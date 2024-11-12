#ifndef FILE_UTILS_H
#define FILE_UTILS_H

struct GridFile {
	int rows;
	int columns;
	char ** contents;
};

struct GridFile loadGridFile(char * filename);
void printGridFile(struct GridFile * gridFile);
void freeGridFile(struct GridFile * gridFile);

#endif
