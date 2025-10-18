#include "gtest/gtest.h"
#include "funcTask3.h" 

TEST(MatrixPowerComparisonTest1,Matrix3x3Power3)
{
    int size = 3;
    int power = 3;
    int**matrix = new int*[size];

    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = j + 1;
        }
        
    }
    int staticMatrix[size][size] = {
        {36,72,108},
        {36,72,108},
        {36,72,108}
    }; 

    raiseMatrixPower(matrix,size,power);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            EXPECT_EQ(matrix[i][j],staticMatrix[i][j]);
        }
        
    }
}

TEST(MatrixPowerComparisonTest2,Matrix3x3Power4)
{
    int size = 3;
    int power = 4;
    int**matrix = new int*[size];

    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = j + 1;
        }
        
    }
    int staticMatrix[size][size] = {
        {216,432,648},
        {216,432,648},
        {216,432,648}
    }; 
    raiseMatrixPower(matrix,size,power);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            EXPECT_EQ(matrix[i][j],staticMatrix[i][j]);
        }
        
    }
}

TEST(MatrixPowerComparisonTest3,Matrix3x3Power4)
{
    int size = 4;
    int power = 3;
    int**matrix = new int*[size];

    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = j + 1;
        }
        
    }
    int staticMatrix[size][size] = {
        {100,200,300,400},
        {100,200,300,300},
        {100,200,300,400},
        {100,200,300,400}
    }; 
    raiseMatrixPower(matrix,size,power);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            EXPECT_EQ(matrix[i][j],staticMatrix[i][j]);
        }
        
    }
}