#ifndef TERMINAL_UTILS_H
#define TERMINAL_UTILS_H

struct Position {
	int row;
	int column;
};
struct ScreenDim {
	int rows;
	int columns;
};
struct ScreenDim getTerminal();
void clearTerminal(struct ScreenDim screenDim);
void hideCursor();
void showCursor();
void moveCursor(struct Position position);
void clear();
void draw(char value);
void flush();

#endif
