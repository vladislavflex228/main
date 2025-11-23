
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<limits>
#include<cstring>
#include<locale>

bool read_repeat();

wchar_t* readString(int &len);

wchar_t* compressString(const wchar_t* str, int len, int &newLen);

void printCompressedString(const wchar_t* str, int len);

int checkInt0(int &value);

bool compareArrays(const wchar_t* a, const wchar_t* b, int len);

#endif