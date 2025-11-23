#include"functions.h"

int main(){
    std::cout<<"Задание номер 1 Вариант 2,Выполнил Антонюк Владислав\n";

    std::cout<<"Суть задачи ввести строку из нулей и единиц,найти наименьюшую группу состояющую из нулей и единиц и вывести\n";

    for (bool repeat = 1; repeat ; repeat = read_repeat())
    {
        std::cout<<"Для начала надо ввести размер массива\n";
        
        int size;

        std::cin>>size;

        char* arr = readBinaryArrayDynamic(size);

        minArray(arr,size);

        std::cout<<"Требуемая строка: \n";

        for (int i = 0; i < size; i++)
        {
            std::cout<<arr[i]<<"\t";
        }

        delete[] arr;
    }



    return 0;
}