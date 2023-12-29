#include <stdio.h>
#include <stdlib.h>

int getTerminalRows() {
  char * rows = getenv("ROWS");
  printf("Rows: %s", rows);
  return 1;
}
int getTerminalColumns() {
  char * columns = getenv("COLUMNS");
  printf("Columns: %s", columns);
  return 1;
}

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
