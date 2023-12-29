#include <stdio.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "terminal-utils.h"

struct ScreenDim getTerminal() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  struct ScreenDim result;
  result.rows = w.ws_row;
  result.cols = w.ws_col;
  return result;
}

void hideCursor() {
  printf("\033[?25l");
}

void showCursor() {
  printf("\033[?25h");
}

void moveCursor(struct Position pos) {
  printf("\033[%d;%dH", pos.y, pos.x);
}

void clear() {
  printf("\033[2J");
}

void draw(char value[]) {
  printf("%s", value);
}

void flush() {
  fflush(stdout);
}
