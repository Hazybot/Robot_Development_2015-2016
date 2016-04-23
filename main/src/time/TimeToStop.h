#ifndef TIME_TO_STOP
#define TIME_TO_STOP

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "../data/Data.h"

#define STOP_TIME 1

void* launchTime(void* stopped_void);

#endif
