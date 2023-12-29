BUILD_DIR = build

main: terminal-utils.o main.o
	gcc -o ${BUILD_DIR}/main \
		${BUILD_DIR}/main.o \
		${BUILD_DIR}/terminal-utils.o
run: main
	${BUILD_DIR}/main

main.o: main.c terminal-utils.h
	gcc -c main.c -o ${BUILD_DIR}/main.o

terminal-utils.o: terminal-utils.h terminal-utils.c
	gcc -c terminal-utils.c -o ${BUILD_DIR}/terminal-utils.o 

clean:
	rm ${BUILD_DIR}/*
