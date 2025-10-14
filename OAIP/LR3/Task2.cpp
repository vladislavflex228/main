#include<iostream>
#include"check.h"

int main()
{
    std::cout<<"Задание 2\nВыполнил Антонюк Владислав Группа 553501\n";
    std::cout<<"Программа находит сумму ряда Dn=1/2^n+1/3^n с точностью до eps=10^-3\n";

    for (bool repeat = 1; repeat; repeat = read_repeat())
    {
        long double sum = 0;
        long double term = 0;
        double a = 2;
        double b = 3;

        do
        {
            term = 1/a+1/b;
            sum+=term;
            a*=2;
            b*=3;
        } while(term>0.001);
        std::cout<<"Cумма ряда равна: "<<sum<<std::endl;

    }

    return 0;
}