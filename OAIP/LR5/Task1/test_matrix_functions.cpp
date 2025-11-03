#include "gtest/gtest.h" // Подключаем Google Test
#include "matrix_functions.h" // Подключаем ваш заголовочный файл

// Тестовый набор для функции sumMainDiagonal
TEST(SumMainDiagonalTest, BasicInput) {
    int n = 3;
    int** matrix = createMatrix(n);
    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
    matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
    matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9;

    long long expected_sum = 1 + 5 + 9; 
    long long actual_sum = sumMainDiagonal(matrix, n);

    EXPECT_EQ(expected_sum, actual_sum); 

    deleteMatrix(matrix, n);
}

// Краевой тест 1: Матрица размером 1x1
TEST(SumMainDiagonalTest, EdgeCase_1x1Matrix) {
    int n = 1;
    int** matrix = createMatrix(n);
    matrix[0][0] = 10;

    long long expected_sum = 10;
    long long actual_sum = sumMainDiagonal(matrix, n);

    EXPECT_EQ(expected_sum, actual_sum);

    deleteMatrix(matrix, n);
}

// Краевой тест 2: Матрица с отрицательными числами
TEST(SumMainDiagonalTest, EdgeCase_NegativeNumbers) {
    int n = 2;
    int** matrix = createMatrix(n);

    // Матрица:
    // -1  -2
    // -3  -4
    matrix[0][0] = -1; matrix[0][1] = -2;
    matrix[1][0] = -3; matrix[1][1] = -4;

    long long expected_sum = -1 + (-4);
    long long actual_sum = sumMainDiagonal(matrix, n);

    EXPECT_EQ(expected_sum, actual_sum);

    deleteMatrix(matrix, n);
}

TEST(SumMainDiagonalTest, EdgeCase_ZeroMatrix) {
    int n = 2;
    int** matrix = createMatrix(n);


    matrix[0][0] = 0; matrix[0][1] = 0;
    matrix[1][0] = 0; matrix[1][1] = 0;

    long long expected_sum = 0;
    long long actual_sum = sumMainDiagonal(matrix, n);

    EXPECT_EQ(expected_sum, actual_sum);

    deleteMatrix(matrix, n);
}

TEST(SumMainDiagonalTest, EdgeCase_LargeNumbers) {
    int n = 5;
    int** matrix = createMatrix(n);


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = 0; 
        }
        matrix[i][i] = 1000000000; 
    }

    long long expected_sum = (long long)n * 1000000000; 
    long long actual_sum = sumMainDiagonal(matrix, n);

    EXPECT_EQ(expected_sum, actual_sum);

    deleteMatrix(matrix, n);
}
