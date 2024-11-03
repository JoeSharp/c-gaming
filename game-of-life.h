#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define BOARD_SIZE 10

struct GameOfLife {
	int contents[BOARD_SIZE][BOARD_SIZE];
};

struct GameOfLife createBoard(int rows, int cols);
void drawBoard(struct GameOfLife * gol);
void iterateBoard(struct GameOfLife * gol);
#endif
