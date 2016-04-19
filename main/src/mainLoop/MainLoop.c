#include "MainLoop.h"

void* launchMainLoop(void* data_void){

	Data* data = (Data*) data_void;

	#ifdef DEBUG
		printf("Lancement de la boucle principale\n");
	#endif

	while(!data->stopped){
		usleep(200);
	}

	#ifdef DEBUG
		printf("Fermeture de la boucle principale\n");
	#endif

	pthread_exit(NULL);
}
