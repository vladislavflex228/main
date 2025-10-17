#include <gtest/gtest.h>
#include "funcTask2.h"

TEST(CountNegativesTest, AboveMainDiagonal) {
    // Матрица 3x3
    // Главная диагональ: 1, 5, 9
    // Выше диагонали: -2, 3, -6
    const int rows = 3, cols = 3;
    int matrix[rows][cols] = {
        {1,  -2, 3},   // Выше диагонали: -2, 3
        {4,  5,  -6},  // Выше диагонали: -6
        {7,  8,  9}    // Выше диагонали: нет
    };
    
    int result = CountNegativeNumbers(&matrix[0][0], rows, cols);
    EXPECT_EQ(result, 2); // -2 и -6
}

TEST(CountNegativesTest, NoNegativesAboveDiagonal) {
    const int rows = 3, cols = 3;
    int matrix[rows][cols] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int result = CountNegativeNumbers(&matrix[0][0], rows, cols);
    EXPECT_EQ(result, 0);
}

TEST(CountNegativesTest, AllNegativesAboveDiagonal) {
    const int rows = 3, cols = 3;
    int matrix[rows][cols] = {
        {1,  -1, -2},  // Выше: -1, -2
        {4,  5,  -3},  // Выше: -3
        {7,  8,  9}    // Выше: нет
    };
    
    int result = CountNegativeNumbers(&matrix[0][0], rows, cols);
    EXPECT_EQ(result, 3);
}

TEST(CountNegativesTest, NonSquareMatrix) {
    // Прямоугольная матрица 2x3
    const int rows = 2, cols = 3;
    int matrix[rows][cols] = {
        {1, -2, 3},  // Выше: -2, -3
        {4, 5,  6}    // Выше: 6 (но 6 положительное)
    };
    
    int result = CountNegativeNumbers(&matrix[0][0], rows, cols);
    EXPECT_EQ(result, 2); // -2 и -3
}

TEST(CountNegativesTest, SingleElement) {
    const int rows = 1, cols = 1;
    int matrix[rows][cols] = {{-1}};
    
    int result = CountNegativeNumbers(&matrix[0][0], rows, cols);
    EXPECT_EQ(result, 0); // Нет элементов выше диагонали
}