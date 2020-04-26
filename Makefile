# Define required macros here
SHELL = /bin/sh

OBJS =  genetic.cpp
CFLAG = -Wall -g
CC = g++
STD = -std=c++11
INCLUDE = 
LIBS = 
BUILD = build/
MKDIR_P = mkdir -p


all: directory genetic

directory:${BUILD}

${BUILD}:
	${MKDIR_P} ${BUILD}


genetic:${OBJ}
	${CC} ${STD} ${CFLAG} ${INCLUDE} -o ${BUILD}$@ ${OBJS} ${LIBS}

clean:
	-rm -rf *.o ${BUILD}