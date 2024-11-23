#include <stdlib.h>
#include <stdio.h>
#include "sudoku.h"
#include "terminal-utils.h"

struct Sudoku * loadSudoku(char * filename) {
  struct Sudoku * sudoku = createSudoku();

  return sudoku;
}

struct Sudoku * createSudoku() {
  struct Sudoku * sudoku = malloc(sizeof(struct Sudoku));
  for (int blockRow=0; blockRow<3; blockRow++) {
    for (int blockCol=0; blockCol<3; blockCol++) {
      for (int cellRow=0; cellRow<3; cellRow++) {
        for (int cellCol=0; cellCol<3; cellCol++) {
          sudoku->blocks[blockRow][blockCol].cells[cellRow][cellCol].value = UNKNOWN_CELL_VALUE;
        }
      }
    }
  }

  return sudoku;
}

void printGrid() {
  struct Position pos;

  for (int col=0; col<4; col++) {
    pos.column = 1 + 4 * col;
    for (int row=1; row<(4 * 3 + 1); row++) {
      pos.row = 1 + row;
      moveCursor(pos);
      draw('|');
    }
  }

  for (int row=0; row<4; row++) {
    pos.row = 1 + 4 * row;
    for (int col=0; col<(4 * 3 + 1); col++) {
      pos.column = 1 + col;
      moveCursor(pos);
      draw('-');
    }
  }
}

void printSudoku(struct Sudoku * sudoku) {
  struct Position pos;

  for (int blockRow=0; blockRow<3; blockRow++) {
    for (int blockCol=0; blockCol<3; blockCol++) {
      for (int cellRow=0; cellRow<3; cellRow++) {
        for (int cellCol=0; cellCol<3; cellCol++) {
          pos.row = 2 + (blockRow * 4) + cellRow; 
          pos.column = 2 + (blockCol * 4) + cellCol; 
          moveCursor(pos);
          int value = sudoku->blocks[blockRow][blockCol].cells[cellRow][cellCol].value;
          if (value == UNKNOWN_CELL_VALUE) {
            draw('x');
          } else {
            draw('0' + value);
          }
        }
      }
    }
  }

  // Put the cursor in bottom right corner
  pos.column = 1 + 3*4;
  pos.row = 1 + 3*4;
  moveCursor(pos);
}

void cleanSudoku(struct Sudoku * sudoku) {
  free(sudoku);
}
