#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <thread> 
#include <chrono> 

namespace Task1 {
    bool isBinaryString(const std::string& s);
    std::string convertAdditionalToInverse(std::string binNum);
    void run();
}

namespace Task2 {
    std::string invertBits(std::string s);
    std::string addOne(std::string s);
    std::string directToAdditional(std::string s);
    std::string additionalToDirect(std::string s);
    std::string addBinary(std::string a, std::string b);
    void run();
}

namespace Task3 {
    int charToInt(char c);
    char intToChar(int v);
    std::string removeLeadingZeros(std::string s);
    bool isValidStringForBase(const std::string& s, int base);
    bool isAbsGreater(std::string a, std::string b);
    std::string coreAdd(std::string n1, std::string n2, int base);
    std::string coreSub(std::string n1, std::string n2, int base);
    int inputStrictBase();
    std::string inputStrictNumber(int base, const std::string& prompt);
    std::string addInBase(std::string n1, std::string n2, int base);
    std::string subInBase(std::string n1, std::string n2, int base);
    void run();
}

namespace Task4 {
    int bitNegate(int x);
    int bitSub(int a, int b);
    int bitMod(int n, int d);
    bool isDivisible(std::string numStr, int divisor);
    void run();
}

namespace Task5 {

    std::vector<int> barrelToScheme(int barrelIndex);
    int schemeToBarrel(const std::vector<int>& states);

    void clearScreen();
    void sleep(int ms);
    void waitEnter();

    bool parseStrictInt(const std::string& s, int& outVal, int min, int max);
    int inputInt(const std::string& prompt, int min, int max);

    void printBarrelArt();
    void printSkullArt();
    void playPoisoner();
    void playDetective();
    
    void run();
}
#endif