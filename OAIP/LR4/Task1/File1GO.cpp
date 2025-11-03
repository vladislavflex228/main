#include<iostream>
#include"Task1.h"
#include"check.h"

int main()
{
    std::cout<<"1 Задание Вариант 2\nВыполнил Антонюк Владислав Группа 553501\n";
    std::cout<<"Вводится статический массивчик размера 8 и переворачивается\n";
    std::cout<<"_____________________________________________\n";
    for (bool repeat = 1; repeat; repeat = read_repeat())
    {
    
        const int size = 8;
    

        std::cout<<"_____________________________________________\n";


        int MyMassive[size];

        std::cout<<"Теперь ручками введем элементы массива: \n";
        for (int i = 0; i < size; i++)
        {
            long int curr;
            MyMassive[i] = checkInt(curr);
        }
        std::cout<<"__________________________________________\n";

        std::cout<<"Получаем массив: ";
        for (int i = 0; i < size; i++)
        {
            std::cout<<MyMassive<<' ';
        }
        
        std::cout<<"\n";

        reverse_massive_in_place(MyMassive,size);


        std::cout<<"Получаем новый массив: ";
        for (int i = 0; i < size; i++)
        {
            std::cout<<MyMassive[i]<<' ';
        }
    

    }
    return 0;
}
