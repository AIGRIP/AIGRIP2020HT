
#include "control.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include <mqueue.h>

#include "typedefsGripperNano.h"
//#include "imageCapture.h"

#include "colourSegmentation.h"
#include "colourBalance.h"
#include "MorphologicalFilters.h"

#include "StableLine.h"
#include "GetValidGripPoints.h"
#include "GetSignature.h"

#include "ApproachObject.h"

#include <time.h>
#include <sys/time.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>

//Gstreamer multimedia framework
std::string gstreamer_pipeline (int capture_width, int capture_height, int display_width, int display_height, int framerate, int flip_method) {
    return "nvarguscamerasrc ! video/x-raw(memory:NVMM), width=(int)" + std::to_string(capture_width) + ", height=(int)" +
           std::to_string(capture_height) + ", format=(string)NV12, framerate=(fraction)" + std::to_string(framerate) +
           "/1 ! nvvidconv flip-method=" + std::to_string(flip_method) + " ! video/x-raw, width=(int)" + std::to_string(display_width) + ", height=(int)" +
           std::to_string(display_height) + ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
}

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
    messageMotorStruct motorMessage = {777};
    mqd_t messageQueueMotors;
    messageQueueMotors = mq_open(messageQueueMotorName, O_RDWR);
    // To get the number of messages in the motor queue.
    struct mq_attr attributeMotorQueue;

    // Connect to message queue for motors.
    controlData controlDataMessage;
    mqd_t messageQueueControlData;
    messageQueueControlData = mq_open(messageQueueControlDataName, O_RDWR);
    struct mq_attr attributeControlData;

    // Takew time on the algorithms.
    struct timeval startTimeStruct;
    struct timeval stopTimeStruct;
    unsigned long long startTime;
    unsigned long long stopTime;


    // For timing, might be useful for approach.
    struct timespec messageDeadline;


    int capture_width = 740 ;
    int capture_height = 984 ;
    int display_width = 740 ;
    int display_height = 984 ;
    int framerate = 20 ;
    int flip_method = 1 ;

    std::string pipeline = gstreamer_pipeline(capture_width, // call to gstream func
	capture_height,
	display_width,
	display_height,
	framerate,
	flip_method);

    cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER); //Opening camera


    if(!cap.isOpened()) 
    {
	    std::cout<<"Failed to open camera."<<std::endl;
    }

    cv::Mat img;
    std::vector<cv::Mat> channels;
    cv::Vec3b tempVar;
    int count;


    while(1)
    {
	// Check if there are new messages.
        mq_getattr(messageQueueControlData, &attributeControlData);

        // Recive current distance to obejct. If there is posible to wait for data, add some time to messageDeadline.
        if(attributeControlData.mq_curmsgs > 0)
        {
            distanceToObject = controlDataMessage.distanceData.proximitySensor[0];

            for(int motorIndex=0; motorIndex<NUMBER_OF_MOTORS;motorIndex++)
            {
		printf("Motor %d is: %hu",motorIndex,controlDataMessage.motorData.motorAngle[motorIndex]);
                currentMotorPosition.motorAngle[motorIndex] = controlDataMessage.motorData.motorAngle[motorIndex];
            }
	    printf("\n");
        }


        // Debug, test state
        gripperState = 1;

        switch( gripperState )
        {
            // Preshape
            case 1:
            {

                if (cap.grab() == 0) //image capture every frame
                {    
                    std::cout<<"Capture read error"<<std::endl;                               
	            }
                else
                {
                    cap.retrieve(img);
                    count = 0;

                    for(int k=0; k<3; k++){
                        for(int i=0; i<(img.cols); i++){
                            for(int j = 0; j<(img.rows); j++){
                                tempVar = img.at<cv::Vec3b>(j,i);
                                outputImg[count] = tempVar[2-k];   //Create output image
                                count++;
                            }
                        }
                    }

                    // Take time of colourBalance.
                    gettimeofday(&startTimeStruct, NULL);
                    colourBalance(outputImg, colourBalancedImage);
                    gettimeofday(&stopTimeStruct, NULL);
                    startTime = startTimeStruct.tv_sec*1000000 + startTimeStruct.tv_usec;
                    stopTime = stopTimeStruct.tv_sec*1000000 + stopTimeStruct.tv_usec;

                    printf("ColourBalance took: %llu nanoseconds.\n",(stopTime-startTime));

                    // Take time of colourSegmentation.
                    gettimeofday(&startTimeStruct, NULL);
                    colourSegmentation( colourBalancedImage,(double) round(height/2),(double) round(width/2) ,binIm1);
                    gettimeofday(&stopTimeStruct, NULL);
                    startTime = startTimeStruct.tv_sec*1000000 + startTimeStruct.tv_usec;
                    stopTime = stopTimeStruct.tv_sec*1000000 + stopTimeStruct.tv_usec;

                    printf("ColourSegmentation took: %llu nanoseconds.\n",(stopTime-startTime));

                    // Take time of MorphologicalFilters.
                    gettimeofday(&startTimeStruct, NULL);
                    MorphologicalFilters(binIm1,(double) round(height/2),(double) round(width/2),&errorNoImage, binIm2);
                    gettimeofday(&stopTimeStruct, NULL);
                    startTime = startTimeStruct.tv_sec*1000000 + startTimeStruct.tv_usec;
                    stopTime = stopTimeStruct.tv_sec*1000000 + stopTimeStruct.tv_usec;

                    printf("Morphological took: %llu nanoseconds.\n",(stopTime-startTime));

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

                        // Take time of Signature.
                        gettimeofday(&startTimeStruct, NULL);
                        GetSignature(binIm2, degreesToMeasure, (double) height, (double) width, signature, YCoordToStore, XCoordToStore);
                        gettimeofday(&stopTimeStruct, NULL);
                        startTime = startTimeStruct.tv_sec*1000000 + startTimeStruct.tv_usec;
                        stopTime = stopTimeStruct.tv_sec*1000000 + stopTimeStruct.tv_usec;

                        printf("Signature took: %llu nanoseconds.\n",(stopTime-startTime));



                        // Debug
                        for(int i=0;i<(lengthSignature-10);i=i+10)
                        {
                            printf("%.1lf ",signature[i]);
                        }
                        printf("\n");


                        //stable line
                        // Take time of Signature.
                        gettimeofday(&startTimeStruct, NULL);
                        StableLine(degreesToMeasure, YCoordToStore, XCoordToStore, signature, targetPointF1Y, targetPointF1X,
                            normalPointF1Y, normalPointF1X, targetPointF2Y, targetPointF2X, normalPointF2Y, normalPointF2X,
                            &targetPointF0Y, &targetPointF0X, &normalPointF0Y, &normalPointF0X, signatureRadiusTargetF1, signatureRadiusTargetF2);
                        gettimeofday(&stopTimeStruct, NULL);
                        startTime = startTimeStruct.tv_sec*1000000 + startTimeStruct.tv_usec;
                        stopTime = stopTimeStruct.tv_sec*1000000 + stopTimeStruct.tv_usec;

                        printf("StableLine took: %llu nanoseconds.\n",(stopTime-startTime));


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


                        // Take time of Signature.
                        gettimeofday(&startTimeStruct, NULL);

                        // Get valid point for finger 0, the thumb.
                        GetValidGripPoints(&targetPointF0Y,(int*) &nrTargetPointsFinger[0],
                            &targetPointF0X,(int*) &nrTargetPointsFinger[0],
                            &normalPointF0Y,(int*) &nrTargetPointsFinger[0],
                            &normalPointF0X,(int*) &nrTargetPointsFinger[0],
                            distanceToObject, 0, offset, motorSteps,
                            &bestTargetPointY, &bestTargetPointX, &bestNormalPointY, &bestNormalPointX);

                        motorMessage.motorAngle[0] = motorSteps[1];
                        motorMessage.motorAngle[1] = motorSteps[2];

                        printf("For finger 0 the motor values are:\n %hu    %hu    %hu\n",motorSteps[0],motorSteps[1],motorSteps[2]);
                        printf("The target points are: %.1lf    %.1lf\n",bestTargetPointY,bestTargetPointX);

                        // Get valid point for finger 1, the pointing finger.
                        GetValidGripPoints(targetPointF1Y,(int*) &nrTargetPointsFinger[1],
                            targetPointF1X,(int*) &nrTargetPointsFinger[1],
                            normalPointF1Y,(int*) &nrTargetPointsFinger[1],
                            normalPointF1X,(int*) &nrTargetPointsFinger[1],
                            distanceToObject, 1, offset, motorSteps,
                            &bestTargetPointY, &bestTargetPointX, &bestNormalPointY, &bestNormalPointX);

                        motorMessage.motorAngle[2] = motorSteps[0];
                        motorMessage.motorAngle[3] = motorSteps[1];
                        motorMessage.motorAngle[4] = motorSteps[2];

                        printf("For finger 1 the motor values are:\n %hu    %hu    %hu\n",motorSteps[0],motorSteps[1],motorSteps[2]);
                        printf("The target points are: %.1lf    %.1lf\n",bestTargetPointY,bestTargetPointX);

                        // Get valid point for finger 2, the long finger.
                        GetValidGripPoints(targetPointF2Y,(int*) &nrTargetPointsFinger[2],
                            targetPointF2X,(int*) &nrTargetPointsFinger[2],
                            normalPointF2Y,(int*) &nrTargetPointsFinger[2],
                            normalPointF2X,(int*) &nrTargetPointsFinger[2],
                            distanceToObject, 2, offset, motorSteps,
                            &bestTargetPointY, &bestTargetPointX, &bestNormalPointY, &bestNormalPointX);

                        motorMessage.motorAngle[5] = motorSteps[0];
                        motorMessage.motorAngle[6] = motorSteps[1];
                        motorMessage.motorAngle[7] = motorSteps[2];

                        printf("For finger 2 the motor values are:\n %hu    %hu    %hu\n",motorSteps[0],motorSteps[1],motorSteps[2]);
                        printf("The target points are: %.1lf    %.1lf\n",bestTargetPointY,bestTargetPointX);


                        gettimeofday(&stopTimeStruct, NULL);
                        startTime = startTimeStruct.tv_sec*1000000 + startTimeStruct.tv_usec;
                        stopTime = stopTimeStruct.tv_sec*1000000 + stopTimeStruct.tv_usec;

                        printf("GetValidGripPoints took: %llu nanoseconds.\n",(stopTime-startTime));


                        // Send motor values to communtication.
                        mq_getattr(messageQueueMotors, &attributeMotorQueue);
                        mq_getattr(messageQueueMain, &attributeMainQueue);

                        if( (attributeMotorQueue.mq_curmsgs < PRE_SHAPE_BUFFER) && (attributeMainQueue.mq_curmsgs < attributeMainQueue.mq_maxmsg) )
                        {
                            mainMessageBuffer = SEND_MOTOR_COMMAND;
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
                            

                        }
                        else
                        {
                            printf("Motor Queue is full, number of messages is: %ld. From control pre-shape.\n",attributeMotorQueue.mq_curmsgs );
                            printf("Main Queue is full, number of messages is: %ld. From control pre-shape.\n",attributeMainQueue.mq_curmsgs );
                        }
                    }
                    memset(&motorMessage, 0, sizeof(messageMotorStruct));
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



	    usleep(10000);

    }
    cap.release();
}

