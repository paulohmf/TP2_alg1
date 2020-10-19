CC=g++
CFLAGS=-Wall -Wextra -g -std=c++11
EXEC=./tp2

${EXEC}: knap.cpp
	${CC} ${CFLAGS} knap.cpp -o ${EXEC}

