#include"massive_functions.h"

double checkDouble(double &value) {
  
    while (true) {
        std::cout << "Введите число: ";
        if ( (std::cin >> value) && (std::cin.peek() == '\n') ) 
        {
            
         
            return value;
        } 
        else 
        {
            std::cout << "Нужны только числа типа double без пробелов\n";
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

int** createMatrix(int M,int N){
    int**matrix = new int*[M];
    for (int i = 0; i < M; i++)
    {
        matrix[i] = new int[N];
    }
    return matrix;

}

void FillMatrix(int**massive,int n,int m){
    for (int i = 0; i < n; i++)
    {   
        for (int j = 0; j < m; j++)
        {
            double a;
            massive[i][j] = checkDouble(a);
        }
        
    }

}

void deleteMatrix(int** matrix, int M,int N){
    for (int i = 0; i < N; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    
}

std::vector<std::pair<int,int>> createMassiveIndex(int** matrix,int n,int m){
    std::vector<std::pair<int,int>> indexes;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(matrix[i][j] == 0){
                std::pair<int,int> index = {i,j};
                indexes.push_back(index);
            }
        }
        
    }
    return indexes;
}

long long countNulls(int** matrix,int n,int m){
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(matrix[i][j] == 0){
                count++;
            }
        }
        
    }
    return count;

}

int** reverseMatrix(int** matrix,int m,int n){
    if(matrix == nullptr){
        return nullptr;
    }
    int** reverseMatrix = createMatrix(m,n);
    if(reverseMatrix == nullptr){
        return nullptr;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            reverseMatrix[m - i - 1][n - j - 1] = matrix[i][j];
        }
        
    }
    return reverseMatrix;
}

