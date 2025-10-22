#include <gtest/gtest.h>
#include "funcTask5.h"

TEST(MineSweeperTest,Basic3x3)
{
    int n = 3;
    int m = 3;
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
    arr[1][2] = '#';
    arr[0][2] = '#';
    arr[2][1] = '#';
    arr[0][0] = '#';
    arr[1][1] = '#';
        
    char check[n][m] = {
        {'#','4','#'},
        {'3','#','#'},
        {'2','#','3'}
    };
    arr = MineSweeper(arr,n,m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            EXPECT_EQ(arr[i][j],check[i][j]);
        }
            
    }
        

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

}

TEST(MineSweeperTest,Basic4x4)
{
    int n = 4;
    int m = 4;
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
    arr[1][2] = '#';
    arr[0][2] = '#';
    arr[2][1] = '#';
    arr[0][0] = '#';
    arr[1][1] = '#';
        
    char check[n][m] = {
        {'#','4','#','2'},
        {'3','#','#','2'},
        {'2','#','3','1'},
        {'1','1','1','.'}
    };
    arr = MineSweeper(arr,n,m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            EXPECT_EQ(arr[i][j],check[i][j]);
        }
            
    }
        

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

}