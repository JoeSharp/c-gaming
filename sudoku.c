#include <stdlib.h>
#include <stdio.h>
#include "sudoku.h"

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
          sudoku->blocks[blockRow][blockCol].cells[cellRow][cellCol].value = 1;
        }
      }
    }
  }

  return sudoku;
}

void printSeparatorLine() {
  // 3 blocks, each with a 3*3 grid and separator either side
  int totalCols = 3 * 3 + 4;
  for (int i=0; i<totalCols; i++) {
    printf("-");
  }
  printf("\n");
}

void printSudoku(struct Sudoku * sudoku) {

  printSeparatorLine();

  for (int blockRow=0; blockRow<3; blockRow++) {
    for (int cellRow=0; cellRow<3; cellRow++) {
      for (int blockCol=0; blockCol<3; blockCol++) {
        printf("|");
        for (int cellCol=0; cellCol<3; cellCol++) {
          printf("%d", sudoku->blocks[blockRow][blockCol].cells[cellRow][cellCol].value);
        }
      }
      printf("|\n");
    }
    printSeparatorLine();
  }
}

void cleanSudoku(struct Sudoku * sudoku) {
  free(sudoku);
}
