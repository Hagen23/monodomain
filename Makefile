CC = g++
CFLAGS = -std=gnu++0x -Wall -Ofast

all: memFH.o monodomainFD.o output.o main.o run

memFH.o: memFH.cc memFH.h types.h constants.h
	${CC} ${CFLAGS} -c memFH.cc

monodomainFD.o: monodomainFD.cc monodomainFD.h types.h constants.h
	${CC} ${CFLAGS} -c monodomainFD.cc

output.o: output.cc output.h types.h constants.h
	${CC} ${CFLAGS} -c output.cc

main.o: main.cc memFH.h monodomainFD.h types.h constants.h
	${CC} ${CFLAGS} -c  main.cc

run: memFH.o monodomainFD.o output.o main.o
	${CC} ${CFLAGS} memFH.o monodomainFD.o output.o main.o -o run

clean:
	rm -rf *o run

