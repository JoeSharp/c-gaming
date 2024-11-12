#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file-utils.h"

#define MAX_LINE_LENGTH 1024

struct GridFile loadGridFile(char * filename) {
  struct GridFile result;
  result.contents = NULL;
  result.rows = 0;
  result.columns = 0;

  FILE *fptr;
  fptr = fopen(filename, "r");
  if (fptr == NULL) {
    printf("Could not load file %s\n", filename);
    exit(1);
  }

  char buffer[MAX_LINE_LENGTH];
  while (fgets(buffer, MAX_LINE_LENGTH, fptr)) {
    int columns = strlen(buffer);
    if (columns > result.columns) {
      result.columns = columns;
    }

    printf("Allocating size of char * %lu, %lu, for rows %d\n", sizeof(char *), sizeof(char), result.rows);
    result.contents = realloc(result.contents, sizeof(char *) * result.rows);
    for (int i=0; i<result.rows; i++) {
      printf("0x%p ", result.contents[i]);
    }
    printf("\n");
    char * rowData = malloc(columns);
    strcpy(rowData, buffer);
    result.contents[result.rows] = rowData;
    result.rows++;
  }
  fclose(fptr);

  return result;
}

void printGridFile(struct GridFile * gridFile) {
  printf("Grid File %d x %d\n", gridFile->rows, gridFile->columns);
  for (int row=0; row<gridFile->rows; row++) {
    printf("%s", gridFile->contents[row]);
    /*
    for (int col=0; col<gridFile->columns; col++) {
      printf("%c", gridFile->contents[row][col]);
    }*/
    printf("\n");
  }
}

void freeGridFile(struct GridFile *gridFile) {
  for (int row=0; row<gridFile->rows; row++) {
    free(gridFile->contents[row]);
  }
  free(gridFile->contents);
}
