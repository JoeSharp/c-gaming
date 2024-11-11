#include <stdio.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "terminal-utils.h"

struct ScreenDim getTerminal() {
  struct ScreenDim result;
#ifdef TIOCGSIZE
    struct ttysize ts;
    ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
    result.cols = ts.ts_cols;
    result.rows = ts.ts_lines;
#elif defined(TIOCGWINSZ)
    struct winsize ts;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
    result.cols = ts.ws_col;
    result.lines = ts.ws_row;
#endif /* TIOCGSIZE */
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

void draw(char value) {
  printf("%c", value);
}

void flush() {
  fflush(stdout);
}
