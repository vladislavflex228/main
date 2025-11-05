#include"massive_functions.h"

int main(){
    std::cout<<"Задание 4 выполнил Антонюк Владислав группа 553501\n";

    std::cout<<"Дан двумерный динамический массив,размеры вводятся с клавиатуры,сохранить пару индексов нулевых элементов,их количество и вывести с развернутым массивом\n";
for (bool repeat = 1; repeat; repeat = read_repeat())
{

    int M,N;
    
    std::cout<<"Нужны размеры M,N массива: \n";

    checkInt0(M);

    checkInt0(N);

    int** matrix = createMatrix(M,N);

    std::cout<<"Введите элементы массива руками: \n";

    FillMatrix(matrix,M,N);

    std::vector<std::pair<int,int>> indexes = createMassiveIndex(matrix,M,N);

    long long count = countNulls(matrix,M,N);

    int** reverse_matrix = reverseMatrix(matrix,M,N);
    if(indexes.empty())
    {
        std::cout<<"К сожалению таких элементов нет: \n";
    }
    else{
        std::cout<<"Наши индексы: \n";
        for (auto it:indexes)
        {
            std::cout<<it.first<<' '<<it.second<<'\n';
        }
    }
    
 
    std::cout<<"Количество нулевых элементов равно: "<<count<<'\n';

    std::cout<<"Наш перевернутый массив: \n";

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout<<std::setw(4)<<reverse_matrix[i][j];
        }
        std::cout<<std::endl;
        
    }
    
    deleteMatrix(matrix,M,N);

    deleteMatrix(reverse_matrix,M,N);


}
    return 0;

}