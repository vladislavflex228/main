#include<iostream>
#include"massive_functions.h"

int main()
{
    std::cout<<"2 Задание Вариант 2\nВыполнил Антонюк Владислав Группа 553501\n";
    std::cout<<"Рекурсивно проверить находятся ли числа в промежутках\n";
    for (bool repeat = 1; repeat; repeat = read_repeat())
    {
        std::cout<<"Введите размер массива: \n";
        int n;
        checkInt0(n);
        std::cout<<"Введите элементы массива: \n";
        int* massive = createMassive(n);
        FillMassive(massive,n);
        if(checkElements(massive,0,n - 1))
        {
            std::cout<<"Элементы находятся в заданном промежутке \n";
        }
        else{
            std::cout<<"Не все числа находятся в промежутке \n";
        }

        deleteMassive(massive,n);
        
    }


    return 0;
}