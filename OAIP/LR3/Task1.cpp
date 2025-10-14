#include<iostream>
#include"check.h"
int main()
{

    std::cout<<"1 Задание\nВыполнил Антонюк Владислав Группа 553501\n";
    std::cout<<"Находится сумма квадратов разности первых 30 элементов (Ai-Bi)*2, где:\n";
    std::cout<<"Ai=i, если i - четное, Ai=i/2, если нечетное\n";
    std::cout<<"Bi=i^2, если i - четное, Bi=i^3 -- нечетное\n";
    

    for (bool repeat = 1; repeat; repeat = read_repeat())
    {
        double Sum = 0;
        int i = 1;
        while (i <= 30) {
            double x = (i % 2) ? i : (i / 2);
            double y = (i % 2) ? i * i : i * i * i;
            Sum += (x - y) * (x - y);
            i++;
        }
        std::cout << "Сумма равна " << Sum << std::endl;
        
    }
}