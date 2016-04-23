#include "Serial.h"

void* launchSerialLoop(void* data_void){

	Data* data = (Data*) data_void;

	#ifdef DEBUG
		printf("Lancement de la boucle port-série\n");
	#endif

	while(!data->stopped){
		usleep(200);
	}

	#ifdef DEBUG
		printf("Fermeture de la boucle port-série\n");
	#endif

	pthread_exit(NULL);
}
