#include"functions.h"

const int MAX_LEN = 100;

wchar_t* readString(int &len) {
    wchar_t buffer[105]; 
    int i = 0;
    wchar_t ch;
    
    while (i < 100 && (ch = std::wcin.get()) != L'\n' && ch != WEOF) {
        buffer[i++] = ch;
    }
    buffer[i] = L'\0';
    len = i;

    wchar_t* res = new wchar_t[len + 1];
    for (int k = 0; k <= len; k++) {
        res[k] = buffer[k];
    }
    return res;
}

wchar_t* compressString(const wchar_t* str, int len, int &newLen) {
    int cap = len * 3;
    wchar_t* res = new wchar_t[cap];
    newLen = 0;

    int i = 0;
    while (i < len) {
        wchar_t curr = str[i];
        int count = 1;
        while (i + count < len && str[i + count] == curr) {
            count++;
        }

        if (count > 1) {
            res[newLen++] = wchar_t(255); // маркер
            res[newLen++] = wchar_t(curr);
            res[newLen++] = wchar_t(count);
        } else {
            res[newLen++] = curr;
        }

        i += count;
    }

    return res;
}

void printCompressedString(const wchar_t* str, int len) {
    int i = 0;
    while (i < len) {
        if (str[i] == wchar_t(255) && i + 2 < len) {
            std::wcout << L"[255," << int(str[i + 1]) << L"," << int(str[i + 2]) << L"]";
            i += 3;
        } else {
            std::wcout << str[i];
            i++;
        }
    }
    std::wcout << std::endl;
}

bool compareArrays(const wchar_t* a, const wchar_t* b, int len) {
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

bool read_repeat () {

    bool temp;
    std::wcout << L"Wanna restart a program? (YES = 1; NO = 0): ";

    while (!(std::wcin >> temp) || std::wcin.peek() != L'\n') {

        std::wcin.clear ();
        while (std::wcin.get () != L'\n') {}

        std::wcout << L"Error. Enter again: ";
    }

    return temp;

}

int checkInt0(int &value) {
    while (true) {
        std::wcout << L"Введите число: ";
        if ( (std::wcin >> value) && (std::wcin.peek() == L'\n') && (value >= 0) && (value < 81)) 
        {
            return value;
        } 
        else 
        {
            std::wcout << L"Нужны только неотрицательные числа не превосходящие 80 без пробелов\n";
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
        }
    }
}