#include<iostream>
#include"check.h"
#include<cmath>


double countFunc(double &x,long int &num_of_members)
{
    double sum = 1;       
    double term = 1;
    for (int i = 1; i < num_of_members; i++)
    {
        term *= (x * x)/((2 * i - 1) * 2 * i);
        sum += term;
    }

return sum;
}

int main()
{
    std::cout << "Задание 4 - 2 вариант\n Выполнил Антонюк Владислав Группа 553501\n";
    
    std::cout << "Пользователь вводит n чисел; Программа находит значения функции, используя ряд Тейлора,\nа затем сравнивает их со значениями (exp^x + exp^(-x))/2 из стандартной библиотеки.\n";
   
   for (bool repeat = 1; repeat; repeat = read_repeat()) 
   {
        long int num_of_members;

        std::cout << "Введите количество элементов ряда Тейлора: " << std::endl;

        checkInt(num_of_members);

        std::cout << "Введите количество значений,которые мы хотим проверить: " << std::endl;

        long int num_of_data;

        checkInt(num_of_data);

        std::cout << "Теперь рассмотрим "<<num_of_data<<" чисел в промежутке от 0.1 до 1" << std::endl;

        std::cout << "________________________________" << std::endl;

        for (int i = 0; i < num_of_data; i++)
        {
            double x;
            checkDouble2(x);
            std::cout << "Число,полученное суммой ряда Тейлора: "<<countFunc(x,num_of_members)<<"\tЧисло,полученное стандартной библиотекой: " << (std::exp(x)+std::exp(-x))/2.0<<std::endl;
            std::cout << "________________________________" << std::endl;
        }
    }

        return 0;
}