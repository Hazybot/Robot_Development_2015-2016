#include "Data.h"

Data* initialiseData(){
	Data* data = malloc(sizeof(Data));
	data->distances = malloc(NB_DISTANCE_SENSOR*sizeof(float));
	data->speeds = malloc(NB_MOTOR*sizeof(float));

	data->stopped = false;
	return data;
}

void freeData(Data* data){
	free(data->distances);
	free(data->speeds);
	free(data);
}
