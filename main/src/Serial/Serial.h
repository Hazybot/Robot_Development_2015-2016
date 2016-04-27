#ifndef SERIAL
#define SERIAL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <stdint.h>

#define MESSAGE_LENGHT 100


int open_s(char *name);

int read_s(int fd, char *buffer);

int write_s(int fd, char *buffer, int nbyte);

int close_s(int fd);

#endif
