#include<iostream>
#include"check.h"
#include"func.h"

int main()
{
    std::cout << "Задание 6 \n Выполнил Антонюк Владислав Группа 553501\n";

    std::cout<<"Вычислить значения функций sin(x),cos(x),ln(|x|) в введенном значении х т найти наименьший из них\n";
for (bool repeat = 1; repeat; repeat = read_repeat()) 
{
    std::cout<<"Для начала выберем x \n";

    double x;
    checkDouble0(x);

    double a = sin(x);
    double b = cos(x);
    double c = log(abs(x));

    double minVal = a;
    if (b < minVal) 
    {
        minVal = b;
    }
    else if(c < minVal) 
    {
        minVal = c;
    }

    std::cout << "Минимальное значение: " << minVal << std::endl;

}

    return 0;
}