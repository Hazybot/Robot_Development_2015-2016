#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "../mainLoop/MainLoop.h"
#include "../time/TimeToStop.h"

int main(int argc, char** argv){

	Data data;
	data.stopped = false;

	pthread_t loopThread, timeThread;

	pthread_create(&timeThread, NULL, launchTime, &data);
	pthread_create(&loopThread, NULL, launchMainLoop, &data);

	pthread_join(loopThread, NULL);
	pthread_join(timeThread, NULL);

	#ifdef DEBUG
		printf("Fin du programme\n");
	#endif

	return 0;
}
