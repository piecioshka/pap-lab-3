CC = gcc
CFLAGS = -Wall --pedantic
TARGET = bin/
SRC = source/

zad1:
	${CC} ${CFLAGS} ${SRC}$@/klientUDP.c -o ${TARGET}$@/klientUDP.o
	${CC} ${CFLAGS} ${SRC}$@/serwerUDP.c -o ${TARGET}$@/serwerUDP.o

clean:
	find ${TARGET} -name "*.o" | xargs rm -rf

