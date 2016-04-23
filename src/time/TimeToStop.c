#include "TimeToStop.h"

void* launchTime(void* stopped_void){

	bool* stopped = (bool*) stopped_void;

	#ifdef DEBUG
		printf("Lancement des %d secondes \n", STOP_TIME);
	#endif

	sleep(STOP_TIME);
	#ifdef DEBUG
		printf("Fin des %d secondes\n", STOP_TIME);
	#endif

	*stopped = true;

	pthread_exit(NULL);
}
