    
#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H
#include<limits>


int** createMatrix(int n);


void fillMatrixA(int** matrix, int n);

void fillMatrixB(int** matrix, int n);

long long sumMainDiagonal(int** matrix, int n);

void printMatrix(int** matrix, int n, const char* name);

void deleteMatrix(int** matrix, int n);

bool read_repeat();

int checkInt(long int &value);

int checkInt0(int &value);

#endif 
  