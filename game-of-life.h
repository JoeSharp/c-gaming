struct GameOfLife {
	int contents[10][10];
};

struct GameOfLife createBoard(int rows, int cols);
void drawBoard(struct GameOfLife gol);
