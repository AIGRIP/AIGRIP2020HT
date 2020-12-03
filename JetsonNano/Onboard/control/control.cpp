
#include "control.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "colourSegmentation.h"
#include "colourBalance.h"
#include "morphologicalFilters.h"
#include "imageCapture.h"
#include "ParallelMotorAnglet2.h"
#include "InverseKinematicsPreshape.h"
#include "ApproachObject.h"

// Main function for communication.
void* controlThread(void* arg)
{
    int width = 740, height = 984;
    bool binIm1[728160];
    bool binIm2[728160];
    unsigned char outputImg[2184480];
    unsigned char colourBalancedImage[2184480]; 
    const double linkLengths[] = {25,95,60,35,50};
 
    while(1)
    {
        // Receive command from message main queue.
        mq_receive(messageQueueMain, (char *) &mainMessageBuffer, messageMainQueueSize,NULL);

        printf("Control thread received a state.\n");
        fflush(stdout);
        switch( mainMessageBuffer )
        {
            // Preshape
            case 1:
            {
                imageCaptureFunc(outputImg);
                colourBalance(outputImg, colourBalancedImage);
                colourSegmentation( colourBalancedImage,(double) round(height/2),(double) round(width/2) ,binIm1);
                morphologicalFilters( binIm1,(double) round(height/2),(double) round(width/2) ,binIm2 ); 

                MorphologicalFilters(const bool colourSegmentationMask[728160],double centerOfObjectX, double centerOfObjectY, bool segmentationMask[728160]);
                //signature
                //stable line
                //Recive current distance to obejct
                //getvalid points
                //Send motor values to communtication
            }
            break;


            // Approach
            case 2:
            {
                //Recive current motor angle and distance
                //Approach
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





