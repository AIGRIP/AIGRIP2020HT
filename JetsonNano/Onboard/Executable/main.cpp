

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "colourSegmentation.h"
#include "colourBalance.h"
#include "morphologicalFilters.h"
#include "imageCapture.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>
#include <stdint.h>
#include "ParallelMotorAnglet2.h"
#include "InverseKinematicsPreshape.h"
#include "ForwardKinematics.h"
#include "PointToLine.h"
#include "colourSegmentation.h"
#include "colourBalance.h"
#include "morphologicalFilters.h"
#include "communication.h"
#include "ApproachObject.h"
#include "GetPixelLength.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
int main()
{
    bool binIm1[728160];
    bool binIm2[728160];
    int width = 740, height = 984;
    unsigned char outputImg[2184480];

    unsigned char resultImage[728160];
    unsigned char colourBalancedImage[2184480]; 
    imageCaptureFunc(outputImg);

      	colourBalance(outputImg, colourBalancedImage);

 	colourSegmentation( colourBalancedImage,(double) round(height/2),(double) round(width/2) ,binIm1);

	morphologicalFilters( binIm1,(double) round(height/2),(double) round(width/2) ,binIm2 );
	
	cv::Mat canvas = cv::Mat::zeros(height,width,CV_8UC1);	
	cv::Mat canvas2 = cv::Mat::zeros(height,width,CV_8UC1);

	for(int i=0;i<(height);i=i+1)
	{
		for(int j=0;j<(width);j=j+1)
		{
			if( binIm1[j*height + i] == 1)
			{
				canvas.at<uchar>(cv::Point2i(j,i)) = 255;
			}
			if (binIm2[j*height + i] == 1)
			{
				canvas2.at<uchar>(cv::Point2i(j,i)) = 255;
			}
		}
	}
	cv::namedWindow("Binary image", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Binary image filter", cv::WINDOW_AUTOSIZE);
	cv::imshow("Binary image",canvas);
	cv::imshow("Binary image filter",canvas2);
	cv::waitKey(0);
	cv::imwrite("../../../binaryImage.jpg",canvas2);
	double pixelLength;
	double objectWidth;
	GetPixelLength(binIm2,(double) round(height/2),600,&pixelLength,&objectWidth);

	printf("%f\n%f\n",pixelLength,objectWidth);
}



