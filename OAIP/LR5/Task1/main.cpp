#include<iostream>
#include"matrix_functions.h"

int main()
{

    std::cout<<"1 Задание Вариант 2\nВыполнил Антонюк Владислав Группа 553501\n";
    std::cout<<"Сформировать два динамических массива,ввести их размеры с клавиатуры,посчитать сумму элементов на их главных диагоналях\n";
    for (bool repeat = 1; repeat; repeat = read_repeat())
    {
        int a,b;
        std::cout<<"Размер первого массива: \n";
        checkInt0(a);
        std::cout<<"Размер второго массива: \n";
        checkInt0(b);

        int** MatrixA = createMatrix(a);
        fillMatrixA(MatrixA,a);
        printMatrix(MatrixA,a,"Матрица А");
        long long diagA = sumMainDiagonal(MatrixA,a);
        std::cout<<"Сумма чисел на главной даигонали равна: "<<diagA<<'\n';
        deleteMatrix(MatrixA,a);

        int** MatrixB = createMatrix(b);
        fillMatrixB(MatrixB,b);
        printMatrix(MatrixB,b,"Матрица B");
        long long diagB = sumMainDiagonal(MatrixB,b);
        std::cout<<"Сумма чисел на главной даигонали равна: "<<diagB<<'\n';
        deleteMatrix(MatrixB,b);
    }

    return 0;
}