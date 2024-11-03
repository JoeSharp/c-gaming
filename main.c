#include <stdio.h>
#include "terminal-utils.h"
#include "game-of-life.h"
#include <unistd.h>

int main() {
  struct GameOfLife gol = createBoard(2,2);
  for (int i=0; i<4; i++) {
    drawBoard(&gol);
    iterateBoard(&gol);
    sleep(1);
  }
  return 0;
}
