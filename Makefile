CC=g++
ARGS=-Wall
LIBS=-lglut -lGLU -lGL
IDIR=-I./include/
IFILES=src/pyramid.cpp src/main.cpp
ODIR=bin
OFILE=${ODIR}/sinewave

all:
	${CC} ${ARGS} ${LIBS} ${IDIR} ${IFILES} -o ${OFILE}

run:
	${OFILE}

clear:
	rm -rf ${ODIR}/*