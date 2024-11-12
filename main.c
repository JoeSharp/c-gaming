#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "terminal-utils.h"
#include "game-of-life.h"
#include "file-utils.h"
#include <unistd.h>

int main() {
  struct GridFile gridFile = loadGridFile("./structures/beacon.txt", '-');
  struct ScreenDim terminal = getTerminal();

  struct GameOfLife gol = createBoard(terminal.rows, terminal.columns);
  for (int column=0; column<terminal.columns; column+=10) {
    writeGridToBoard(&gol, &gridFile, 0, column);
  }
  flipBoardIndex(&gol);
  freeGridFile(&gridFile);

  while (1) {
    drawBoard(&gol);
    iterateBoard(&gol);
    sleep(1);
  }
  return 0;
}
