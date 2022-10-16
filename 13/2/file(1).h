#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FILE_H
#define FILE_H

extern int loadCount;
extern int saveCount;

int *loadFromFile(char *fileName);

void saveToFile(int arguments[], char *fileName);

#endif