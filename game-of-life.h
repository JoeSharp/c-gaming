#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include "file-utils.h"

struct GameOfLife {
	int rows;
	int columns;
	int index;
	int * contents;
};

struct GameOfLife createBoard(int rows, int cols);
void writeGridToBoard(struct GameOfLife * gol, struct GridFile * gridFile, int row, int column);
void setBoardValue(struct GameOfLife * gol, int row, int column, int value);
int getBoardValue(struct GameOfLife * gol, int row, int column);
void destroyBoard(struct GameOfLife * gol);
void drawBoard(struct GameOfLife * gol);
void iterateBoard(struct GameOfLife * gol);
void flipBoardIndex(struct GameOfLife * gol);
#endif
