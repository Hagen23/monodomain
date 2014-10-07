CC = g++
CFLAGS = -std=gnu++0x -Wall -Ofast

all: MemFH.o PointStim.o MonodomainFD.o Output.o Main.o run

MemFH.o: MemFH.cc MemFH.h Types.h Constants.h
	${CC} ${CFLAGS} -c MemFH.cc

PointStim.o: PointStim.cc PointStim.h Types.h Constants.h
	${CC} ${CFLAGS} -c PointStim.cc

MonodomainFD.o: MonodomainFD.cc MonodomainFD.h Types.h Constants.h
	${CC} ${CFLAGS} -c MonodomainFD.cc

Output.o: Output.cc Output.h Types.h Constants.h
	${CC} ${CFLAGS} -c Output.cc

Main.o: Main.cc MemFH.h MonodomainFD.h Types.h Constants.h
	${CC} ${CFLAGS} -c  Main.cc

run: MemFH.o PointStim.o MonodomainFD.o Output.o Main.o
	${CC} ${CFLAGS} MemFH.o PointStim.o MonodomainFD.o Output.o Main.o -o run

clean:
	rm -rf *o run

