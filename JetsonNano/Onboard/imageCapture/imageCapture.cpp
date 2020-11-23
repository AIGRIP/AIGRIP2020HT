#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>

//Gstreamer multimedia framework
std::string gstreamer_pipeline (int capture_width, int capture_height, int display_width, int display_height, int framerate, int flip_method) {
    return "nvarguscamerasrc ! video/x-raw(memory:NVMM), width=(int)" + std::to_string(capture_width) + ", height=(int)" +
           std::to_string(capture_height) + ", format=(string)NV12, framerate=(fraction)" + std::to_string(framerate) +
           "/1 ! nvvidconv flip-method=" + std::to_string(flip_method) + " ! video/x-raw, width=(int)" + std::to_string(display_width) + ", height=(int)" +
           std::to_string(display_height) + ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
}

// image capturing function
int imageCaptureFunc(unsigned char *outputImg){

    
    

    int capture_width = 740 ;
    int capture_height = 984 ;
    int display_width = 740 ;
    int display_height = 984 ;
    int framerate = 20 ;
    int flip_method = 3 ;
    std::string pipeline = gstreamer_pipeline(capture_width, // call to gstream func
	capture_height,
	display_width,
	display_height,
	framerate,
	flip_method);
    std::cout << "Using pipeline: \n\t" << pipeline << "\n";
 
    cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER); //Opening camera
    if(!cap.isOpened()) {
	std::cout<<"Failed to open camera."<<std::endl;
	return 0;
    }
    cv::namedWindow("CSI Camera", cv::WINDOW_AUTOSIZE); // window to show the camera images
    cv::Mat img;
    std::vector<cv::Mat> channels;
    std::cout << "Hit ESC to exit" << "\n" ;
  
    	if (!cap.read(img)) {                                   //image capture every frame
		std::cout<<"Capture read error"<<std::endl;
		
	
		//std::cout<<imgChan.size()<<std::endl;

	}
	//split(img, channels);

	//cv::imshow("CSI Camera",img);	//displaying the camare images
	
	

cv::Vec3b tempVar;
int count = 0;

for(int k=0; k<3; k++){
	for(int i=0; i<(img.cols); i++){
		for(int j = 0; j<(img.rows); j++){
			tempVar = img.at<cv::Vec3b>(j,i);
			outputImg[count] = tempVar[2-k];   //input to Samuels algorithm 
			count++;
			
			
		}
	}
}
	cap.release();
        cv::destroyAllWindows();
	return 1;
}





