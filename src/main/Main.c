#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "../mainLoop/MainLoop.h"
#include "../time/TimeToStop.h"
#include "../serial/SerialTraitment.h"

int main(int argc, char** argv){

	Data* data = initialiseData();
	int test = openArduino(data->arduino, NB_ARDUINO) != 0;
	if(test != 0){
		return test;
	}

	pthread_t loopThread, timeThread, serialThread;

	pthread_create(&timeThread, NULL, launchTime, &data->stopped);
	pthread_create(&loopThread, NULL, launchMainLoop, data);
	pthread_create(&serialThread, NULL, launchSerialLoop, data);

	pthread_join(loopThread, NULL);
	pthread_join(timeThread, NULL);
	pthread_join(serialThread, NULL);

	closeArduino(data->arduino, NB_ARDUINO);
	freeData(data);

	#ifdef DEBUG
		printf("Fin du programme\n");
	#endif

	return 0;
}
