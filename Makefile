SHELL = /bin/bash

CC = gcc
CFLAGS = -Wall --pedantic

TARGET = bin/
SRC = source/

SZAD1 = ${SRC}zad1/
TZAD1 = ${TARGET}zad1/

zadania: zad1
 
zad1:
	${CC} ${CFLAGS} ${SZAD1}client.c -o ${TZAD1}client.o
	${CC} ${CFLAGS} ${SZAD1}server.c -o ${TZAD1}server.o

clean:
	rm -rf ${TZAD1}*.o

.PHONY: zadania clean
