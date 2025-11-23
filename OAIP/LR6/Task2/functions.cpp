#include"functions.h"

char* readStringDynamic(int &len) {
    const int INIT_SIZE = 16;

    while (true) {
        int capacity = INIT_SIZE;
        char* arr = new char[capacity];
        len = 0;

        std::cout << "Введите непустую строку: ";
        int c = getchar();

        while (c == '\n' || c == '\r')  // пропускаем начальные переносы строк
            c = getchar();

        while (c != '\n' && c != '\r' && c != EOF) {
            if (len >= capacity) {  // расширяем массив при необходимости
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

        if (len == 0) {
            std::cout << "Ошибка: строка не может быть пустой. Попробуйте снова.\n";
            delete[] arr;
            continue;  // запрашиваем ввод заново
        }

        arr[len] = '\0';  // завершаем строку
        return arr;
    }
}

int checkInt0(int &value) {
    while (true) {
        std::cout << "Введите число: ";
        if ( (std::cin >> value) && (std::cin.peek() == '\n') && (value >= 0) && (value < 81)) 
        {
            return value;
        } 
        else 
        {
            std::cout << "Нужны только неотрицательные числа не превосходящие 80 без пробелов\n";
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

char* readReplaceNoSpaces(int &len) {
    const int INIT_SIZE = 16;
    int capacity = INIT_SIZE;
    char* arr = new char[capacity];
    len = 0;

    std::cout << "Введите строку для замены (не может быть пустой, без пробелов): ";
    int c = getchar();

    while (c == '\n' || c == '\r')  // пропуск начальных переносов
        c = getchar();

    while (c != '\n' && c != '\r' && c != EOF) {
        if (c == ' ') {
            std::cout << "Ошибка: пробелы запрещены. Попробуйте снова.\n";
            len = 0;
            delete[] arr;
            // очистка оставшегося ввода до конца строки
            while (c != '\n' && c != '\r' && c != EOF)
                c = getchar();
            return readReplaceNoSpaces(len); 
        }

        if (len >= capacity) {
            capacity *= 2;
            char* newArr = new char[capacity];
            for (int i = 0; i < len; i++)
                newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
        }

        arr[len++] = char(c);
        c = getchar();
    }

    arr[len] = '\0';
    return arr;
}


bool isDelimiter(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

char* replaceWords(char* text, int wordLen, char* replace) {
    int newCap = 64;
    char* newText = new char[newCap];
    int newLen = 0;

    int i = 0;
    while (text[i] != '\0') {
        if (isDelimiter(text[i])) {
            if (newLen + 1 >= newCap) {
                newCap *= 2;
                char* tmp = new char[newCap];
                for (int k = 0; k < newLen; k++)
                    tmp[k] = newText[k];
                delete[] newText;
                newText = tmp;
            }
            newText[newLen++] = text[i++];
            continue;
        }

        int start = i;
        int len = 0;
        while (text[i] != '\0' && !isDelimiter(text[i])) {
            i++;
            len++;
        }

        int insertLen = (len == wordLen) ? 0 : len;

        if (len == wordLen) {
            for (int k = 0; replace[k] != '\0'; k++)
                insertLen++;
        }

        while (newLen + insertLen >= newCap) {
            newCap *= 2;
            char* tmp = new char[newCap];
            for (int k = 0; k < newLen; k++)
                tmp[k] = newText[k];
            delete[] newText;
            newText = tmp;
        }

        if (len == wordLen) {
            for (int k = 0; replace[k] != '\0'; k++)
                newText[newLen++] = replace[k];
        } else {
            for (int k = start; k < start + len; k++)
                newText[newLen++] = text[k];
        }
    }

    newText[newLen] = '\0';
    return newText;
}