#include "Serial.h"

char* readInfo(int arduino, int size){
	char* result = (char*) calloc(size, sizeof(char));
	strcat(result, "10:10:10:10:10");

	#ifdef DEBUG
		printf("Reception de %s de l'arduino %d\n", result, arduino);
	#endif
	return result;
}

void writeInfo(int arduino, char* msg){
	#ifdef DEBUG
		printf("Envoie de %s à l'arduino %d\n", msg, arduino);
	#endif
}

void buildDistanceSensor(char* info, float* distances, int size){

	char* new = strtok(info, DELIM_CHAR);
	int i;
	for(i = 0; (i < size) && (new != NULL); i++){
		distances[i] = atoi(new);
		new = strtok(NULL, DELIM_CHAR);
	}
}

char* createMotorString(float* speeds, int size){
	int i;
	char* result = (char*) calloc(size*6-1, sizeof(char));
	char* oneSpeed = (char*) calloc(6, sizeof(char));
	char* delim;

	for(i = 0; i < size; i++){
		if(i == size-1){
			delim = "";
		}
		else{
			delim = DELIM_CHAR;
		}
		sprintf(oneSpeed, "%06.2f%s", speeds[i], delim);
		strcat(result, oneSpeed);
	}
	return result;
}

void* launchSerialLoop(void* data_void){

	Data* data = (Data*) data_void;

	#ifdef DEBUG
		printf("Lancement de la boucle port-série\n");
	#endif

	while(!data->stopped){
		buildDistanceSensor(readInfo(0, NB_DISTANCE_SENSOR*6-1), data->distances, NB_DISTANCE_SENSOR);
		writeInfo(1, createMotorString(data->speeds, NB_MOTOR));
		usleep(500000);
	}

	#ifdef DEBUG
		printf("Fermeture de la boucle port-série\n");
	#endif

	pthread_exit(NULL);
}
