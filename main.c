#include <stdio.h>
#include <sys/ioctl.h>
#include "terminal-utils.h"
#include "game-of-life.h"
#include "sudoku.h"
#include "file-utils.h"
#include <unistd.h>

void runGameOfLife(struct ScreenDim * terminal) {
  struct GridFile gridFile = loadGridFile("./structures/pentadecathalon.txt", '-');

  struct GameOfLife gol = createBoard(terminal->rows, terminal->columns);
  for (int column=0; column<terminal->columns; column+=10) {
    writeGridToBoard(&gol, &gridFile, 0, column);
  }
  flipBoardIndex(&gol);
  freeGridFile(&gridFile);

  while (1) {
    drawBoard(&gol);
    iterateBoard(&gol);
    sleep(1);
  }
}

void runSudoku(struct ScreenDim * terminal) {

  printf("Running Sudoku Program\n");
  printGrid();
  struct Sudoku * sudoku = createSudoku();
  printSudoku(sudoku);
  cleanSudoku(sudoku);
}

int main() {
  struct ScreenDim terminal = getTerminal();
  clearTerminal(terminal);

  runSudoku(&terminal);
  //runGameOfLife(&terminal);

  return 0;
}
