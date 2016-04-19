#ifndef MAIN_LOOP
#define MAIN_LOOP

	#include <stdio.h>
	#include <stdlib.h>
	#include <pthread.h>
	#include <unistd.h>

	#include "../data/Data.h"

	void* launchMainLoop(void* data);

#endif
