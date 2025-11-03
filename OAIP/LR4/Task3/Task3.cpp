#include<iostream>
#include"funcTask3.h"
#include"check.h"

int main()
{

std::cout<<"3 Задание Вариант 2\nВыполнил Антонюк Владислав Группа 553501\n";
std::cout<<"Вводится динамический массив размера N на N и затем возводится в степень k по правилу матриц\n";
for(bool repeat = 1;repeat;repeat = read_repeat())
{
std::cout<<"Введите размер квадратной матрицы: \n";
int size;
checkInt0(size);

int**matrix = new int*[size];

for (int i = 0; i < size; i++)
{
    matrix[i] = new int[size];
}



std::cout<<"_____________________________________\n";
std::cout<<"Введем массив(матрицу)руками\n";
for (int i = 0; i < size; i++)
{
    for (int j = 0; j < size; j++)
    {
        long int element;
        matrix[i][j] = checkInt(element);
    }
    
}





std::cout<<"___________________________\n";
std::cout<<"Наша исходная матрица: \n";

for (int i = 0; i < size; i++)
{
    for (int j = 0; j < size; j++)
    {
        std::cout<<matrix[i][j]<<' ';
    }
    std::cout<<std::endl;
}



std::cout<<"____________________________________\n";
std::cout<<"Введите степень,в которую хотите вовзвести матрицу: \n";
int power;

checkInt0(power);

raiseMatrixPower(matrix,size,power);




for (int i = 0; i < size; i++)
{
    for (int j = 0; j < size; j++)
    {
        std::cout<<matrix[i][j]<<' ';
    }
    std::cout<<std::endl;
}
std::cout<<"___________________________\n";
std::cout<<"Полученная матрица: \n";


for (int i = 0; i < size; i++)
{
    delete[] matrix[i];
}

delete[] matrix;


}

    return 0;
}