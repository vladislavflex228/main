#include"funcTask6.h"

int checkMagicSum(int **sq, int n) {
    long long magicSum = 0;
    for(int j = 0; j < n; j++) magicSum += sq[0][j];
    int ok = 1;
    int *seen = (int*)malloc((n * n + 1)*sizeof(int)); // Массив для отслеживания чисел от 1 до n^2
    if (!seen) {
        printf("Ошибка выделения памяти.\n");
        return -1;
    }
    for (int i = 1; i < n*n + 1; i++)
    {
        seen[i] = 0; 
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(sq[i][j] < 0 || sq[i][j] > n*n || seen[sq[i][j]] == 1)
            {
                ok = 0;
            }
            else
            {
                seen[sq[i][j]] = 1;
            }
        }
        
    }
    
    for(int i = 1; i < n && ok; i++) {
        long long s = 0;
        for(int j = 0; j < n; j++) {s += sq[i][j];}
        if (s != magicSum) ok = 0;
    }
    for(int j = 0; j < n && ok; j++) {
        long long s = 0;
        for(int i = 0; i < n; i++) {s += sq[i][j];}
        if (s != magicSum) ok = 0;
    }
   for(int i = 0; i< n && ok; i++) {
        long long s = 0;
        for (int j = 0; j < n; j++)
        {
            s += sq[j][j];
        }
        
        if (s != magicSum) ok = 0;
    }
    
    for(int i = 0; i< n && ok; i++) {
        long long s = 0;
        for (int j = 0; j < n; j++)
        {
            s += sq[j][n - j - 1];
        }
        
        if (s != magicSum) ok = 0;
    }
    

    if (ok == 1) {return 1;}
    else {return 0;}

}