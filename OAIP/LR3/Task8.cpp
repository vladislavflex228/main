#include<iostream>
#include<cmath>


long long int checkInt0(long long int &value) {
    

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
long int checkInt(long int &value) {
    

    while (true) {
        std::cout << "Введите число: ";
        if ( (std::cin >> value) && (std::cin.peek() == '\n') ) 
        {
            
            std::cout << "Вы ввели число: " << value << std::endl;
            return value;
        } 
        else 
        {
            std::cout << "Нужны только целые числа без пробелов\n";
            std::cin.clear();
            std::cin.ignore(999, '\n');
        }
    }


}


int main()
{
    std::cout << "Задание 8 \n Выполнил Антонюк Владислав Группа 553501\n";

    std::cout<<"Без использования арифметической арифметики и переполнения вычислить a0 -2a1 + ... +2^(n-1)(-1)^(n-1)a(n-1)\n";

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




        return 0;
}