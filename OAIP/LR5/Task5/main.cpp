#include"massive_functions.h"


int main(){
std::cout<<"Задание 5 выполнил Антонюк Владислав группа 553501\n";

std::cout<<"Дан двумерный динамический массив,размеры и элементы вводятся с клавиатуры,создать массив из элементов с нечетным значением расположенных на четных столбцах,найти среднее арифмитическое,вывести\n";


for (int repeat = 1; repeat; repeat = read_repeat())
{
    int M,N;
    std::cout<<"Введите размеры: ";
    checkInt0(M);
    checkInt0(N);
    int** matrix = createMatrix(M,N);
    FillMatrix(matrix,M,N);
    int* massive = createMassive(matrix,M,N);

    if(massive[0] == 1){
        std::cout<<"Мишаня,все фигня,давай по новой \n";
        deleteMassive(massive,1);
    }
    else{
        int size = 0;
        for (int i = 0; i < M; i++)
        {
           for (int j = 0; j < N; j++)
           {
            if(matrix[i][j]%2 == 1 && j%2 == 0){
                size++;
            }
            else continue;
           }
           
        }

        for (int i = 0; i < size; i++)
        {
            std::cout<<std::setw(4)<<massive[i];
        }
        std::cout<<'\n';
        std::cout<<"Среднее арифмитическое чисел полученного массива равно: "<<averageMean(massive,size)<<'\n';

        deleteMassive(massive,size);
    
    }
    deleteMatrix(matrix,M,N);


}
    return 0;
}