struct Position {
	int x;
	int y;
};
struct ScreenDim {
	int rows;
	int cols;
};
struct ScreenDim getTerminal();
void hideCursor();
void showCursor();
void moveCursor(struct Position position);
void clear();
void draw(char value);
void flush();
