CC = gcc

CFLAGS = -ansi -pedantic -Wall -g

rk: rk.o parameters.o
<Tab>$(CC) $(CFLAGS) -o rk rk.o parameters.o -lm

rk.o: rk.c  parameters.h
<Tab>$(CC) $(CFLAGS) -c rk.c -lm

parameters.o: parameters.c parameters.h
<Tab>$(CC) $(CFLAGS) -c parameters.c -lm