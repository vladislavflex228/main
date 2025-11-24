#include"functions.h"

int main() {
    std::locale utf8_locale("ru_RU.UTF-8");
    std::locale::global(utf8_locale);; // включаем поддержку UTF-8/локали
    std::wcin.imbue(utf8_locale);
    std::wcout.imbue(utf8_locale);

    std::wcout<<L"Задание номер 3 Вариант 2,Выполнил Антонюк Владислав\n";

    std::wcout<<L"Если в строке встречена последовательность одинаковых символов, заменить их кодом 255, за которым следует код этого символа и количество одинаковых символов \n";
    
    for (bool repeat = 1; repeat; repeat = read_repeat())
    {
        int n;
        std::wcout << L"Введите количество строк: ";
        
        checkInt0(n);

        while (std::wcin.get() != L'\n'); 

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