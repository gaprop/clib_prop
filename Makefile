CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic -std=gnu99 -pthread

stack.o: stack.c stack.h utils.h
	$(CC) stack.c stack.h utils.h $(CFLAGS)
