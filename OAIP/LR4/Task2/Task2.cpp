#include"funcTask2.h"
#include"check.h"



int main()
{
    std::cout<<"2 Задание Вариант 2\nВыполнил Антонюк Владислав Группа 553501\n";
    std::cout<<"Вводится двумерный статический массив 3x3 и считается количество отрицательных элементов выше главной диагонали\n";

    for (bool repeat = 1; repeat; repeat = read_repeat())
    {
        const int str = 3;
        const int col = 3;
        std::cout<<"Теперь будем вводить руками элементы массива 3x3 \n";
        int massive[str][col];

        for(int i = 0; i < str; i++)
        {
            for (int j = 0; j < col; j++)
            {
                long int curr;
                
                
                massive[i][j] = checkInt(curr);

            }
            
        }

        int count = CountNegativeNumbers(&massive[0][0],str,col);

        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < col; j++)
            {
                std::cout<<massive[i][j]<<' ';
            }
            std::cout<<'\n';
        }
        

        std::cout<<"Количество отрицательных элементов массива равна: "<<count<<std::endl;


    }

        return 0;
}