
#include "control.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include "typedefsGripperNano.h"

#include "imageCapture.h"

#include "colourSegmentation.h"
#include "colourBalance.h"
#include "MorphologicalFilters.h"

#include "StableLine.h"
#include "GetValidGripPoints.h"
#include "GetSignature.h"

// Main function for communication.
void* controlThread(void* arg)
{
    int width = 740, height = 984, offset = 10;
    bool binIm1[728160];
    bool binIm2[728160];
    unsigned char outputImg[2184480];
    unsigned char colourBalancedImage[2184480];
    const double linkLengths[] = {25,95,60,35,50};


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
    double distanceToObject = 300;
    double bestTargetPointY, bestTargetPointX, bestNormalPointY, bestNormalPointX;
    unsigned short motorSteps[3];

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

    // Connect to message queue for motors.
    messageI2CToNucleoMotor motorMessage;
    mqd_t messageQueueMotors;
    messageQueueMotors = mq_open(messageMainQueueName, O_RDWR);

    // Connect to message queue for motors.
    proximitySensorMessage distanceMessage;
    mqd_t messageQueueDistance;
    messageQueueDistance = mq_open(messageMainQueueName, O_RDWR);

    // For timing, might be useful for approach.
    struct timespec messageDeadline;
    

    while(1)
    {
        // Receive command from message main queue.
        gripperState = 1;


        //Recive current distance to obejct. If there is posible to wait for data, add some time to messageDeadline.
        clock_gettime(CLOCK_REALTIME, &messageDeadline);
        messageQueueReturnValue = mq_timedreceive(messageQueueDistance,(char *) &distanceMessage, sizeof(proximitySensorMessage), 1, messageDeadline);
        if(messageQueueReturnValue > 0){
            distanceToObject = distanceMessage.proximitySensor[0];
        }

        switch( gripperState )
        {
            // Preshape
            case 1:
            {
                imageCaptureFunc(outputImg);
                colourBalance(outputImg, colourBalancedImage);
                colourSegmentation( colourBalancedImage,(double) round(height/2),(double) round(width/2) ,binIm1);
                MorphologicalFilters(binIm1,(double) round(height/2),(double) round(width/2), binIm2);

                // Debug
                for(int i=0;i<(width-5);i=i+5)
                {
                    for(int j=0;j<(height-5);j=j+5)
                    {
                        if( binIm2[j*height + i] == 0)
                        {
                            printf(" ");
                        }else{
                            printf("1");
                        }
                    }
                    printf("\n");
                }


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
                    printf("%.1lf	%.1lf \n",targetPointF1X[i],targetPointF1Y[i]);
                }

                printf("Suggested gripping points finger 2.\n");
                for(int i=0;i<nrTargetPointsFinger[2];i++)
                {
                    printf("%.1lf   %.1lf \n",targetPointF2X[i],targetPointF2Y[i]);
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
                printf("The target points are: %lf    %lf\n",bestTargetPointY,bestTargetPointX);

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
                if( mq_send(messageQueueMotors, (char*) &motorMessage, sizeof(messageI2CToNucleoMotor),1) !=0 )
                {
                    printf("Failed to send motor values in pre-shape to MQ.\n");
                }

                // Tell communication handle that new motor values are available.
                mainMessageBuffer = 1;
                if( mq_send(messageQueueMain, (char*) &mainMessageBuffer, messageMainQueueSize,1) !=0 )
                {
                    printf("Failed to reach main MQ in pre-shape.\n");
                }
            }
            break;


            // Approach
            case 2:
            {
                //Recive current motor angle and distance
                //Approach
                motorMessage.motorAngle[0] = motorSteps[1];
                motorMessage.motorAngle[1] = motorSteps[2];

                motorMessage.motorAngle[2] = motorSteps[0];
                motorMessage.motorAngle[3] = motorSteps[1];
                motorMessage.motorAngle[4] = motorSteps[2];

                motorMessage.motorAngle[5] = motorSteps[0];
                motorMessage.motorAngle[6] = motorSteps[1];
                motorMessage.motorAngle[7] = motorSteps[2];
            }
            break;

            // Idle
            default:
            {
                //Do nothing
            }
            break;
       }



	    usleep(10000);

    }

}





