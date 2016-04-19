#include "TimeToStop.h"

void* launchTime(void* data_void){

	Data* data = (Data*) data_void;

	#ifdef DEBUG
		printf("Lancement du temps\n");
	#endif

	sleep(STOP_TIME);
	#ifdef DEBUG
		printf("Fin du temps\n");
	#endif

	data->stopped = true;

	pthread_exit(NULL);
}
