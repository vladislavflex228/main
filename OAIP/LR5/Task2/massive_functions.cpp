#include<iostream>
#include"massive_functions.h"

bool read_repeat () {

    bool temp;
    std::cout << "Wanna restart a program? (YES = 1; NO = 0): ";

    while (!(std::cin >> temp) || std::cin.peek() != '\n') {

        std::cin.clear ();
        while (std::cin.get () != '\n') {}

        std::cout << "Error. Enter again: ";
    }

    return temp;

}

int checkInt(long int &value) {
    while (true) {
        std::cout << "Введите число: ";
        if ( (std::cin >> value) && (std::cin.peek() == '\n') ) 
        {
            
        
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

int checkInt0(int &value) {
    while (true) {
        std::cout << "Введите число: ";
        if ( (std::cin >> value) && (std::cin.peek() == '\n') && (value > 0) && (value < 1000000)) 
        {
            
       
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

int*createMassive(int n){
    int* massive = new int[n];
    return massive;
}

void FillMassive(int*massive,int n){
    for (int i = 0; i < n; i++)
    {
        long int a;
        checkInt(a);
    }

}

void deleteMassive(int* massive,int n){
    delete[] massive;
}
bool checkElements(int* arr, int start, int end) {
    if (start == end) {

        int val = arr[start];

        long long valCubed = static_cast<long long>(val) * val * val;  //Обращаем внимание только на элементы массива и на их индексы,не выделыем дополнительно память для каких-то доп массивов

        return (valCubed > -10 && valCubed < 20);
    }
    int mid = start + (end - start) / 2;

    bool leftHalfOK = checkElements(arr, start, mid);

    bool rightHalfOK = checkElements(arr, mid + 1, end);

    return leftHalfOK && rightHalfOK;
}


/* 
g++ -c -fPIC massive_functions.cpp -o massive_functions_dyn.o
g++ -shared -o libmassivedynamic.so massive_functions_dyn.o
g++ main.cpp -L. -lmassivedynamic -o main_dynamic
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./main_dynamic

*/
