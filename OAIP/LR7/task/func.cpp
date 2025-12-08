#include"func.h"

namespace Task1 {
    bool isValidBinary(const std::string& s) {
        if (s.empty()) return false;
        
        if (s.find(' ') != std::string::npos) return false;
        
        for (char c : s) {
            if (c != '0' && c != '1') return false;
        }
        return true;
    }

    std::string convertAdditionalToInverse(std::string binNum) {
        if (binNum[0] == '0') return binNum; 
        
        for (int i = binNum.length() - 1; i >= 0; i--) {
            if (binNum[i] == '1') {
                binNum[i] = '0';
                break; 
            } else {
                binNum[i] = '1';
            }
        }
        return binNum;
    }

    void run() {
        std::cout << "\n--- ЗАДАНИЕ 1 ---\n";
        
        std::string inputStr;
        while (true) {
            std::cout << "Введите число (доп. код): ";
            std::getline(std::cin, inputStr);
            
            if (isValidBinary(inputStr)) break;
            
            std::cout << "Ошибка! Вводите только '0' и '1' без пробелов.\n";
        }

        std::string result = convertAdditionalToInverse(inputStr);
        std::cout << "Результат (обр. код): " << result << std::endl;
        if (inputStr[0] == '0') std::cout << "(Число положительное)\n";
        else std::cout << "(Число отрицательное)\n";
    }
}

namespace Task2 {
    
    bool isValidBinary(const std::string& s) {
        if (s.empty()) return false;
        if (s.find(' ') != std::string::npos) return false;
        for (char c : s) {
            if (c != '0' && c != '1') return false;
        }
        return true;
    }

    std::string invertBits(std::string s) {
        std::string res = s;
        for (size_t i = 1; i < res.length(); i++) {
            res[i] = (res[i] == '0' ? '1' : '0');
        }
        return res;
    }

    std::string addOne(std::string s) {
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '0') { s[i] = '1'; break; }
            else { s[i] = '0'; }
        }
        return s;
    }

    std::string directToAdditional(std::string s) {
        if (s[0] == '0') return s; 
        return addOne(invertBits(s));
    }

    std::string additionalToDirect(std::string s) {
        if (s[0] == '0') return s; 
        std::string temp = s;
        for (int i = temp.length() - 1; i >= 0; i--) {
            if (temp[i] == '1') { temp[i] = '0'; break; }
            else { temp[i] = '1'; }
        }
        return invertBits(temp);
    }

    std::string addBinary(std::string a, std::string b) {
        size_t maxLen = std::max(a.length(), b.length());
        std::string padA(maxLen - a.length(), a[0]);
        std::string padB(maxLen - b.length(), b[0]);
        a = padA + a;
        b = padB + b;

        std::string res = "";
        int carry = 0;
        for (int i = a.length() - 1; i >= 0; i--) {
            int bitA = a[i] - '0';
            int bitB = b[i] - '0';
            int sum = bitA + bitB + carry;
            res += std::to_string(sum % 2);
            carry = sum / 2;
        }
        std::reverse(res.begin(), res.end());
        return res; 
    }

    void run() {
        std::cout << "\n--- ЗАДАНИЕ 2 ---\n";
        std::string s1, s2;

        while (true) {
            std::cout << "Число 1: ";
            std::getline(std::cin, s1);
            if (isValidBinary(s1)) break;
            std::cout << "Ошибка! Только '0' и '1' без пробелов.\n";
        }

        while (true) {
            std::cout << "Число 2: ";
            std::getline(std::cin, s2);
            if (isValidBinary(s2)) break;
            std::cout << "Ошибка! Только '0' и '1' без пробелов.\n";
        }

        std::string add1 = directToAdditional(s1);
        std::string add2 = directToAdditional(s2);
        
        std::string sumAdd = addBinary(add1, add2);
        std::string resDirect = additionalToDirect(sumAdd);

        std::cout << "Сумма (Доп): " << sumAdd << std::endl;
        std::cout << "Ответ (Прямой): " << resDirect << std::endl;
    }
}

