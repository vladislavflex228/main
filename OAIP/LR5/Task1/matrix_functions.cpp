#include"matrix_functions.h"
#include<iostream>
#include<iomanip> //ДЛя setw

int checkInt(long int &value) {
    while (true) {
        std::cout << "Введите число: ";
        if ( (std::cin >> value) && (std::cin.peek() == '\n') ) 
        {
            
        
            return value;
        } 
        else 
        {
            std::cout << "Нужны только целые числа без пробелов\n";
            std::cin.clear();
            std::cin.ignore(999, '\n');
        }
    }


}

int checkInt0(int &value) {
    while (true) {
        std::cout << "Введите число: ";
        if ( (std::cin >> value) && (std::cin.peek() == '\n') && (value > 0) && (value < 1000000)) 
        {
            
       
            return value;
        } 
        else 
        {
            std::cout << "Нужны только натуральные числа не превосходящие миллиона без пробелов\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
int** createMatrix(int n){
    int**matrix = new int*[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }
    return matrix;

}

void fillMatrixA(int**matrix,int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 3*i*j - 3;
        }
        
    }
    
}

void fillMatrixB(int**matrix,int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 2*i*j - 2;
        }
        
    }
    
}

long long sumMainDiagonal(int** matrix, int n){
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][i];
    }
    return sum;
}

void printMatrix(int** matrix, int n, const char* name){
    std::cout << "Матрица " << name << ":" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(6) << matrix[i][j];  //Следующий элемент будет занимать минимум 6 символов
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
bool read_repeat () {

    bool temp;
    std::cout << "Wanna restart a program? (YES = 1; NO = 0): ";

    while (!(std::cin >> temp) || std::cin.peek() != '\n') {

        std::cin.clear ();
        while (std::cin.get () != '\n') {}

        std::cout << "Error. Enter again: ";
    }

    return temp;

}

void deleteMatrix(int** matrix, int n){
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    
}