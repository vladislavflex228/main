#include<iostream>
#define PI 3.141592653
#include<cmath>
#include"check.h"

int main()
{
    std::cout<<"Задание 3\nВыполнял Антонюк Владислав Группа 553501\n";
    std::cout<<"Программа находит значение функции y = sin(x) - cos(x) на промежутке [A; B], где A = 0, B = pi/2, ";
    std::cout<<"с шагом H = (B-A)/M, где M = 20, используя цикл for\n";
    for (bool repeat = 1; repeat; repeat = read_repeat())
    {
        long double M = 20;
        long double A = 0;
        long double B = PI / 2;
        long double H = (B - A) / M;
        for (int i = 0; A +  static_cast<double>(i) * H <= B; i++)
        {
            long double x = A + static_cast<double>(i) * H;
            long double func = std::sin(x) - std::cos(x);
            std::cout<<"При Xi = A + H * i, где i = " << i<< ", y =  " << func << std::endl;
        }

    }
    return 0;
}