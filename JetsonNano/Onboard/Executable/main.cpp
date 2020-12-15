

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "communication.h"
#include "control.h"

#include "GetValidGripPoints.h"

int main()
{
	unsigned short motorSteps[3];

	double bestTargetPointX;
	double bestTargetPointY;
	double bestNormalPointY;
	double bestNormalPointX;

	double tpY[] = {38,51,65,81,146,144,99,144,119,143,141};
	double tpX[] = {132,132,133,135,65,80,136,97,137,116,136};
	double tNY[] = {182,181.6,182.7,184.8,70.5,80,185.8,97,186.9,124.9,185.9};
	double tNX[] = {38,44.8,59.5,76,195.7,194,94.8,194,115.2,192.2,144.8};

	const int ts = 11;

	GetValidGripPoints( tpY,&ts,tpX,&ts,tNY,&ts,tNX,&ts,(double) 300.0, 1,(int)10, motorSteps, &bestTargetPointY, &bestTargetPointX, &bestNormalPointY, &bestNormalPointX);

	for(int i=0;i<3;i++)
		printf("%hu    ",motorSteps[i]);

	// Communication handle for Nano.
	communicationHandler();

    return 0;
}



