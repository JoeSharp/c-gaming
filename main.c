#include <stdio.h>
#include "terminal-utils.h"

int main() {
  clear();
  struct winsize w = getTerminal();
  int pos[2] = {2, 2};
  moveCursor(pos);
  draw("Hello World");
  printf ("lines %d\n", w.ws_row);
  printf ("columns %d\n", w.ws_col);
  return 0;
}
