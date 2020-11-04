#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//extern "cBalance"

#include "testFuncHardwareGPU.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

int main(void)
{
	int width,height,channels;
	unsigned char segIM[94710];

	//unsigned char colourBalancedImage[14745600];

	unsigned char *img = stbi_load("table205x154.jpg",&width,&height,&channels,0);

	if(img == NULL){
		printf("Error loading the image");
		exit(1);
	}
	printf("Width %d, height %d, channels %d.\n",width,height,channels);


	clock_t t;
	t = clock();

	//colourBalance( img, colourBalancedImage);

	testFuncHardwareGPU( img, segIM);

	t = clock()-t;
	double time_taken = ((double) t)/CLOCKS_PER_SEC;

	printf("It took %f seconds to execute.\n",time_taken);

	stbi_write_jpg("testOutPut.jpg",width,height,channels,segIM,100);


	stbi_image_free(img);
}
