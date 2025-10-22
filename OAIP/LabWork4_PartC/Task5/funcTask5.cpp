#include"funcTask5.h"

char** MineSweeper(char** massive,int rows,int cols)
{
    char ** newmassive = (char**)malloc(((rows) + 2) * sizeof(char*));
    for (int i = 0; i < rows + 2; i++)
    {
        newmassive[i] = (char*)malloc((cols +2) * sizeof(char));
    }

    for (int i = 1; i < rows + 1; i++)
    {
        for (int j = 1; j < cols + 1; j++)
        {
            newmassive[i][j] = massive[i - 1][j - 1];
        }
        
    }

    for (int i = 1; i < rows + 1; i++)
    {
        newmassive[i][0] == '.';
        newmassive[i][cols + 1] == '.';
    
    }
    
    for (int i = 0; i < cols + 2; i++)
    {
        newmassive[0][i] == '.';
        newmassive[rows +1][i] == '.';
    }

    for (int i = 1; i < rows + 1; i++)
    {
        for (int j = 1; j < cols + 1; j++)
        {
            if(newmassive[i][j] == '#')continue;
            else
            {
                int cnt = 0;
                cnt += (newmassive[i-1][j] == '#');
                cnt += (newmassive[i-1][j -1] == '#');
                cnt += (newmassive[i - 1][j + 1] == '#');
                cnt += (newmassive[i][j - 1] == '#');
                cnt += (newmassive[i][j + 1] == '#');
                cnt += (newmassive[i + 1][j] == '#');
                cnt += (newmassive[i + 1][j - 1] == '#');
                cnt += (newmassive[i + 1][j + 1] == '#');
                if(cnt == 0)
                {
                    newmassive[i][j] = '.';
                }
                else
                {
                    newmassive[i][j] = '0' + cnt; // cnt автоматически преобразуется к номеру таблицы затем к символу соответсв
                }
            }
        }
        
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            massive[i][j] = newmassive[i + 1][j + 1];
        }
        
    }

    for (int i = 0; i < rows + 2; i++)
    {
        free(newmassive[i]);
    }
    free(newmassive);

    return massive;
    

}