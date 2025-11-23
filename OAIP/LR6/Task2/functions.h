
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<limits>
#include<cstring>

bool read_repeat();

char* readStringDynamic(int &len);

int checkInt0(int &value);

char* readReplaceNoSpaces(int &len);

char* replaceWords(char* text, int wordLen, char* replace);



#endif