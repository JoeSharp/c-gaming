#include <stdio.h>

void hideCursor() {
  printf("\033[?25l");
}

void showCursor() {
  printf("\033[?25h");
}

void moveCursor(int pos[2]) {
  printf("\033[%d,%dH", pos[0], pos[1]);
}

void clear() {
  printf("\033[2J");
}

void draw(char value[]) {
  printf("%s", value);
}
