#include<iostream>
#include"check.h"
#include<cmath>

int main()
{
    std::cout << "Задание 5 - 2 вариант\n Выполнил Антонюк Владислав Группа 553501\n";
        
    std::cout << "Пользователь вводит число n частей на которые мы делим заданный интервал,начиная с минимального значения";
    std::cout << "и проверяет через шаг 1/n значения в полученных икс, находим Х,при котором значение минимально,выводим значение \n";
    for (bool repeat = 1; repeat; repeat = read_repeat())
    {
        long long int n;
        checkInt0(n);
        
        double step = 2.0/(double)n; // (4.0-2.0)/n
        double x = 2.0;
        double minX = x;
        double y = std::log(minX) + 3 * std::tan(minX) + std::sqrt(minX);
        double minY = std::abs(y);

        while(x < 4.0)
        {
            x += step;
            double currentY = std::log(x) + 3 * std::tan(x) + std::sqrt(x);
            if(minY > std::abs(currentY))
            {
                minX = x;
                minY = std::abs(currentY);
            }

        }

        std::cout<<"Наш корень равен: "<<minX<<std::endl;
    }

    return 0;
}