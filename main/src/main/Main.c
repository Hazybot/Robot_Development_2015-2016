#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "../mainLoop/MainLoop.h"
#include "../time/TimeToStop.h"
#include "../serial/Serial.h"

int main(int argc, char** argv){

	Data* data = initialiseData();

	pthread_t loopThread, timeThread, serialThread;

	pthread_create(&timeThread, NULL, launchTime, data);
	pthread_create(&loopThread, NULL, launchMainLoop, data);
	pthread_create(&serialThread, NULL, launchSerialLoop, data);

	pthread_join(loopThread, NULL);
	pthread_join(timeThread, NULL);
	pthread_join(serialThread, NULL);

	freeData(data);

	#ifdef DEBUG
		printf("Fin du programme\n");
	#endif

	return 0;
}
