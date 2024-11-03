#include <stdio.h>
#include <stdlib.h>
#include "game-of-life.h"
#include "terminal-utils.h"

#define BOARD_SIZE 10

struct GameOfLife createBoard(int rows, int cols) {
  struct GameOfLife board;
  for (int x=0; x<BOARD_SIZE; x++) {
    for (int y=0; y<BOARD_SIZE; y++) {
      board.contents[x][y] = rand() % 2 == 0 ? 1 : 0;
    }
  }

  return board;
}

void drawBoard(struct GameOfLife * gol) {
  struct Position pos;
  clear();
  for (int x=0; x<BOARD_SIZE; x++) {
    pos.x = x;
    for (int y=0; y<BOARD_SIZE; y++) {
      pos.y = y;
      moveCursor(pos);
      if (gol->contents[x][y] > 0) {
        draw('X');
      } else {
        draw('-');
      }
    }
  }
  flush();
}

void iterateBoard(struct GameOfLife * gol) {
  for (int x=0; x<BOARD_SIZE; x++) {
    for (int y=0; y<BOARD_SIZE; y++) {
      if (gol->contents[x][y] == 0) {
        gol->contents[x][y] = 1;
      } else {
        gol->contents[x][y] = 0;
      }
    }
  }
}
