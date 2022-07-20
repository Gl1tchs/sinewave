CC=g++
CFLAGS=-Wall
LIBS=-lglut -lGLU -lGL
IDIR=-I./include/
SOURCES=src/object.cpp src/pyramid.cpp src/main.cpp
OUTDIR=bin
OUTFILENAME=sinewave
OUTFILE=${OUTDIR}/${OUTFILENAME}

all:
	@echo Building files...
	${CC} ${ARGS} ${LIBS} ${IDIR} ${SOURCES} -o ${OUTFILE}

run:
	@echo Starting animation...
	${OUTFILE}

clear:
	@echo Removing binaries...
	rm -rf ${OUTDIR}/*

install:
	@echo Installing globally...
	sudo cp -r ${OUTFILE} /usr/bin/${OUTFILENAME}

uninstall:
	@echo Removing globally...
	sudo rm /usr/bin/${OUTFILENAME}
