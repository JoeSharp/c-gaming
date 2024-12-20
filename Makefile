BUILD_DIR = build

run: main
	${BUILD_DIR}/main

main: terminal-utils.o file-utils.o game-of-life.o sudoku.o main.o 
	gcc -o ${BUILD_DIR}/main \
		${BUILD_DIR}/main.o \
		${BUILD_DIR}/file-utils.o \
		${BUILD_DIR}/terminal-utils.o \
		${BUILD_DIR}/sudoku.o \
		${BUILD_DIR}/game-of-life.o

main.o: main.c terminal-utils.h file-utils.h game-of-life.h
	gcc -c main.c -o ${BUILD_DIR}/main.o

terminal-utils.o: terminal-utils.h terminal-utils.c
	gcc -c terminal-utils.c -o ${BUILD_DIR}/terminal-utils.o 

file-utils.o: file-utils.h file-utils.c
	gcc -c file-utils.c -o ${BUILD_DIR}/file-utils.o 

game-of-life.o: game-of-life.h terminal-utils.h game-of-life.c
	gcc -c game-of-life.c -o ${BUILD_DIR}/game-of-life.o 

sudoku.o: sudoku.h sudoku.c
	gcc -c sudoku.c -o ${BUILD_DIR}/sudoku.o 

clean:
	rm ${BUILD_DIR}/*
