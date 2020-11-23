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



int main()
{
    bool binIm1[728160];
    bool binIm2[728160];
    int width = 740, height = 984;
    unsigned char outputImg[2184480];

    unsigned char resultImage[728160];
    unsigned char colourBalancedImage[2184480]; 
    imageCaptureFunc(outputImg);
  //    std::cout<<"outputimg"<<sizeof outputImg<<std::endl;
  //    unsigned char* dataOut = img.data;
      colourBalance(outputImg, colourBalancedImage);

      colourSegmentation( colourBalancedImage,(double) round(height/2),(double) round(width/2) ,binIm1);

      morphologicalFilters( binIm1,(double) round(height/2),(double) round(width/2) ,binIm2 );

	for(int i=0;i<(width-5);i=i+5)
	{
		for(int j=0;j<(height-5);j=j+5)
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

    
    return 0;
}




