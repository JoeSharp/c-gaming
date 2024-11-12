#ifndef FILE_UTILS_H
#define FILE_UTILS_H

struct TextFile {
	int lines;
	char ** contents;
};

struct GridFile {
	int rows;
	int columns;
	char ** contents;
};

void printCharArray(char * arr, int length);
char * padString(char * input, int length, char padding);
char * removeWhitespace(char * input);

struct TextFile loadTextFile(char * filename);
void printTextFile(struct TextFile *textFile);
void freeTextFile(struct TextFile * textFile);

struct GridFile loadGridFile(char * filename, char padding);
void printGridFile(struct GridFile * gridFile);
void freeGridFile(struct GridFile * gridFile);

#endif
