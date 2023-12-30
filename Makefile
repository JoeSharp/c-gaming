BUILD_DIR = build

run: main
	${BUILD_DIR}/main

main: terminal-utils.o game-of-life.o main.o
	gcc -o ${BUILD_DIR}/main \
		${BUILD_DIR}/main.o \
		${BUILD_DIR}/terminal-utils.o \
		${BUILD_DIR}/game-of-life.o

main.o: main.c terminal-utils.h game-of-life.h
	gcc -c main.c -o ${BUILD_DIR}/main.o

terminal-utils.o: terminal-utils.h terminal-utils.c
	gcc -c terminal-utils.c -o ${BUILD_DIR}/terminal-utils.o 

game-of-life.o: game-of-life.h terminal-utils.h game-of-life.c
	gcc -c game-of-life.c -o ${BUILD_DIR}/game-of-life.o 

clean:
	rm ${BUILD_DIR}/*
