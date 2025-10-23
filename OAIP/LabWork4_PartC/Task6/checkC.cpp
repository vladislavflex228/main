#include "checkC.h"


int get_natural_number_c(int *value_ptr) {
    char buffer[100]; // Буфер для чтения строки ввода
    long temp_value;  // Используем long для strtol, чтобы избежать переполнения при чтении
    char *endptr;     // Указатель на первый непреобразованный символ

    while (true) { // Бесконечный цикл
        printf("Введите число: ");

        // Читаем строку из stdin
        if (fgets(buffer, sizeof(buffer), stdin) == nullptr) {
         
            printf("Ошибка чтения ввода,повторите попытку\n");

            continue; 
        }

 
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) == 0) {
            printf("Магический квадрат существует для n>=2.Введите именно такое натуральное число\n");
            continue; 
        }

        temp_value = strtol(buffer, &endptr, 10);

        if (*endptr == '\0' && temp_value > 2 && temp_value < 30000) {
            *value_ptr = (int)temp_value;
            return *value_ptr;            
        } else {
           
            printf("Магический квадрат существует для n>=2.Введите именно такое натуральное число\n");
            
        }
    }
}

int repeat_c(int *value_ptr)
{
    char buffer[100]; // Буфер для чтения строки ввода
    long temp_value;  // Используем long для strtol, чтобы избежать переполнения при чтении
    char *endptr;     // Указатель на первый непреобразованный символ

    while (true) { // Бесконечный цикл
        printf("Хотите повторить программу? (ДА = 1; НЕТ = 0): ");

        // Читаем строку из stdin
        if (fgets(buffer, sizeof(buffer), stdin) == nullptr) {
         
            printf("Ошибка чтения ввода,повторите попытку\n");

            continue; 
        }

 
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) == '\0') {
            printf("Зачем вы просто нажали enter,введите 1 или 0\n");
            continue; 
        }

        temp_value = strtol(buffer, &endptr, 10);

        if (*endptr == '\0' && (temp_value == 0 || temp_value == 1)) {
            *value_ptr = (int)temp_value;
            return *value_ptr;            
        } else {
           
            printf("Нажмите либо 0,либо 1\n");
            
        }
    }


}


/*
int read_int_safe(const char* prompt, int* value) {
    char buffer[100]; // Объявление массива символов (строки)
    char* endptr;     // Объявление указателя на символ

    while (1) { // Бесконечный цикл, который будет продолжаться, пока не получим корректный ввод
        printf("%s", prompt); // Вывод подсказки

        // --- 1. fgets ---
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            fprintf(stderr, "Ошибка чтения ввода.\n");
            return 0; // Возврат 0 (ложь) при ошибке
        }

        // --- 2. strcspn ---
        buffer[strcspn(buffer, "\n")] = 0;

        // --- 3. strtol ---
        long int temp_val = strtol(buffer, &endptr, 10);

        // --- 4. Проверки ---
        if (endptr == buffer) {
            printf("Ошибка: Введите число. '%s' не является числом.\n", buffer);
        } else if (temp_val > INT_MAX || temp_val < INT_MIN) {
            printf("Ошибка: Введенное число выходит за пределы диапазона int (от %d до %d).\n", INT_MIN, INT_MAX);
        } else {
            // --- 5. isspace ---
            while (*endptr != '\0' && isspace((unsigned char)*endptr)) {
                endptr++;
            }

            if (*endptr != '\0') {
                printf("Ошибка: Обнаружены нечисловые символы после числа. '%s' не является целым числом.\n", buffer);
            } else {
                *value = (int)temp_val; // Присвоение значения по указателю
                return 1; // Возврат 1 (истина) при успехе
            }
        }
    }
}
*/

