CC=g++
ARGS=-Wall
LIBS=-lglut -lGLU -lGL
IDIR=-I./include/
IFILES=src/pyramid.cpp src/main.cpp
ODIR=bin
OFILENAME=sinewave
OFILE=${ODIR}/${OFILENAME}

all:
	${CC} ${ARGS} ${LIBS} ${IDIR} ${IFILES} -o ${OFILE}

run:
	${OFILE}

clear:
	rm -rf ${ODIR}/*

install:
	sudo cp -r ${OFILE} /usr/bin/${OFILENAME}

uninstall:
	sudo rm /usr/bin/${OFILENAME}