namespace Task3 {
    int charToInt(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
        if (c >= 'a' && c <= 'z') return c - 'a' + 10;
        return -1;
    }
    
    char intToChar(int v) {
        if (v >= 0 && v <= 9) return v + '0';
        if (v >= 10 && v <= 35) return v - 10 + 'A';
        return '?';
    }
    
    std::string removeLeadingZeros(std::string s) {
        size_t first_nonzero = s.find_first_not_of('0');
        if (std::string::npos == first_nonzero) return "0";
        return s.substr(first_nonzero);
    }
    

    bool isValidStringForBase(const std::string& s, int base) {
        if (s.empty()) return false;
        
        
        if (s.find(' ') != std::string::npos) return false;

        size_t start = 0;
        if (s[0] == '-' || s[0] == '+') {
            if (s.length() == 1) return false; 
            start = 1;
        }
        if (s[start] == '0' && s.length() > start + 1) {
            return false;
        }

        for (size_t i = start; i < s.length(); i++) {
            int val = charToInt(s[i]);
            if (val == -1 || val >= base) return false;
        }
        return true;
    }


    int inputStrictBase() {
        std::string baseStr;
        while (true) {
            std::cout << "Введите основание (2-36): ";
            std::getline(std::cin, baseStr);
            
            if (baseStr.empty()) {
                std::cout << "Ошибка! Пустой ввод.\n";
                continue;
            }
            if (baseStr.find(' ') != std::string::npos) {
                std::cout << "Ошибка! Пробелы запрещены.\n";
                continue;
            }
            if (baseStr.length() > 1 && baseStr[0] == '0') {
                std::cout << "Ошибка! Ведущие нули запрещены.\n";
                continue;
            }

            bool isNumber = true;
            long long tempBase = 0;
            for (char c : baseStr) {
                if (c < '0' || c > '9') {
                    isNumber = false;
                    break;
                }
                tempBase = tempBase * 10 + (c - '0');
            }

            if (!isNumber) {
                std::cout << "Ошибка! Только цифры.\n";
                continue;
            }

            if (tempBase < 2 || tempBase > 36) {
                std::cout << "Ошибка! Диапазон от 2 до 36.\n";
                continue;
            }

            return (int)tempBase;
        }
    }

    std::string inputStrictNumber(int base, const std::string& prompt) {
        std::string num;
        while (true) {
            std::cout << prompt;
            std::getline(std::cin, num);
            
            if (isValidStringForBase(num, base)) {
                return num;
            }
            
            std::cout << "Ошибка! Недопустимый ввод (проверьте пробелы, нули и алфавит).\n";
            std::cout << "Допустимо: 0-" << (base <= 10 ? (char)('0' + base - 1) : '9');
            if (base > 10) std::cout << ", A-" << (char)('A' + base - 11);
            std::cout << std::endl;
        }
    }
    
    bool isAbsGreater(std::string a, std::string b) {
        if (a.length() > b.length()) return true;
        if (a.length() < b.length()) return false;
        return a > b;
    }
    
