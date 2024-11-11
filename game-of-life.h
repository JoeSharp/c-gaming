#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

struct GameOfLife {
	int width;
	int height;
	int index;
	int * contents;
};

struct GameOfLife createBoard(int rows, int cols);
void setBoardValue(struct GameOfLife * gol, int x, int y, int value);
int getBoardValue(struct GameOfLife * gol, int x, int y);
void destroyBoard(struct GameOfLife * gol);
void drawBoard(struct GameOfLife * gol);
void iterateBoard(struct GameOfLife * gol);
#endif
