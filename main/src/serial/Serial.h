#ifndef SERIAL
#define SERIAL

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "../data/Data.h"

char* readInfo(int arduino);
void writeInfo(int arduino, char* msg);

void* launchSerialLoop(void* data_void);

#endif
