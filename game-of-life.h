#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H
struct GameOfLife {
	int contents[10][10];
};

struct GameOfLife createBoard(int rows, int cols);
void drawBoard(struct GameOfLife gol);
#endif