    std::string coreAdd(std::string n1, std::string n2, int base) {
        std::string res = "";
        int i = n1.length() - 1, j = n2.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int v1 = (i >= 0) ? charToInt(n1[i]) : 0;
            int v2 = (j >= 0) ? charToInt(n2[j]) : 0;
            int sum = v1 + v2 + carry;
            carry = sum / base;
            res += intToChar(sum % base);
            i--; j--;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
    
    std::string coreSub(std::string n1, std::string n2, int base) {
        std::string res = "";
        int i = n1.length() - 1, j = n2.length() - 1, borrow = 0;
        while (i >= 0) {
            int v1 = charToInt(n1[i]);
            int v2 = (j >= 0) ? charToInt(n2[j]) : 0;
            int diff = v1 - v2 - borrow;
            if (diff < 0) { diff += base; borrow = 1; } else borrow = 0;
            res += intToChar(diff);
            i--; j--;
        }
        std::reverse(res.begin(), res.end());
        return removeLeadingZeros(res);
    }
    
    std::string addInBase(std::string n1, std::string n2, int base);
    std::string subInBase(std::string n1, std::string n2, int base);

    std::string addInBase(std::string n1, std::string n2, int base) {
        if (n1[0] == '+') n1 = n1.substr(1);
        if (n2[0] == '+') n2 = n2.substr(1);

        bool neg1 = (n1[0] == '-'), neg2 = (n2[0] == '-');
        std::string abs1 = neg1 ? n1.substr(1) : n1;
        std::string abs2 = neg2 ? n2.substr(1) : n2;
        
        if (neg1 == neg2) {
            std::string res = coreAdd(abs1, abs2, base);
            return neg1 ? "-" + res : res;
        } else {
            if (isAbsGreater(abs1, abs2)) {
                std::string res = coreSub(abs1, abs2, base);
                return (res == "0") ? "0" : (neg1 ? "-" + res : res);
            } else {
                std::string res = coreSub(abs2, abs1, base);
                return (res == "0") ? "0" : (neg2 ? "-" + res : res);
            }
        }
    }
    
    std::string subInBase(std::string n1, std::string n2, int base) {
        if (n2[0] == '-') return addInBase(n1, n2.substr(1), base);
        else if (n2[0] == '+') return addInBase(n1, "-" + n2.substr(1), base);
        else return addInBase(n1, "-" + n2, base);
    }

    void run() {
        std::cout << "\n--- ЗАДАНИЕ 3 ---\n";
    
        int base = inputStrictBase();
        
        std::string n1 = inputStrictNumber(base, "Число 1: ");
        std::string n2 = inputStrictNumber(base, "Число 2: ");
        
        std::cout << "Сумма:    " << addInBase(n1, n2, base) << std::endl;
        std::cout << "Разность: " << subInBase(n1, n2, base) << std::endl;
    }
}

namespace Task4 {
    int bitNegate(int x) { return ~x + 1; }
    int bitSub(int a, int b) { return a + bitNegate(b); }
    
    
    bool isValidDecimal(const std::string& s) {
        if (s.empty()) return false;
        
        
        if (s.find(' ') != std::string::npos) return false;

        size_t start = 0;
        if (s[0] == '-') {
            if (s.length() == 1) return false; 
            start = 1;
        }

        if (s[start] == '0' && s.length() > start + 1) return false;

        for (size_t i = start; i < s.length(); i++) {
            if (s[i] < '0' || s[i] > '9') return false;
        }
        return true;
    }

    int bitMod(int n, int d) {
        int rem = 0;
        for (int i = 30; i >= 0; i = bitSub(i, 1)) {
            rem = rem << 1;
            int bit = (n >> i) & 1;
            rem = rem + bit;
            int diff = bitSub(rem, d);
            if (((diff >> 31) & 1) == 0) rem = diff;
        }
        return rem;
    }
    
    bool isDivisible(std::string numStr, int divisor) {
        int rem = 0;
        int minusCharZero = bitNegate('0');
        size_t i = (numStr[0] == '-') ? 1 : 0;
        for (; i < numStr.length(); i++) {
            int digit = numStr[i] + minusCharZero;
            int currentVal = (rem << 3) + (rem << 1) + digit;
            rem = bitMod(currentVal, divisor);
        }
        return (rem == 0);
    }
    
