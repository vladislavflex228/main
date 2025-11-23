#include"functions.h"

int main() {
    std::locale::global(std::locale("")); // включаем поддержку UTF-8/локали
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());

    std::cout<<"Задание номер 3 Вариант 2,Выполнил Антонюк Владислав\n";

    std::cout<<"Если в строке встречена последовательность одинаковых символов, заменить их кодом 255, за которым следует код этого символа и количество одинаковых символов \n";
    
    for (bool repeat = 1; repeat; repeat = read_repeat())
    {
        int n;
        std::wcout << L"Введите количество строк: ";
        
        checkInt0(n);

        wchar_t** arr = new wchar_t*[n];
        int* lengths = new int[n];

        for (int i = 0; i < n; i++) {
            std::wcout << L"Строка " << i + 1 << L": ";
            arr[i] = readString(lengths[i]);
        }

        for (int i = 0; i < n; i++) {
            int newLen;
            wchar_t* compressed = compressString(arr[i], lengths[i], newLen);
            std::wcout << L"Сжатая строка " << i + 1 << L": ";
            printCompressedString(compressed, newLen);
            delete[] arr[i];
            delete[] compressed;
        }

        delete[] arr;
        delete[] lengths;
    }
    
    return 0;
}