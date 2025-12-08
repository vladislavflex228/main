
#include "func.h" 

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    
    do {
        std::cout << "\n1. Перевод (Доп -> Обр)\n";
        std::cout << "2. Сложение двоичных\n";
        std::cout << "3. Системы счисления\n";
        std::cout << "4. Делимость (побитово)\n";
        std::cout << "5. Задача Патриция\n";
        std::cout << "0. Выход\n";
        std::cout << "Выбор: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Ошибка! Введите целое число.\n";
            choice = -1;
            continue;   
        }
    
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: Task1::run(); break;
            case 2: Task2::run(); break;
            case 3: Task3::run(); break;
            case 4: Task4::run(); break;
            case 5: Task5::run(); break;
            case 0: break;
            default: std::cout << "Ошибка!\n";
        }
    } while (choice != 0);

    return 0;
}