    void run() {
        std::cout << "\n--- ЗАДАНИЕ 4 ---\n";
        std::string num;
        
        while (true) {
            std::cout << "Введите число: ";
            std::getline(std::cin, num);
            
            if (isValidDecimal(num)) break;
            
            std::cout << "Ошибка! Введите целое число (без пробелов, без ведущих нулей 007).\n";
        }

        int primes[] = {5, 47, 89};
        for (int p : primes) {
            std::cout << "На " << p << ": " << (isDivisible(num, p) ? "ДА" : "НЕТ") << std::endl;
        }
    }
}

namespace Task5 {

    
    std::vector<int> barrelToScheme(int barrelIndex) {
        std::vector<int> scheme(5, 0);
        int temp = barrelIndex;
        for (int i = 0; i < 5; i++) {
            scheme[i] = temp % 3;
            temp /= 3;
        }
        return scheme;
    }

    int schemeToBarrel(const std::vector<int>& states) {
        int idx = 0, p = 1;
        for (int i : states) { idx += i * p; p *= 3; }
        return idx;
    }

    
    void clearScreen() {
        for(int i = 0; i < 50; i++) std::cout << "\n";
    }

    
    void sleep(int ms) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    
    void waitEnter() {
        std::cout << "\n[Нажмите Enter, чтобы продолжить...]";
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    
    bool parseStrictInt(const std::string& s, int& outVal, int min, int max) {
        if (s.empty()) return false;
        if (s.find(' ') != std::string::npos) return false;
        if (s.length() > 1 && s[0] == '0') return false;
        long long temp = 0;
        for (char c : s) {
            if (c < '0' || c > '9') return false;
            temp = temp * 10 + (c - '0');
            if (temp > max) return false;
        }
        if (temp < min) return false;
        outVal = (int)temp;
        return true;
    }

    
    int inputInt(const std::string& prompt, int min, int max) {
        std::string s;
        int val;
        while (true) {
            std::cout << prompt;
            std::getline(std::cin, s);
            if (parseStrictInt(s, val, min, max)) return val;
            std::cout << " >> Ошибка! Введите число от " << min << " до " << max << " (без пробелов).\n";
        }
    }
    
    void printBarrelArt() {
        std::cout << "      _______\n";
        std::cout << "     (_______)\n";
        std::cout << "    /         \\\n";
        std::cout << "   |   VINO    |\n";
        std::cout << "   |  ROMANO   |\n";
        std::cout << "    \\_________/\n";
    }

    void printSkullArt() {
        std::cout << "      _____ \n";
        std::cout << "     /     \\ \n";
        std::cout << "    | () () | \n";
        std::cout << "     \\  ^  /  \n";
        std::cout << "      |||||   \n";
    }

    
    void playPoisoner() {
        clearScreen();
        std::cout << "=== РЕЖИМ: ОТРАВИТЕЛЬ ===\n\n";
        std::cout << "Вы пробрались в погреб Патриция.\n";
        std::cout << "Перед вами 240 бочек с лучшим вином империи.\n";
        std::cout << "У вас есть один флакон с ядом.\n";
        
        printBarrelArt();

        int barrel = inputInt("\nВ какую бочку подсыпать яд? (1-240): ", 1, 240);
        
        std::cout << "\nВы аккуратно открываете бочку №" << barrel << ", выливаете яд и скрываетесь в тени...\n";
        waitEnter();

        std::cout << "Патриций обнаружил следы взлома!\n";
        std::cout << "Он вызывает 5 рабов. Начинается дегустация по Троичной Системе...\n";
        
        std::vector<int> scheme = barrelToScheme(barrel - 1);
        
    
        clearScreen();
        std::cout << "--- ДЕНЬ ПЕРВЫЙ ---\n";
        std::cout << "Рабы пьют вино согласно схеме...\n";
        sleep(2000);
        
        std::cout << "\nНаступает ночь. Тишина...\n";
        bool day1Death = false;
        for(int i=0; i<5; i++) {
            if(scheme[i] == 1) {
                std::cout << "Крик в ночи! Раб №" << i+1 << " падает замертво!\n";
                day1Death = true;
            }
        }
        if(!day1Death) std::cout << "Все рабы пережили первую ночь.\n";
        
        waitEnter();

    
        std::cout << "\n--- ДЕНЬ ВТОРОЙ ---\n";
        std::cout << "Выжившие рабы (те, кто не пил вчера яд) продолжают дегустацию...\n";
        sleep(2000);
        
        std::cout << "\nПроходит еще 24 часа...\n";
        bool day2Death = false;
        for(int i=0; i<5; i++) {
            if(scheme[i] == 2) {
                std::cout << "Раб №" << i+1 << " начинает кашлять и умирает!\n";
                day2Death = true;
            }
        }
        if(!day2Death) std::cout << "Больше никто не умер.\n";
        
        waitEnter();

    
        clearScreen();
        printSkullArt();
        std::cout << "\n--- ФИНАЛ ---\n";
        std::cout << "Патриций смотрит на трупы и сверяется с папирусом.\n";
        std::cout << "Патриций: 'Математика не врет! Яд в бочке №" << barrel << "!'\n";
        std::cout << "Вас схватила стража. Game Over.\n";
        waitEnter();
    }

    
    void playDetective() {
        clearScreen();
        std::cout << "=== РЕЖИМ: ДЕТЕКТИВ ===\n\n";
        std::cout << "Патриций в панике! Завтра пир, а вино может быть отравлено.\n";
        std::cout << "Вы провели эксперимент с 5 рабами. Прошло 48 часов.\n";
        std::cout << "Стражник зачитывает вам доклад о состоянии рабов.\n";
        
        std::vector<int> states(5);
        
        for(int i = 0; i < 5; i++) {
            std::cout << "\n--------------------------------\n";
            std::cout << "ДОКЛАД ПО РАБУ №" << i+1 << ":\n";
            std::cout << "Что с ним случилось?\n";
            std::cout << "  0 - Жив и здоров\n";
            std::cout << "  1 - Умер в ПЕРВЫЙ день\n";
            std::cout << "  2 - Умер во ВТОРОЙ день\n";
            
            states[i] = inputInt("Ваш вердикт (0-2): ", 0, 2);
            
            if(states[i] > 0) std::cout << " >> Записано: Раб №" << i+1 << " мертв.\n";
            else std::cout << " >> Записано: Раб №" << i+1 << " жив.\n";
        }

        waitEnter();
        
        clearScreen();
        int result = schemeToBarrel(states) + 1;
        
        std::cout << "Вы берете перо и проводите вычисления...\n";
        std::cout << "3^0 * " << states[0] << " + 3^1 * " << states[1] << "...\n";
        sleep(2000);
        
        printBarrelArt();
        if (result > 240) {
            std::cout << "\nВЫВОД: Бочка №" << result << "...\n";
            std::cout << "Постойте! У нас всего 240 бочек.\n";
            std::cout << "Похоже, стражник ошибся в докладе, или рабы умерли от страха.\n";
        } else {
            std::cout << "\nВЫВОД: Яд находится в бочке №" << result << "!\n";
            std::cout << "Патриций спасен! Вы получаете мешок золота.\n";
        }
        waitEnter();
    }

    void run() {
        while(true) {
            clearScreen();
            std::cout << "==========================================\n";
            std::cout << "    ЗАГАДКА ПАТРИЦИЯ: ВИНО И ЯД\n";
            std::cout << "==========================================\n";
            std::cout << "Выберите свою роль:\n";
            std::cout << "1. ОТРАВИТЕЛЬ (Симуляция: я загадываю бочку)\n";
            std::cout << "2. ДЕТЕКТИВ   (Решение: я ввожу исходы)\n";
            std::cout << "0. Вернуться в главное меню\n";
            std::cout << "==========================================\n";
            
            int choice = inputInt("Ваш выбор: ", 0, 2);
            
            if (choice == 0) break;
            if (choice == 1) playPoisoner();
            if (choice == 2) playDetective();
        }
    }
}