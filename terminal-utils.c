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
    result.columns = ts.ts_cols;
    result.rows = ts.ts_lines;
#elif defined(TIOCGWINSZ)
    struct winsize ts;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
  // Cannot write to such a high column?
  // Meh, fix that later, stupid WSL
    result.columns = 100; //ts.ws_col;
    result.rows = ts.ws_row;
#endif /* TIOCGSIZE */
  return result;
}

void hideCursor() {
  printf("\033[?25l");
}

void showCursor() {
  printf("\033[?25h");
}

void clearTerminal(struct ScreenDim screenDim) {
  struct Position pos;
  for (int row=1; row<=screenDim.rows; row++) {
    for (int col=1; col<=screenDim.columns; col++) {
      pos.row = row;
      pos.column = col;
      moveCursor(pos);
      draw(' ');
    }
  }
}

void moveCursor(struct Position pos) {
  printf("\033[%d;%dH", pos.row, pos.column);
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
