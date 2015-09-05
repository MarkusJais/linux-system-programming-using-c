CC=gcc
CFLAGS=-std=c11 -Wall


fork1:
	gcc $(CFLAGS) -o fork1 fork1.c

clean:
	rm -f fork1
