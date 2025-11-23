#include"functions.h"

int main(){
    std::cout<<"Задание номер 2 Вариант 2,Выполнил Антонюк Владислав\n";

    std::cout<<"В тексте слова заданной длины заменить указанной подстрокой,длина которой может не совпадать с длиной слова \n";

    std::cout<<"Для начала введите размер начальной строки\n";

    int size;

    checkInt0(size);

    char * arr = readStringDynamic(size);

    std::cout<<"Теперь введите размер заменочной подстроки: \n";

    int size2;

    checkInt0(size2);

    char * replace = readReplaceNoSpaces(size2);

    int size3;

    std::cout<<"Наконец введите длину слов,которые надо менять: \n";

    checkInt0(size3);

    char * res = replaceWords(arr, size3, replace);

    std::cout<<"Результат: \n"<<res;





    return 0;
}