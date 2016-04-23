#include "Serial.h"

int openArduino(int* arduino, int nb){
	char* name = "/dev/ttyACM";
	int* tempArduino = calloc(nb, sizeof(int));
	int i;
	int success = 0;
	for(i = 0; (i < 10) && (success < nb); i++){
		int file;
		char* port = (char*) calloc(strlen(name)+1, sizeof(char));
		sprintf(port, "%s%d", name, i);
		file = open(port, O_RDWR);
		if(file != -1){
			#ifdef DEBUG
				printf("Ouverture du port %s\n", port);
			#endif
			tempArduino[success] = file;
			success++;
		}
		free(port);
	}

	if(i >= 10){
		printf("Can't open arduino\n");
		return -1;
	}

	for(i = 0; i < nb; i++){
		arduino[i] = tempArduino[i];
	}

	return 0;
}

void closeArduino(int* arduino, int nb){
	int i;
	for(i = 0; i < nb; i++){
		close(arduino[i]);
	}
}

char* readInfo(int arduino, int size){
	char* result = (char*) calloc(size+1, sizeof(char));
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
	char* result = (char*) calloc(size*6, sizeof(char));
	char* oneSpeed = (char*) calloc(7, sizeof(char));
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
		char* info_r = readInfo(0, NB_DISTANCE_SENSOR*6);
		char* info_w = createMotorString(data->speeds, NB_MOTOR);
		buildDistanceSensor(info_r, data->distances, NB_DISTANCE_SENSOR);
		writeInfo(1, info_w);
		free(info_r);
		free(info_w);
		usleep(500000);
	}

	#ifdef DEBUG
		printf("Fermeture de la boucle port-série\n");
	#endif

	pthread_exit(NULL);
}
