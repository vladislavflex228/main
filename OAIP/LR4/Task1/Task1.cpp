  
#include"Task1.h"


void reverse_massive_in_place(int* arr,const int size) {
    if (arr == nullptr || size <= 0) 
    {
        
        return;
    }
    std::reverse(arr, arr + size);
}

