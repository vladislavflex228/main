#include<iostream>
#include<cmath>


int checkInt0(int &value)  //Проверка на натуральное число
{
    

    while (true) {
        std::cout << "Введите число: ";
        if ( (std::cin >> value) && (std::cin.peek() == '\n') && (value > 0) && (value < 1000000)) 
        {
            
            std::cout << "Вы ввели число: " << value << std::endl;
            return value;
        } 
        else 
        {
            std::cout << "Нужны только натуральные числа не превосходящие миллиона без пробелов\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}







int main()
{
    std::cout << "Задание 7 \n Выполнил Антонюк Владислав Группа 553501\n";

    std::cout<<"Найти все числа Армстронга меньшие введенного числа \n";
    int value;
    checkInt0(value);

    for (int i = 0; i < value; i++)
    {
        double sum = 0;
        double numbers_of_i;
        int k = 0;
        while(true)
        {
            
            if(i >= std::pow(10,k))
            {
                k++;
            }
            else
            {
                numbers_of_i = k;
                break;
            }
        }
        for (double j = 0; j < numbers_of_i; j++)
        {
           int divisor1 = static_cast<int>(std::pow(10, j + 1));
           int divisor2 = static_cast<int>(std::pow(10, j));
           int remainder = i % divisor1 / divisor2 ;
           double number = static_cast<double>(remainder);

           sum += std::pow(number,numbers_of_i);
        }
        if(sum == i)
        {
            std::cout<<"Число Армстронга: "<< i <<std::endl;
        }
        
    }
    



    return 0;
}