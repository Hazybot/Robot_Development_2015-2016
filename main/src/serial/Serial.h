#ifndef SERIAL
#define SERIAL

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../data/Data.h"

int openArduino(int* arduino, int nb);
void closeArduino(int* arduino, int nb);

char* readInfo(int arduino, int size);
void writeInfo(int arduino, char* msg);

void buildDistanceSensor(char* info, float* distances, int size);
char* createMotorString(float* speeds, int size);

void* launchSerialLoop(void* data_void);

#endif
