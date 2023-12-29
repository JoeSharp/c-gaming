#include <stdio.h>
#include "terminal-utils.h"



int main() {
  clear();
  struct ScreenDim w = getTerminal();
  struct Position pos;
  for (int i=0; i<10; i++) {
    pos.x = i;
    pos.y = i;
    moveCursor(pos);
    draw("x");
  }
  printf ("lines %d\n", w.rows);
  printf ("columns %d\n", w.cols);
  return 0;
}
