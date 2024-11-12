#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "terminal-utils.h"
#include "game-of-life.h"
#include "file-utils.h"
#include <unistd.h>

int main() {
  struct GridFile file = loadGridFile("./structures/beacon.txt");
  printf("PRINTING\n");
  printGridFile(&file);
  printf("PRINTED\n");
  freeGridFile(&file);

  exit(0);

  struct ScreenDim terminal = getTerminal();

  struct GameOfLife gol = createBoard(terminal.rows,terminal.cols);
  while (1) {
    drawBoard(&gol);
    iterateBoard(&gol);
    sleep(1);
  }
  return 0;
}
