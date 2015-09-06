CC=gcc
CFLAGS=-std=c11 -Wall


all: clean fork1 pipe

fork1:
	gcc $(CFLAGS) -o fork1 fork1.c

pipe:
	gcc $(CFLAGS) -o pipe pipe.c

clean:
	rm -f fork1 pipe
