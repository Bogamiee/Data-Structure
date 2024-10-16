#
# Makefile
#

CC = g++
CFLAGS = -Wall -g
SRC = Matrix.cpp MatrixCalc.cpp MatrixOperation.cpp TimeMsr.cpp main.cpp
OBJ = Matrix.o MatrixCalc.o MatrixOperation.o TimeMsr.o main.o
PROG = main

all: $(PROG)

${PROG} : ${OBJ}
	${CC} -o ${PROG} ${OBJ}
${OBJ} : ${SRC}
	${CC} ${CFLAGS} -c -o Matrix.o Matrix.cpp
	${CC} ${CFLAGS} -c -o MatrixCalc.o MatrixCalc.cpp
	${CC} ${CFLAGS} -c -o MatrixOperation.o MatrixOperation.cpp
	${CC} ${CFLAGS} -c -o TimeMsr.o TimeMsr.cpp
	${CC} ${CFLAGS} -c -o main.o main.cpp
clean:
	rm *.o main
