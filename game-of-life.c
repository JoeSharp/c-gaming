#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game-of-life.h"
#include "terminal-utils.h"

#define ALIVE 'O'
#define DEAD '.'

int countNeighbours(struct GameOfLife * gol, int row, int column);
int incrementIfTrue(int count, bool valid, struct GameOfLife * gol, int row, int column);
int nextState(int currentState, int neighbours);

int getIndex(struct GameOfLife * gol, int index, int row, int column) {
  return (index * gol->rows * gol->columns) + (row * gol->columns) + column;
}

struct GameOfLife createBoard(int rows, int cols) {
  struct GameOfLife board;
  // Ensure the 0th index is filled in, for initial state
  board.index = 0;
  board.rows = rows;
  board.columns = cols;

  int totalSize = sizeof(int) * 2 * rows * cols;
  board.contents = malloc(totalSize);
  for (int index=0; index<2; index++) {
    for (int row=0; row<board.rows; row++) {
      for (int column=0; column<board.columns; column++) {
        board.contents[getIndex(&board, index, row, column)] = 0;
      }
    }
  }

  return board;
}

void writeGridToBoard(struct GameOfLife * gol, 
                      struct GridFile * gridFile, 
                      int startRow, 
                      int startColumn) {
  if (gridFile->rows + startRow > gol->rows) {
    printf("Cannot write to such a high row");
    exit(1);
  }
  if (gridFile->columns + startColumn > gol->columns) {
    printf("Cannot write to such a high column");
    exit(1);
  }

  for (int row=0; row<gridFile->rows; row++) {
    for (int column=0; column<gridFile->columns; column++) {
      int value = gridFile->contents[row][column] == ALIVE ? 1 : 0;
      setBoardValue(gol, startRow + row, startColumn + column, value);
    }
  }
}

int getBoardValue(struct GameOfLife * gol, int row, int column) {
  int i = getIndex(gol, gol->index, row, column);
  return gol->contents[i];
}

void setBoardValue(struct GameOfLife * gol, int row, int column, int value) {
  int otherIndex = gol->index == 0 ? 1 : 0;
  int i = getIndex(gol, otherIndex, row, column);
  gol->contents[i] = value;
}

void destroyBoard(struct GameOfLife * gol) {
  free(gol->contents);
}

void drawBoard(struct GameOfLife * gol) {
  struct Position pos;
  clear();
  for (int row=0; row<gol->rows; row++) {
    pos.row = row;
    for (int column=0; column<gol->columns; column++) {
      pos.column = column;
      moveCursor(pos);
      if (getBoardValue(gol, row, column) > 0) {
        draw(ALIVE);
      } else {
        draw(DEAD);
      }
    }
  }
  flush();
}

void iterateBoard(struct GameOfLife * gol) {
  for (int row=0; row<gol->rows; row++) {
    for (int column=0; column<gol->columns; column++) {
      int neighbours = countNeighbours(gol, row, column);
      int currentState = getBoardValue(gol, row, column);
      setBoardValue(gol, row, column, nextState(currentState, neighbours));
    }
  }

  flipBoardIndex(gol);
}

int nextState(int currentState, int neighbours) {
  switch (neighbours) {
    case 0:
    case 1:
      // Underpopulation, or already dead
      return 0;
    case 2:
      // lives on
      return currentState;
    case 3:
      // Reproduction, or lives on
      return 1;
    default:
      // Overpopulation, or already dead
      return 0;
  }
  
}

void flipBoardIndex(struct GameOfLife * gol) {
  gol->index = gol->index == 0 ? 1 : 0;
}

int incrementIfTrue(int count, bool valid, struct GameOfLife * gol, int row, int column) {
  if (!valid) return count;
  if (getBoardValue(gol, row, column) > 0) return count + 1;
  return count;
}

int countNeighbours(struct GameOfLife * gol, int row, int column) {
  int count = 0;

  bool onFarLeft = column == 0;
  bool onFarRight = column == gol->columns - 1;
  bool onTop = row == 0;
  bool onBottom = row == gol->rows - 1;

  count = incrementIfTrue(count, !(onTop || onFarLeft), gol, row - 1, column - 1);
  count = incrementIfTrue(count, !onFarLeft, gol, row, column - 1);
  count = incrementIfTrue(count, !(onBottom || onFarLeft), gol, row + 1, column - 1);
  
  count = incrementIfTrue(count, !onTop, gol, row - 1, column);  
  count = incrementIfTrue(count, !onBottom, gol, row + 1, column);
  
  count = incrementIfTrue(count, !(onTop || onFarRight), gol, row - 1, column + 1);
  count = incrementIfTrue(count, !onFarRight, gol, row, column + 1);
  count = incrementIfTrue(count, !(onBottom || onFarRight), gol, row + 1, column + 1);

  return count;
}
