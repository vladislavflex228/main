#include <gtest/gtest.h>
#include "funcTask4.h"


TEST(MaxDiagonalOf3DMatrix,Size3Case1)
{
    int size = 3;
    int***matrix = (int***)malloc(size*sizeof(int**));
    for(int i = 0;i < size;i++)
    {
        matrix[i] = (int**)malloc(size*sizeof(int*));
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = (int*)malloc(size*sizeof(int));
        }
        
    }
    for (int i  = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                matrix[i][j][k] = i;
            }
            
        }
        
    }
    
    EXPECT_EQ(maxDiagonalOfMatrix(matrix,size),3);

}

TEST(MaxDiagonalOf3DMatrix,Size3Case2)
{
    int size = 3;
    int***matrix = (int***)malloc(size*sizeof(int**));
    for(int i = 0;i < size;i++)
    {
        matrix[i] = (int**)malloc(size*sizeof(int*));
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = (int*)malloc(size*sizeof(int));
        }
        
    }
    for (int i  = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                matrix[i][j][k] = i * j;
            }
            
        }
        
    }
    
    EXPECT_EQ(maxDiagonalOfMatrix(matrix,size),5);




}

TEST(MaxDiagonalOf3DMatrix,Size4Case)
{
    int size = 4;
    int***matrix = (int***)malloc(size*sizeof(int**));
    for(int i = 0;i < size;i++)
    {
        matrix[i] = (int**)malloc(size*sizeof(int*));
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = (int*)malloc(size*sizeof(int));
        }
        
    }
    for (int i  = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                matrix[i][j][k] = i * j;
            }
            
        }
        
    }
    
    EXPECT_EQ(maxDiagonalOfMatrix(matrix,size),13);




}