#include"funcTask2.h"




int CountNegativeNumbers(int *massive,int str,int col)

{
int count = 0;
for (int i = 0; i < str; i++)
{
    for (int j = i+1;j < col; j++)
    {
        if(massive[i * col + j] < 0 )
        {
            count++;
        }
    }
    
}

    return count;
}