#include"functions.h"


#include <iostream>
using namespace std;

char* readBinaryArrayDynamic(int &len) {
    const int INITIAL_SIZE = 16; // стартовый размер массива
    int capacity = INITIAL_SIZE;
    char* arr = new char[capacity];

    while (true) {
        cout << "Введите последовательность из 0 и 1: ";

        len = 0;
        int c = getchar();

        // пропускаем начальные переносы строк
        while (c == '\n' || c == '\r')
            c = getchar();

        bool bad = false;

        while (c != '\n' && c != '\r' && c != EOF) {

            // ❌ запрещаем пробелы и любые другие символы кроме '0' и '1'
            if (c != '0' && c != '1') {
                bad = true;

                // очистить остаток строки
                while (c != '\n' && c != EOF)
                    c = getchar();

                break;
            }

            // увеличить массив при необходимости
            if (len >= capacity) {
                capacity *= 2;
                char* newArr = new char[capacity];
                for (int i = 0; i < len; i++)
                    newArr[i] = arr[i];
                delete[] arr;
                arr = newArr;
            }

            arr[len++] = char(c);
            c = getchar();  // читаем следующий символ
        }

        if (bad) {
            cout << "Ошибка: вводите только символы 0 и 1. Пробелы запрещены.\n";
            continue;
        }

        if (len == 0) {
            cout << "Ошибка: пустая строка. Попробуйте снова.\n";
            continue;
        }

        arr[len] = '\0'; // завершаем C-строку
        return arr;
    }
}

int checkInt0(int &value) {
    while (true) {
        std::cout << "Введите число: ";
        if ( (std::cin >> value) && (std::cin.peek() == '\n') && (value > 0) && (value < 81)) 
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

char* minArray(char*&arr,int & len){
    int left = 0;
    int maxLeft = 0;
    int currLen = 1;
    int maxLen = 1;
    for (int i = 1; i < len; i++)
    {
        if(arr[i] == arr[i-1]){
            currLen++;
        }
        else{
            currLen = 1;
            left = i;
        }
        if(currLen > maxLen){
            maxLen = currLen;
            maxLeft = left;
        }
    }
    char * newArray = new char[maxLen + 1];
    for (int i = 0; i < maxLen; i++)
    {
        newArray[i] = arr[maxLeft + i];
    }
    newArray[maxLen] = '\0';
    delete[] arr;
    arr = newArray;
    len = maxLen;
    
    return arr;
}
