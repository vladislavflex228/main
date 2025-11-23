#include"functions.h"

const int MAX_LEN = 100;

wchar_t* readString(int &len) {
    wchar_t* arr = new wchar_t[MAX_LEN + 1];
    len = 0;
    std::wcin.getline(arr, MAX_LEN + 1);
    while (arr[len] != L'\0') len++;
    return arr;
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