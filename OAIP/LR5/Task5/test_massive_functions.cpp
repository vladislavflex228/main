#include"massive_functions.h"
#include "gtest/gtest.h"


TEST(CreateMassiveTest, HandlesEmptyMatrix) {
    int M = 0;
    int N = 0;
    int** matrix = createMatrix(M, N); 

    int* result_massive = createMassive(matrix, M, N);

 
    ASSERT_NE(result_massive, nullptr); 
    ASSERT_EQ(result_massive[0], 1);   

    deleteMassive(result_massive, 1); 
    deleteMatrix(matrix, M, N);
}

TEST(CreateMassiveTest, CorrectlyExtractsMultipleElements) {
    int M = 3;
    int N = 3;
    int** matrix = createMatrix(M, N);

    matrix[0][0] = 11; 
    matrix[1][0] = 2;  
    matrix[2][0] = 13; 
    matrix[0][1] = 1;
    matrix[1][1] = 2;
    matrix[2][1] = 3;
    matrix[0][2] = 4;  
    matrix[1][2] = 17; 
    matrix[2][2] = 19; 

    int* result_massive = createMassive(matrix, M, N);

    ASSERT_NE(result_massive, nullptr);
    
    ASSERT_EQ(result_massive[0], 11);
    ASSERT_EQ(result_massive[1], 17);
    ASSERT_EQ(result_massive[2], 13);
    ASSERT_EQ(result_massive[3], 19);

    deleteMassive(result_massive, 4); 
    deleteMatrix(matrix, M, N);
}


TEST(CreateMassiveTest, ReturnsFaikMassiveWhenNoMatchingElements) {
    int M = 2;
    int N = 2;
    int** matrix = createMatrix(M, N);

    matrix[0][0] = 2; 
    matrix[0][1] = 3; 
    matrix[1][0] = 4; 
    matrix[1][1] = 5; 

    int* result_massive = createMassive(matrix, M, N);

    ASSERT_NE(result_massive, nullptr);
    ASSERT_EQ(result_massive[0], 1);

    deleteMassive(result_massive, 1);
    deleteMatrix(matrix, M, N);
}


