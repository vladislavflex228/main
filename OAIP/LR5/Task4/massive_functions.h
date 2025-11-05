#ifndef MASSIVE_FUNCTIONS_H
#define MASSIVE_FUNCTIONS_H
#include<limits>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>

int** createMatrix(int m,int n);

void FillMatrix(int**matrix,int n,int m);

void deleteMatrix(int** matrix, int n, int m);

bool read_repeat();

int checkInt0(int &value);

double checkDouble(double &value);

void deleteMassive(int* matrix, int n);

int** reverseMatrix(int** matrix,int m,int n);

long long countNulls(int** matrix,int n,int m);

std::vector<std::pair<int,int>> createMassiveIndex(int** matrix,int n,int m);





#endif