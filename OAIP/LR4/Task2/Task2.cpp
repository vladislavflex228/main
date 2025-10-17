#include"funcTask2.h"
#include"check.h"

const int MAX_SIZE = 100;

int main()
{
    std::cout<<"2 Задание Вариант 2\nВыполнил Антонюк Владислав Группа 553501\n";
    std::cout<<"Вводится двумерный массив MxN и считается количество отрицательных элементов\n";

    for (bool repeat = 1; repeat; repeat = read_repeat())
    {
        std::cout<<"Для начала введите количество строк и стобцов массива: \n";
        std::cout<<"Введите количество строк: \n";
        long int str;
        checkInt(str);
        std::cout<<"_______________________________________\n";
        std::cout<<"Введите количество столбцов: \n";
        long int col;
        checkInt(col);
        std::cout<<"_______________________________________\n";
        std::cout<<"Теперь будем вводить руками элементы массива MxN \n";
        int massive[MAX_SIZE][MAX_SIZE];

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