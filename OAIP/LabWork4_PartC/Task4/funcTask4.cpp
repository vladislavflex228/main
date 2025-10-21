#include"funcTask4.h"

int maxDiagonalOfMatrix(int***arr,int size)
{

int* number = (int*)malloc(4*sizeof(int));
memset(number,0,4*sizeof(int));

for (int i = 0; i < size; i++)
{
    number[0] += arr[i][i][i];
    number[1] += arr[i][i][size - i - 1];
    number[2] += arr[i][size-i - 1][i];
    number[3] += arr[size - i - 1][i][i];
}

int max = number[0];

for (int i = 0; i < 3; i++)
{
    if(number[i]< number[i+1])
    {
        max = number[i+1];
    }
}


free(number);

return max;

}