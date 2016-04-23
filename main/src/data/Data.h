#ifndef DATA
#define DATA

#include <stdlib.h>

#define NB_ARDUINO 2
#define NB_DISTANCE_SENSOR 5
#define NB_MOTOR 2

#define DELIM_CHAR ":"

typedef enum ArduinoFunction ArduinoFunction;
enum ArduinoFunction {SENSOR_ARDUINO, MOTOR_ARDUINO};

typedef enum Motor Motor;
enum Motor {LEFT_MOTOR, RIGHT_MOTOR};

typedef enum DistanceSensor DistanceSensor;
enum DistanceSensor {FRONT_TOP_DISTANCE_SENSOR, FRONT_MIDDLE_DISTANCE_SENSOR, FRONT_BOTTOM_DISTANCE_SENSOR, RIGHT_DISTANCE_SENSOR, LEFT_DISTANCE_SENSOR};

typedef enum bool bool;
enum bool {false=0, true=1};

typedef struct Data Data;
struct Data{
	bool stopped;
	int* arduino;
	float* distances;
	float* speeds;
};

Data* initialiseData();
void freeData(Data* data);

#endif
