
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
//extern "cBalance"

//#include "testFuncHardwareGPU.h"
#include "ParallelMotorAnglet2.h"
#include "InverseKinematicsPreshape.h"
#include "ForwardKinematics.h"
#include "PointToLine.h"
#include "colourSegmentation.h"
#include "colourBalance.h"
#include "morphologicalFilters.h"
#include "communication.h"
#include "ApproachObject.h"

int main(void)
{


	const double linkLengths[] = {25,95,60,35,50};
	double desiredPosition[] = {5,10};
	double desiredAngle[] = {9,10};
	uint16_t motorAngles[3];  
	double fingerNum = 1;
	InverseKinematicsPreshape(linkLengths,desiredPosition,desiredAngle,fingerNum,motorAngles);
	printf("%u,%u,%u \n",motorAngles[0],motorAngles[1],motorAngles[2]);	
	

	double pt[] = {30,30};
	double v1[] = {1,3};
	double v2[] = {1,5};
	bool positionReachable = PointToLine(pt,v1,v2);

	if(positionReachable == 1)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}


	double motorAnglet1 = (float) 3/4;
	double motorAnglet2 = (float) 1.2829;
	const double motorPositionM1[] = {0,0};
	double motorPositionM2[] = {-29,-38};
	double jointPositions [8];
	double opticalSensorPosition [2];
	ForwardKinematics(linkLengths, motorPositionM1,motorAnglet1,motorAnglet2,jointPositions,opticalSensorPosition);

	for(int i = 0 ; i<8 ; i++)
	{
		printf("%f,",jointPositions[i]);
	}
	printf("\n");

	printf("%f,%f\n",opticalSensorPosition[0],opticalSensorPosition[1]);

	double currentMotorM0Steps = 20000;
	double currentMotorM1Steps = 50000;
	double distanceToObject = 10;

	ApproachObject(linkLengths, currentMotorM0Steps, currentMotorM1Steps, distanceToObject, motorAngles);
		
	printf("%u %u %u \n",motorAngles[0],motorAngles[1],motorAngles[2]);	
	
	communicationHandler();

	return 0;
}
