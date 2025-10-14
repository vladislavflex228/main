#include<iostream>
#include<cmath>
#include"check.h"




int main()
{
    std::cout << "Задание 8 \n Выполнил Антонюк Владислав Группа 553501\n";

    std::cout<<"Без использования арифметической арифметики и переполнения вычислить a0 -2a1 + ... +2^(n-1)(-1)^(n-1)a(n-1)\n";
for (bool repeat = 1; repeat; repeat = read_repeat())
{
    std::cout<<"Нам требуется ввести количество одночленов n \n";

    long long int n;

    checkInt0(n);

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        long int current;
        std::cout<<"Нам требуется текущий элемент \n";
        checkInt(current);

        if(i%2 == 0)
        {
            sum += std::pow(2,i) * current;
        }
        else
        {
            sum -= std::pow(2,i) * current;
        }
        std::cout<<"_______________________________"<<std::endl;
    }

    std::cout<<"Полученная сумма равна: "<<sum<<std::endl;

}


        return 0;
}