#include "TimeToStop.h"

void* launchTime(void* data_void){

	Data* data = (Data*) data_void;

	#ifdef DEBUG
		printf("Lancement des %d secondes \n", STOP_TIME);
	#endif

	sleep(STOP_TIME);
	#ifdef DEBUG
		printf("Fin des %d secondes\n", STOP_TIME);
	#endif

	data->stopped = true;

	pthread_exit(NULL);
}
