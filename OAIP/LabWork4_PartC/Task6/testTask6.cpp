#include<gtest/gtest.h>
#include"funcTask6.h"

TEST(CheckMagickSum,MagisSquare3x3)
{
    int size = 3;
    int magic[size][size] = {
        {2,7,6},
        {9,5,1},
        {4,3,8}
    };
    int** myMagicSquare = (int**)malloc(size*sizeof(int *));
    
    for(int i = 0; i < size; i++)
    {
        myMagicSquare[i] = (int*)malloc(size*sizeof(int));
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            myMagicSquare[i][j] = magic[i][j];
        }
            
    }
    EXPECT_EQ(checkMagicSum(myMagicSquare,size),1);

    for(int i = 0; i < size; i++)
    {
        free(myMagicSquare[i]);
    }
    free(myMagicSquare);
}

TEST(CheckMagickSum,MagisSquare4x4)
{
    int size = 4;
    int magic[size][size] = {
        {16,3,2,13},
        {5,10,11,8},
        {9,6,7,12},
        {4,15,14,1}
    };
    int** myMagicSquare = (int**)malloc(size*sizeof(int *));
    
    for(int i = 0; i < size; i++)
    {
        myMagicSquare[i] = (int*)malloc(size*sizeof(int));
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            myMagicSquare[i][j] = magic[i][j];
        }
            
    }
    EXPECT_EQ(checkMagicSum(myMagicSquare,size),1);

    for(int i = 0; i < size; i++)
    {
        free(myMagicSquare[i]);
    }
    free(myMagicSquare);
}