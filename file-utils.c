#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "file-utils.h"

#define MAX_LINE_LENGTH 1024


void printCharArray(char * arr, int length) {
  printf("Printing Ptr Array\n");
  for (int i=0; i<length; i++) {
    printf("%02x ", arr[i]);
  }
  printf("\n");
}

struct TextFile loadTextFile(char * filename) {
  struct TextFile result;
  result.lines = 0;
  result.contents = NULL;
    
  FILE *fptr;
  fptr = fopen(filename, "r");
  if (fptr == NULL) {
    printf("Could not load file %s\n", filename);
    exit(1);
  }

  char buffer[MAX_LINE_LENGTH];
  while (fgets(buffer, MAX_LINE_LENGTH, fptr)) {
    result.lines++;
    result.contents = realloc(result.contents, sizeof(char *) * (result.lines));
    result.contents[result.lines - 1] = removeWhitespace(buffer);
  }
  fclose(fptr);

  return result;
}

void printTextFile(struct TextFile *textFile) {
  printf("Printing Text File\n");
  for (int i=0; i<textFile->lines; i++) {
    printf("%s\n", textFile->contents[i]);
  }

  printf("------------\n");
}

void freeTextFile(struct TextFile * textFile) {
  for (int i=0; i<textFile->lines; i++) {
    free(textFile->contents[i]);
  }
  free(textFile->contents);
}

int findLongestLine(struct TextFile *textFile) {
  int result = 0;

  for (int i=0; i<textFile->lines; i++) {
    int lineLength = strlen(textFile->contents[i]);
    if (lineLength > result) {
      result = lineLength;
    }
  }

  return result;
}

char * removeWhitespace(char * input) {
  int inputLength = strlen(input);

  int outputLength = 0;
  for (int i=0; i<inputLength; i++) {
    if (!isspace(input[i])) {
      outputLength++;
    }
  }

  int writeIndex = 0;
  char * output = malloc(sizeof(char) * outputLength);

  for (int i=0; i<inputLength; i++) {
    if (!isspace(input[i])) {
      output[writeIndex++] = input[i];
    }
  }
  output[writeIndex] = '\0';

  return output;
}

char * padString(char * input, int length, char padding) {
  int actualLength = strlen(input);

  char * output = malloc(sizeof(char) * length);
  strcpy(output, input);
  for (int i=actualLength; i<length; i++) {
    output[i] = padding;
  }

  return output;
}

struct GridFile loadGridFile(char * filename, char padding) {
  struct TextFile textFile = loadTextFile(filename);
  
  struct GridFile result;
  result.contents = textFile.contents;
  result.rows = textFile.lines;
  result.columns = findLongestLine(&textFile);

  for (int i=0; i<result.rows; i++) {
    char * original = result.contents[i];
    result.contents[i] = padString(original, result.columns, padding);
    free(original);
  }

  return result;
}

void printGridFile(struct GridFile * gridFile) {
  printf("Grid File %d x %d\n", gridFile->rows, gridFile->columns);
  for (int row=0; row<gridFile->rows; row++) {
    printf("%s\n", gridFile->contents[row]);
  }
  printf("-------------\n");
}

void freeGridFile(struct GridFile *gridFile) {
  for (int row=0; row<gridFile->rows; row++) {
    free(gridFile->contents[row]);
  }
  free(gridFile->contents);
}
