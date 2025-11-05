#include<iostream>
#include"massive_functions.h"

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

int*createMassive(int **matrix,int M,int N){
    int size = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(matrix[i][j]%2 == 1 && j%2 == 0){
                size++;
            }
        }
        
    }

    if(size == 0)
    {
        int* faikmassive = new int[1];
        faikmassive[0] = 1;
        return faikmassive;
        
        
    }
    else{
    
        int* massive = new int[size];
        int k = 0;
        for (int i = 0; i < M; i++)
        {
           for (int j = 0; j < N; j++)
           {
                if(matrix[i][j]%2 == 1 && j%2 == 0){
                    massive[k] = matrix[i][j];
                    k++;
                }
                else continue;

           }
           
        
        }

        return massive;
    }
}

void FillMatrix(int**massive,int n,int m){
    for (int i = 0; i < n; i++)
    {   
        for (int j = 0; j < m; j++)
        {
            long int a;
            massive[i][j] = checkInt(a);
        }
        
    }

}

void deleteMassive(int* massive,int n){
    delete[] massive;
}


int** createMatrix(int M,int N){
    int**matrix = new int*[M];
    for (int i = 0; i < M; i++)
    {
        matrix[i] = new int[N];
    }
    return matrix;

}

void deleteMatrix(int** matrix, int M,int N){
    for (int i = 0; i < N; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    
}


double averageMean(int*massive,int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += massive[i];
    }
    return sum/n;
    
}