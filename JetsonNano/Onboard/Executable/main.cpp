#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//extern "cBalance"

//#include "testFuncHardwareGPU.h"
#include "colourSegmentation.h"
#include "colourBalance.h"
#include "morphologicalFilters.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>


std::string gstreamer_pipeline (int capture_width, int capture_height, int display_width, int display_height, int framerate, int flip_method) {
    return "nvarguscamerasrc ! video/x-raw(memory:NVMM), width=(int)" + std::to_string(capture_width) + ", height=(int)" +
           std::to_string(capture_height) + ", format=(string)NV12, framerate=(fraction)" + std::to_string(framerate) +
           "/1 ! nvvidconv flip-method=" + std::to_string(flip_method) + " ! video/x-raw, width=(int)" + std::to_string(display_width) + ", height=(int)" +
           std::to_string(display_height) + ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
}

int main()
{

    int width = 740, height = 984;
    bool binIm1[728160];
    bool binIm2[728160];
   

    unsigned char resultImage[728160];
    unsigned char colourBalancedImage[2184480];
    unsigned char outputImg[2184480];

    int capture_width = 1280 ;
    int capture_height = 720 ;
    int display_width = 740 ;
    int display_height = 984 ;
    int framerate = 60 ;
    int flip_method = 3 ;
    std::string pipeline = gstreamer_pipeline(capture_width,
	capture_height,
	display_width,
	display_height,
	framerate,
	flip_method);
    std::cout << "Using pipeline: \n\t" << pipeline << "\n";
 
    cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER);
    if(!cap.isOpened()) {
	std::cout<<"Failed to open camera."<<std::endl;
	return (-1);
    }
    cv::namedWindow("CSI Camera", cv::WINDOW_AUTOSIZE);
    cv::Mat img;
    //cv::Mat3d imgChan;
    std::vector<cv::Mat> channels;
    std::cout << "Hit ESC to exit" << "\n" ;
    while(true)
    {
    	if (!cap.read(img)) {
		std::cout<<"Capture read error"<<std::endl;
		break;
	
		//std::cout<<imgChan.size()<<std::endl;

	}
	//cv::imshow("CSI Camera",img);
	split(img, channels);
	//std::cout<<"blue:"<<channels[0].size<<std::endl;
	//std::cout<<"Green:"<<channels[1].size<<std::endl;
	//std::cout<<"Red:"<<channels[2].size<<std::endl;
	cv::imshow("CSI Camera",img);
	//std::cout<<img.size<<std::endl;
	int keycode = cv::waitKey(30) & 0xff ; 
        if (keycode == 27) break ;
    }

//cv::Vec3b tempVar;
//int count = 0;

//for(int k=0; k<3; k++){
//	for(int i=0; i<(img.rows); i++){
//		for(int j = 0; j<(img.cols); j++){
//			tempVar = img.at<cv::Vec3b>(i,j);
//			outputImg[count] = tempVar[k];
//			count++;
			
			
//		}
//	}
//}
  //    std::cout<<"outputimg"<<sizeof outputImg<<std::endl;
      unsigned char* dataOut = img.data;
      colourBalance(dataOut, colourBalancedImage);

      colourSegmentation( colourBalancedImage,(double) round(height/2),(double) round(width/2) ,binIm1);

      morphologicalFilters( binIm1,(double) round(height/2),(double) round(width/2) ,binIm2 );

	for(int i=0;i<(width-5);i=i+5)
	{
		for(int j=0;j<(height-5);j=j+5)
		{
			if( binIm2[i*height + j] == 0)
			{
				printf(" ");
			}else{
				printf("1");
			}
		}
		printf("\n");
	}

    cap.release();
    cv::destroyAllWindows() ;
    return 0;
}




