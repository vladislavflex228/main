#include"checkC.h"
#include"funcTask5.h"


int main()
{
    srand(time(NULL));

    printf("5 Задание Вариант 2\nВыполнил Антонюк Владислав Группа 553501\n");
    printf("Вводится двумерный массив N*M заполняется минами ('#') и требуется заполнить массив цифрами или '.'(если рядом бомб нет)как в игре сапер\n");

    
    for (int go = 1; go == 1; go = repeat_c(&go))
    {
        printf("Введите число,соответсвующее количеству строк массива:\n");
            
        int n = get_natural_number_c(&n);
        
        printf("Введите число,соответсвующее количеству столбцов массива:\n");
            
        int m = get_natural_number_c(&m);
        
        char**arr = (char**)malloc(n*sizeof(char *));
        for (int i = 0; i < n; i++)
        {
            arr[i] = (char*)malloc(m*sizeof(char));
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = '$';
            }
            
        }
        
        for (int i = 0; i < rand() % ((m * n - 1) - (m*n)/4) + (m*n)/4; i++) //не менее 25% мин на доске
        {
            arr[rand()%n][rand()%m] = '#';
        }

        printf("Изначальная таблица : \n");


        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%c ",arr[i][j]);
            }
            printf("\n");
        }

        arr = MineSweeper(arr,n,m);


        printf("Конечная таблица : \n");


        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%c ",arr[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < n; i++)
        {
            free(arr[i]);
        }
        free(arr);
    }
    return 0;
    
}


