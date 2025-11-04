#ifndef MASSIVE_FUNCTIONS_H
#define MASSIVE_FUNCTIONS_H
#include<limits>
#include<iostream>
#include<algorithm>
#include<iomanip>

int* createMassive(int** matrix,int n);

int** createMatrix(int m,int n);

void FillMatrix(int**matrix,int n,int m);

void deleteMatrix(int** matrix, int n, int m);

bool read_repeat();

int checkInt(long int &value);

int checkInt0(int &value);

void deleteMassive(int* matrix, int n);

long product(int*massive,int n);



#endif