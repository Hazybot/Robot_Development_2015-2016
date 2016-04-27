#include "stdio.h"
#include "stdlib.h"
#include "../Serial/Serial.h"

int main(int argc, char** argv){
	printf("Hello World !\n");
	int fd = open_s("/dev/ttyACM0");
	char* car = "aaa";
	int val = write_s(fd, car, 3);
	if(val == 1){
		printf("YATA\n" );
	}
	val = write_s(fd, car, 3);
	if(val == 1){
		printf("YATA\n" );
	}
	val = write_s(fd, car, 3);
	if(val == 1){
		printf("YATA\n" );
	}
	val = write_s(fd, car, 3);
	if(val == 1){
		printf("YATA\n" );
	}
	close_s(fd);
	return 0;
}
