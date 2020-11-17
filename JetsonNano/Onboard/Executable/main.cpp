#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//extern "cBalance"

//#include "testFuncHardwareGPU.h"
#include "colourSegmentation.h"
#include "colourBalance.h"
#include "morphologicalFilters.h"
#include "communication.h"


int main(void)
{

	communicationHandler();

	printf("It took %f seconds to execute.\n",time_taken);

	return 0;
}
