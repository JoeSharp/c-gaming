#include <stdio.h>
#include "terminal-utils.h"

int main() {
  printf("Hello World!");
  clear();
  int pos[2] = {5, 5};
  moveCursor(pos);
  draw("Foo");
  return 0;
}
