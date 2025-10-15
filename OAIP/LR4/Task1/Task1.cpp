  
#include"Task1.h"


void reverse_massive_in_place(int* arr, int size) {
    if (arr == nullptr || size <= 0) 
    {
        
        return;//завершить выполнение функции и вернуться к вызывающему коду
    }
    std::reverse(arr, arr + size);
}

