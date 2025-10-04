#include<iostream>
#include"check.h"
#include<cmath>


double countFunc(double &x)
{
    double sum = 1;       
    double term = 1;
    for (int i = 1; i < 20; i++)
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
    long int n;

    std::cout << "Введите количество n значений,которые мы хотим проверить: " << std::endl;

    checkInt(n);

    std::cout << "Теперь рассмотрим "<<n<<" чисел в промежутке от 0.1 до 1" << std::endl;

    std::cout << "________________________________" << std::endl;

    for (int i = 0; i < n; i++)
    {
        double x;
        checkDouble2(x);
        std::cout << "Число,полученное суммой ряда Тейлора: "<<countFunc(x)<<"\tЧисло,полученное стандартной библиотекой: " << (std::exp(x)+std::exp(-x))/2.0<<std::endl;
        std::cout << "________________________________" << std::endl;
    }

        return 0;
}