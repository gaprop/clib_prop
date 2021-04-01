CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic -std=gnu99 -pthread

stack: stack.c
	$(CC) $(CFLAGS) stack.c -o stack
