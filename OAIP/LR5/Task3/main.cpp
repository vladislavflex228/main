#include"massive_functions.h"


int main(){
std::cout<<"Задание 3 выполнил Антонюк Владислав группа 553501\n";

std::cout<<"Дан двумерный динамический массив,размеры вводятся с клавиатуры,создать массив из элементов главной даигонали имеющих четное значение и вывести\n";


for (int repeat = 1; repeat; repeat = read_repeat())
{
    int M,N;
    std::cout<<"Введите размеры: ";
    checkInt0(M);
    checkInt0(N);
    int** matrix = createMatrix(M,N);
    FillMatrix(matrix,M,N);
    int k = std::min(M,N);
    int* massive = createMassive(matrix,M);

    if(massive[0] == 1){
        std::cout<<"Мишаня,все фигня,давай по новой \n";
        deleteMassive(massive,1);
    }
    else{
        int size = 0;
        for (int i = 0; i < k; i++)
        {
            if(matrix[i][i]%2 == 0){
                size++;
            }
        }

        for (int i = 0; i < size; i++)
        {
            std::cout<<std::setw(4)<<massive[i];
        }
        std::cout<<'\n';
        std::cout<<"Произведение чисел полученного массива равно: "<<product(massive,size);

        deleteMassive(massive,size);
    
    }
    deleteMatrix(matrix,M,N);


}
    return 0;
}