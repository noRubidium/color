CC=gcc
CFLAGS=-Wall -Werror -O2 -std=c99
EXECUTABLE=write

all: color.o write.c
	$(CC) $(CFLAGS) color.o write.c -o $(EXECUTABLE)

color.o: color.h color.c
	$(CC) -c color.c
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
