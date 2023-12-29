#include <stdio.h>
#include "terminal-utils.h"
#include <unistd.h>

int main() {
  clear();
  struct ScreenDim w = getTerminal();
  struct Position pos;
  for (int offset=1; offset<5; offset++) {
    for (int i=0; i<10; i++) {
      pos.x = i;
      pos.y = i + offset;
      moveCursor(pos);
      draw("x");
    }
    flush();
    sleep(1);
  }
  printf ("lines %d\n", w.rows);
  printf ("columns %d\n", w.cols);
  return 0;
}
