
#include "control.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include <mqueue.h>

#include "typedefsGripperNano.h"
#include "imageCapture.h"

#include "colourSegmentation.h"
#include "colourBalance.h"
#include "MorphologicalFilters.h"

#include "StableLine.h"
#include "GetValidGripPoints.h"
#include "GetSignature.h"

#include "ApproachObject.h"

#include <time.h>


// Main function for communication.
void* controlThread(void* arg)
{
    int width = 740, height = 984;
    double offset = 10;
    bool binIm1[728160];
    bool binIm2[728160];
    unsigned char outputImg[2184480];
    unsigned char colourBalancedImage[2184480];
    const double linkLengths[] = {25,95,60,35,50};
    double errorNoImage;

    // Variables to get signature
    const int lengthSignature = 360;
    double degreesToMeasure[lengthSignature];
    double signature[lengthSignature];
    double YCoordToStore[lengthSignature];
    double XCoordToStore[lengthSignature];

    // Variables for stable line.

    // Number of target points for each finger.
    const int nrTargetPointsFinger[] = {1,11,11};

    double targetPointF0Y, targetPointF0X, normalPointF0Y, normalPointF0X;

    double targetPointF1Y[nrTargetPointsFinger[1]];
    double targetPointF1X[nrTargetPointsFinger[1]];
    double normalPointF1Y[nrTargetPointsFinger[1]];
    double normalPointF1X[nrTargetPointsFinger[1]];

    double targetPointF2Y[nrTargetPointsFinger[2]];
    double targetPointF2X[nrTargetPointsFinger[2]];
    double normalPointF2Y[nrTargetPointsFinger[2]];
    double normalPointF2X[nrTargetPointsFinger[2]];

    // Just receiveing the signature for each finger. (Is used for debug purposes)
    double signatureRadiusTargetF1[nrTargetPointsFinger[1]];
    double signatureRadiusTargetF2[nrTargetPointsFinger[2]];

    // Variables for valid grip points.
    double distanceToObject = 300.0;
    double bestTargetPointY, bestTargetPointX, bestNormalPointY, bestNormalPointX;
    unsigned short motorSteps[3];
    messageMotorStruct currentMotorPosition;

    double resDeg = 1*3.1415/180.0;

    // Initate measuring points.
    for(int i=0;i<lengthSignature;i++)
    {
        degreesToMeasure[i] = i*resDeg;
    }

    unsigned char gripperState;


    // Open message queues.
    int messageQueueReturnValue;
    // Connect to message main queue.
    int mainMessageBuffer;
    mqd_t messageQueueMain;
    messageQueueMain = mq_open(messageMainQueueName, O_RDWR);
    // To get the number of messages in the main queue.
    struct mq_attr attributeMainQueue;

    // Connect to message queue for motors.
    messageMotorStruct motorMessage;
    mqd_t messageQueueMotors;
    messageQueueMotors = mq_open(messageQueueMotorName, O_RDWR);
    // To get the number of messages in the motor queue.
    struct mq_attr attributeMotorQueue;

    // Connect to message queue for motors.
    controlData controlDataMessage;
    mqd_t messageQueueControlData;
    messageQueueControlData = mq_open(messageQueueControlDataName, O_RDWR);



    // For timing, might be useful for approach.
    struct timespec messageDeadline;


    while(1)
    {

        /*

        // Recive current distance to obejct. If there is posible to wait for data, add some time to messageDeadline.
        clock_gettime(CLOCK_REALTIME, &messageDeadline);
        messageQueueReturnValue = mq_timedreceive(messageQueueControlData,(char *) &controlDataMessage, sizeof(proximitySensorMessage), 1, messageDeadline);
        if(messageQueueReturnValue > 0)
        {
            distanceToObject = controlDataMessage.proximitySensor[0];

            for(int motorIndex=0; motorIndex<NUMBER_OF_MOTORS;motorIndex++)
            {
                currentMotorPosition.motorAngle[i] = controlDataMessage.motorData.motorAngle[i];
            }


            // Check if it is time to switch state.
            if( distanceToObject < 20 && gripperState == 1 )
            {
                gripperState = 2;

                // Tell communication handle that Nucleo should go to slipNot mode.
                mainMessageBuffer = 1;
                if( mq_send(messageQueueMain, (char*) &mainMessageBuffer, messageMainQueueSize,1) !=0 )
                {
                    printf("Failed to reach main MQ in pre-shape.\n");
                }
            }


            if(1)
            {
                // Tell communication handle that Nucleo should go to slipNot mode.
                mainMessageBuffer = 1;
                if( mq_send(messageQueueMain, (char*) &mainMessageBuffer, messageMainQueueSize,1) !=0 )
                {
                    printf("Failed to reach main MQ in pre-shape.\n");
                }
            }
        }
        */

        // Debug, test state
        gripperState = 1;

        switch( gripperState )
        {
            // Preshape
            case 1:
            {
                imageCaptureFunc(outputImg);
                colourBalance(outputImg, colourBalancedImage);
                colourSegmentation( colourBalancedImage,(double) round(height/2),(double) round(width/2) ,binIm1);
                MorphologicalFilters(binIm1,(double) round(height/2),(double) round(width/2),&errorNoImage, binIm2);

                // Debug
                for(int i=0;i<(width-20);i=i+20)
                {
                    for(int j=0;j<(height-20);j=j+20)
                    {
                        if( binIm1[j*height + i] == 0)
                        {
                            printf(" ");
                        }else{
                            printf("1");
                        }
                    }
                    printf("\n");
                }
		fflush(stdout);

                if(errorNoImage == 1)
                {
                    printf("ERROR, No object detected\n");
                }
                else
                {
                    //signature
                    GetSignature(binIm2, degreesToMeasure, (double) height, (double) width, signature, YCoordToStore, XCoordToStore);

                    // Debug
                    for(int i=0;i<(lengthSignature-10);i=i+10)
                    {
                        printf("%.1lf ",signature[i]);
                    }
                    printf("\n");


                    //stable line
                    StableLine(degreesToMeasure, YCoordToStore, XCoordToStore, signature, targetPointF1Y, targetPointF1X,
                        normalPointF1Y, normalPointF1X, targetPointF2Y, targetPointF2X, normalPointF2Y, normalPointF2X,
                        &targetPointF0Y, &targetPointF0X, &normalPointF0Y, &normalPointF0X, signatureRadiusTargetF1, signatureRadiusTargetF2);

                    // Debug
                    printf("Target point finger 0: %.1lf 	%.1lf \n",targetPointF0X,targetPointF0Y);

                    printf("Suggested gripping points finger 1.\n");
                    for(int i=0;i<nrTargetPointsFinger[1];i++)
                    {
                        printf("%.1lf	%.1lf   %.1lf   %.1lf \n",targetPointF1X[i],targetPointF1Y[i],normalPointF1Y[i], normalPointF1X[i]);
                    }

                    printf("Suggested gripping points finger 2.\n");
                    for(int i=0;i<nrTargetPointsFinger[2];i++)
                    {
                        printf("%.1lf   %.1lf   %.1lf   %.1lf \n",targetPointF2X[i],targetPointF2Y[i],normalPointF2Y[i], normalPointF2X[i]);
                    }


                    //getvalid points

                    // Get valid point for finger 0, the thumb.
                    GetValidGripPoints(&targetPointF0Y, &nrTargetPointsFinger[0],
                        &targetPointF0X, &nrTargetPointsFinger[0],
                        &normalPointF0Y, &nrTargetPointsFinger[0],
                        &normalPointF0X, &nrTargetPointsFinger[0],
                        distanceToObject, 0, offset, motorSteps,
                        &bestTargetPointY, &bestTargetPointX, &bestNormalPointY, &bestNormalPointX);

                    motorMessage.motorAngle[0] = motorSteps[1];
                    motorMessage.motorAngle[1] = motorSteps[2];

                    printf("For finger 0 the motor values are:\n %hu    %hu    %hu\n",motorSteps[0],motorSteps[1],motorSteps[2]);
                    printf("The target points are: %.1lf    %.1lf\n",bestTargetPointY,bestTargetPointX);

                    // Get valid point for finger 1, the pointing finger.
                    GetValidGripPoints(targetPointF1Y, &nrTargetPointsFinger[1],
                        targetPointF1X, &nrTargetPointsFinger[1],
                        normalPointF1Y, &nrTargetPointsFinger[1],
                        normalPointF1X, &nrTargetPointsFinger[1],
                        distanceToObject, 1, offset, motorSteps,
                        &bestTargetPointY, &bestTargetPointX, &bestNormalPointY, &bestNormalPointX);

                    motorMessage.motorAngle[2] = motorSteps[0];
                    motorMessage.motorAngle[3] = motorSteps[1];
                    motorMessage.motorAngle[4] = motorSteps[2];

                    printf("For finger 1 the motor values are:\n %hu    %hu    %hu\n",motorSteps[0],motorSteps[1],motorSteps[2]);
                    printf("The target points are: %lf    %lf\n",bestTargetPointY,bestTargetPointX);

                    // Get valid point for finger 2, the long finger.
                    GetValidGripPoints(targetPointF2Y, &nrTargetPointsFinger[2],
                        targetPointF2X, &nrTargetPointsFinger[2],
                        normalPointF2Y, &nrTargetPointsFinger[2],
                        normalPointF2X, &nrTargetPointsFinger[2],
                        distanceToObject, 2, offset, motorSteps,
                        &bestTargetPointY, &bestTargetPointX, &bestNormalPointY, &bestNormalPointX);

                    motorMessage.motorAngle[5] = motorSteps[0];
                    motorMessage.motorAngle[6] = motorSteps[1];
                    motorMessage.motorAngle[7] = motorSteps[2];

                    printf("For finger 2 the motor values are:\n %hu    %hu    %hu\n",motorSteps[0],motorSteps[1],motorSteps[2]);
                    printf("The target points are: %lf    %lf\n",bestTargetPointY,bestTargetPointX);

                    // Send motor values to communtication.
                    mq_getattr(messageQueueMotors, &attributeMotorQueue);
                            mainMessageBuffer = SEND_MOTOR_COMMAND;
                    mq_getattr(messageQueueMain, &attributeMainQueue);

                    if( attributeMotorQueue.mq_curmsgs < attributeMotorQueue.mq_maxmsg &&  attributeMainQueue.mq_curmsgs < attributeMainQueue.mq_maxmsg )
                    {
                        // Send motor values.
                        if( mq_send(messageQueueMotors, (char*) &motorMessage, sizeof(messageMotorStruct),1) !=0 )
                        {
                            printf("Failed to send motor values in pre-shape to MQ.\n");
                        }
                        // Inform that there are motor values available.
                        if( mq_send(messageQueueMain, (char*) &mainMessageBuffer, messageMainQueueSize,1) !=0 )
                        {
                            printf("Failed to reach main MQ in pre-shape.\n");
                        }

                    }else{
                        printf("Motor Queue is full, number of messages is: %ld. From control pre-shape.\n",attributeMotorQueue.mq_curmsgs );
                        printf("Main Queue is full, number of messages is: %ld. From control pre-shape.\n",attributeMainQueue.mq_curmsgs );

		            }

                }
            }
            break;


            // Approach
            case 2:
            {
		/*
                //Recive current motor angle and distance
                //Approach
                //get new motor angles for finger 0
                ApproachObject(linkLengths, 0, currentMotorPosition.motorAngle[0], distanceToObject, motorSteps);
                motorMessage.motorAngle[0] = motorSteps[1];
                motorMessage.motorAngle[1] = motorSteps[2];

                //get new motor angles for finger 1
                ApproachObject(linkLengths,currentMotorPosition.motorAngle[2], currentMotorPosition.motorAngle[3], distanceToObject, motorSteps);
                motorMessage.motorAngle[2] = motorSteps[0];
                motorMessage.motorAngle[3] = motorSteps[1];
                motorMessage.motorAngle[4] = motorSteps[2];

                //get new motor angles for finger 2
                ApproachObject(linkLengths,currentMotorPosition.motorAngle[5], currentMotorPosition.motorAngle[6], distanceToObject, motorSteps);
                motorMessage.motorAngle[5] = motorSteps[0];
                motorMessage.motorAngle[6] = motorSteps[1];
                motorMessage.motorAngle[7] = motorSteps[2];

                    // Send motor values to communtication.
		    mq_getattr(messageQueueMotors, &attributeMotorQueue);
                    mainMessageBuffer = SEND_MOTOR_COMMAND;
		    mq_getattr(messageQueueMain, &attributeMainQueue);

		    if( attributeMotorQueue.mq_curmsgs < attributeMotorQueue.mq_maxmsg &&  attributeMainQueue.mq_curmsgs < attributeMainQueue.mq_maxmsg )
		    {
			// Send motor values.
                    	if( mq_send(messageQueueMotors, (char*) &motorMessage, sizeof(messageMotorStruct),1) !=0 )
                    	{
                       	    printf("Failed to send motor values in pre-shape to MQ.\n");
                    	}
			// Inform that there are motor values available.
                    	if( mq_send(messageQueueMain, (char*) &mainMessageBuffer, messageMainQueueSize,1) !=0 )
                    	{
                            printf("Failed to reach main MQ in pre-shape.\n");
                    	}

		    }else{
			printf("Motor Queue is full, number of messages is: %ld. From control pre-shape.\n",attributeMotorQueue.mq_curmsgs);
			printf("Main Queue is full, number of messages is: %ld. From control pre-shape.\n",attributeMainQueue.mq_curmsgs);

		    }
                }
            */
            }
            break;

            // Idle
            default:
            {
                //Do nothing
            }
            break;
       }



	    usleep(1000000);

    }

}

