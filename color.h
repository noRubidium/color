#ifndef POINT_H
#define POINT_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>

typedef struct _color color;
typedef color *Color;
typedef unsigned char byte;

int writeStruct(int fd, int x, int y, int width, int height, byte r, byte g, byte b);
Color readStruct(int fd, int x, int y, int width, int height);
void printColor(Color c);
void destroyColor(Color c);
#endif
