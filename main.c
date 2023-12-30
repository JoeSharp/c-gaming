#include <stdio.h>
#include "terminal-utils.h"
#include "game-of-life.h"
#include <unistd.h>

int main() {
  struct GameOfLife gol = createBoard(2,2);
  drawBoard(gol);
  return 0;
}
