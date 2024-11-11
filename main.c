#include <stdio.h>
#include <sys/ioctl.h>
#include "terminal-utils.h"
#include "game-of-life.h"
#include <unistd.h>

int main() {
  struct ScreenDim terminal = getTerminal();

  struct GameOfLife gol = createBoard(terminal.rows,terminal.cols);
  while (1) {
    drawBoard(&gol);
    iterateBoard(&gol);
    sleep(1);
  }
  return 0;
}
