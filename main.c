#include <stdio.h>
#include "terminal-utils.h"

int main() {
  clear();
  int rows = getTerminalRows();
  int cols = getTerminalColumns();
  int pos[2] = {2, 2};
  moveCursor(pos);
  draw("Foo");
  printf("Hello World rows=%d, cols=%d!", rows, cols);
  return 0;
}
