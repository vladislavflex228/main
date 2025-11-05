#include "gtest/gtest.h" 
#include "massive_functions.h" 

TEST(CreateMassiveIndexTest, MultipleZeros) {
    int M = 3, N = 3;
    int** matrix = createMatrix(M, N);
    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 0;
    matrix[1][0] = 2; matrix[1][1] = 3; matrix[1][2] = 4;
    matrix[2][0] = 0; matrix[2][1] = 5; matrix[2][2] = 0;
    std::vector<std::pair<int, int>> indexes = createMassiveIndex(matrix, M, N);
    ASSERT_EQ(indexes.size(), 4);
    ASSERT_EQ(indexes[0].first, 0); ASSERT_EQ(indexes[0].second, 0);
    ASSERT_EQ(indexes[1].first, 0); ASSERT_EQ(indexes[1].second, 2);
    ASSERT_EQ(indexes[2].first, 2); ASSERT_EQ(indexes[2].second, 0);
    ASSERT_EQ(indexes[3].first, 2); ASSERT_EQ(indexes[3].second, 2);
    deleteMatrix(matrix, M, N);
}

TEST(CountNullsTest, EmptyMatrix) {
    int M = 0, N = 0;
    int** matrix = nullptr;
    ASSERT_EQ(countNulls(matrix, M, N), 0);
}

TEST(CountNullsTest, MultipleZeros) {
    int M = 3, N = 3;
    int** matrix = createMatrix(M, N);
    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 0;
    matrix[1][0] = 2; matrix[1][1] = 3; matrix[1][2] = 4;
    matrix[2][0] = 0; matrix[2][1] = 5; matrix[2][2] = 0;
    ASSERT_EQ(countNulls(matrix, M, N), 4);
    deleteMatrix(matrix, M, N);
}

TEST(ReverseMatrixTest, EmptyMatrix) {
    int M = 0, N = 0;
    int** matrix = nullptr;
    int** reversed = reverseMatrix(matrix, M, N);
    ASSERT_EQ(reversed, nullptr);
}

TEST(ReverseMatrixTest, TwoByTwoMatrix) {
    int M = 2, N = 2;
    int** matrix = createMatrix(M, N);
    matrix[0][0] = 1; matrix[0][1] = 2;
    matrix[1][0] = 3; matrix[1][1] = 4;
    int** reversed = reverseMatrix(matrix, M, N);
    ASSERT_NE(reversed, nullptr);
    ASSERT_EQ(reversed[0][0], 4);
    ASSERT_EQ(reversed[0][1], 3);
    ASSERT_EQ(reversed[1][0], 2);
    ASSERT_EQ(reversed[1][1], 1);
    deleteMatrix(matrix, M, N);
    deleteMatrix(reversed, M, N);
}

