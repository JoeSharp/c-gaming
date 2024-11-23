#ifndef SUDOKU_H
#define SUDOKU_H

#define UNKNOWN_CELL_VALUE -1

struct SudokuCell {
	int value;
	int possibleValues[9]; 
};

struct SudokuBlock {
	struct SudokuCell cells[3][3];
};

struct Sudoku {
	struct SudokuBlock blocks[3][3];
};

struct Sudoku * loadSudoku(char * filename);
struct Sudoku * createSudoku();
void printGrid();
void printSudoku(struct Sudoku * sudoku);
void cleanSudoku(struct Sudoku * sudoku);

#endif

