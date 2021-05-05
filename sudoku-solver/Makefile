# Define required macros here
SHELL = /bin/sh

OBJS =  main.cpp individual.cpp population.cpp
CFLAG = -Wall -g
CC = g++
STD = -std=c++11
INCLUDE = 
LIBS = 
BUILD = build/
MKDIR_P = mkdir -p


all: directory main

directory:${BUILD}

${BUILD}:
	${MKDIR_P} ${BUILD}


main:${OBJ}
	${CC} ${STD} ${CFLAG} ${INCLUDE} -o ${BUILD}$@ ${OBJS} ${LIBS}

clean:
	-rm -rf *.o ${BUILD}