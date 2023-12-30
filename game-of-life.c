#include "game-of-life.h"
#include "terminal-utils.h"

struct GameOfLife createBoard(int rows, int cols) {
	struct GameOfLife board;
	return board;
}

void drawBoard(struct GameOfLife gol) {
  struct Position pos;
  clear();
  for (int x=0; x<10; x++) {
    pos.x = x;
    for (int y=0; y<10; y++) {
      pos.y = y;
      moveCursor(pos);
      if (gol.contents[x][y] > 0) {
        draw('X');
      } else {
        draw('-');
      }
    }
  }
  flush();
}
