#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game-of-life.h"
#include "terminal-utils.h"

#define ALIVE 'O'
#define DEAD ' '

int countNeighbours(struct GameOfLife * gol, int x, int y);
int incrementIfTrue(int count, bool valid, struct GameOfLife * gol, int x, int y);
int nextState(int currentState, int neighbours);

int getIndex(struct GameOfLife * gol, int index, int x, int y) {
  return (index * gol->width * gol->height) + (x * gol->height) + y;
}

struct GameOfLife createBoard(int rows, int cols) {
  struct GameOfLife board;
  // Ensure the 0th index is filled in, for initial state
  board.index = 0;
  board.width = cols;
  board.height = rows;
  int totalSize = sizeof(int) * 2 * rows * cols;
  board.contents = malloc(totalSize);
  for (int index=0; index<2; index++) {
    for (int x=0; x<board.width; x++) {
      for (int y=0; y<board.height; y++) {
        board.contents[getIndex(&board, index, x, y)] = 0;
        //rand() % 2 == 0 ? 1 : 0;
      }
    }
  }

  board.index = 1;
  // Blinker
  setBoardValue(&board, 2, 2, 1);
  setBoardValue(&board, 2, 3, 1);
  setBoardValue(&board, 2, 4, 1);

  // Toad
  setBoardValue(&board, 6, 6, 1);
  setBoardValue(&board, 6, 7, 1);
  setBoardValue(&board, 6, 8, 1);
  setBoardValue(&board, 7, 5, 1);
  setBoardValue(&board, 7, 6, 1);
  setBoardValue(&board, 7, 7, 1);

  // Spaceship
  for (int i=0; i < cols; i += 7) {
    setBoardValue(&board, 8 + i, 1, 1);
    setBoardValue(&board, 9 + i, 2, 1);
    setBoardValue(&board, 10 + i, 0, 1);
    setBoardValue(&board, 10 + i, 1, 1);
    setBoardValue(&board, 10 + i, 2, 1);
  }

  // Switch back to first index
  board.index = 0;

  return board;
}

int getBoardValue(struct GameOfLife * gol, int x, int y) {
  int i = getIndex(gol, gol->index, x, y);
  return gol->contents[i];
}

void setBoardValue(struct GameOfLife * gol, int x, int y, int value) {
  int otherIndex = gol->index == 0 ? 1 : 0;
  int i = getIndex(gol, otherIndex, x, y);
  gol->contents[i] = value;
}

void destroyBoard(struct GameOfLife * gol) {
  free(gol->contents);
}

void drawBoard(struct GameOfLife * gol) {
  struct Position pos;
  clear();
  for (int x=0; x<gol->width; x++) {
    pos.x = x;
    for (int y=0; y<gol->height; y++) {
      pos.y = y;
      moveCursor(pos);
      if (getBoardValue(gol, x, y) > 0) {
        draw(ALIVE);
      } else {
        draw(DEAD);
      }
    }
  }
  flush();
}

void iterateBoard(struct GameOfLife * gol) {
  int otherIndex = gol->index == 0 ? 1 : 0;
  for (int x=0; x<gol->width; x++) {
    for (int y=0; y<gol->height; y++) {
      int neighbours = countNeighbours(gol, x, y);
      int currentState = getBoardValue(gol, x, y);
      setBoardValue(gol, x, y, nextState(currentState, neighbours));
    }
  }
  gol->index = otherIndex;
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


int incrementIfTrue(int count, bool valid, struct GameOfLife * gol, int x, int y) {
  if (!valid) return count;
  if (getBoardValue(gol, x, y) > 0) return count + 1;
  return count;
}

int countNeighbours(struct GameOfLife * gol, int x, int y) {
  int count = 0;

  bool onFarLeft = x == 0;
  bool onFarRight = x == gol->width - 1;
  bool onTop = y == 0;
  bool onBottom = y == gol->height - 1;

  count = incrementIfTrue(count, !(onFarLeft || onTop), gol, x-1, y-1);
  count = incrementIfTrue(count, !onFarLeft, gol, x-1, y);
  count = incrementIfTrue(count, !(onFarLeft || onBottom), gol, x-1, y+1);
  
  count = incrementIfTrue(count, !onTop, gol, x, y-1);  
  count = incrementIfTrue(count, !onBottom, gol, x, y+1);
  
  count = incrementIfTrue(count, !(onFarRight || onTop), gol, x+1, y-1);
  count = incrementIfTrue(count, !onFarRight, gol, x+1, y);
  count = incrementIfTrue(count, !(onFarRight || onBottom), gol, x+1, y+1);

  return count;
}
