#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//extern "cBalance"

//#include "testFuncHardwareGPU.h"
#include "colourSegmentation.h"
#include "colourBalance.h"
#include "morphologicalFilters.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

int main(void)
{
	int width,height,channels;
	//unsigned char segIM[94710];
	
	bool binIm1[728160];
	bool binIm2[728160];

	unsigned char resultImage[728160];
	unsigned char colourBalancedImage[2184480];

	unsigned char *img = stbi_load("CUDATest.jpg",&width,&height,&channels,3);

	if(img == NULL){
		printf("Error loading the image");
		
		//exit(1);
	}
	printf("Width %d, height %d, comp %d.\n",width,height,channels);

	clock_t t;
	t = clock();

	colourBalance( img, colourBalancedImage);

	colourSegmentation( img,(double) round(width/2),(double) round(height/2) ,binIm1);

	morphologicalFilters( binIm1,(double) round(width/2),(double) round(height/2) ,binIm2 );

	t = clock()-t;
	double time_taken = ((double) t)/CLOCKS_PER_SEC;

	printf("It took %f seconds to execute.\n",time_taken);


	for(int i=0;i<(height-5);i=i+5)
	{
		for(int j=0;j<(width-5);j=j+5)
		{
			if( binIm1[i*width + j] == 0)
			{
				printf(" ");
			}else{
				printf("1");
			}
		}
		printf("\n");
	}

	for(int i=0;i < height*width;i++)
	{
		resultImage[i] = binIm1[i]*255;
	}

	stbi_write_jpg("originalImage.jpg",width,height,channels,img,100);
	stbi_write_jpg("colourBalance.jpg",width,height,channels,colourBalancedImage,100);

	stbi_write_png("colourSegmentation.png",width,height,1,resultImage,width);
	stbi_write_png("fillHoles.png",width,height,1,binIm2,width);


	stbi_image_free(img);
}
