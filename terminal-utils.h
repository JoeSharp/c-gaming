#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

struct winsize getTerminal();
void hideCursor();
void showCursor();
void moveCursor(int pos[2]);
void clear();
void draw(char value[]);
