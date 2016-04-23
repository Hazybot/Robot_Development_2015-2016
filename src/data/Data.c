#include "Data.h"

Data* initialiseData(){
	Data* data = (Data*) malloc(sizeof(Data));
	data->distances = (float*) calloc(NB_DISTANCE_SENSOR, sizeof(float));
	data->speeds = (float*) calloc(NB_MOTOR, sizeof(float));

	data->stopped = false;

	data->arduino = (int*) calloc(NB_ARDUINO, sizeof(int));

	return data;
}

void freeData(Data* data){
	free(data->distances);
	free(data->speeds);
	free(data);
}
