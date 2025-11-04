#include "gtest/gtest.h" 
#include "massive_functions.h" 


TEST(CreateMassiveTest, OrdinaryCase_MixedEvenAndOdd) {
    int M = 3; 
    int N = 3; 
    
    int** initial_data_flat = createMatrix(M,N);
    initial_data_flat[0][0] = 2; initial_data_flat[0][1] = 2; initial_data_flat[0][2] = 3;
    initial_data_flat[1][0] = 4; initial_data_flat[1][1] = 6; initial_data_flat[1][2] = 7; 
    initial_data_flat[2][0] = 8; initial_data_flat[2][1] = 9; initial_data_flat[2][2] = 10; 

    int* result_massive = createMassive(initial_data_flat, M);

    ASSERT_NE(result_massive, nullptr); 
    ASSERT_EQ(result_massive[0], 2); 
    ASSERT_EQ(result_massive[1], 6); 
    ASSERT_EQ(result_massive[2], 10);

    delete[] result_massive;
    deleteMatrix(initial_data_flat,M,N);
}

TEST(CreateMassiveTest,KraevoyOne) {
    int M = 3;
    int N = 3; 
    int** initial_data_flat = createMatrix(M,N);
    
    initial_data_flat[0][0] = 1; initial_data_flat[0][1] = 2; initial_data_flat[0][2] = 3;
    initial_data_flat[1][0] = 4; initial_data_flat[1][1] = 5; initial_data_flat[1][2] = 7; 
    initial_data_flat[2][0] = 8; initial_data_flat[2][1] = 9; initial_data_flat[2][2] = 11; 
    

    int* result_massive = createMassive(initial_data_flat, M);


    ASSERT_NE(result_massive, nullptr); 
    ASSERT_EQ(result_massive[0], 1); 

    delete[] result_massive;
   deleteMatrix(initial_data_flat,M,N);
}

TEST(CreateMassiveTest, KraevoyTwo) {
    int M = 1;
    int N = 1;
    int** initial_data_flat = createMatrix(M,N);
    
    initial_data_flat[0][0] = 10; 

    int* result_massive = createMassive(initial_data_flat, M);
    ASSERT_NE(result_massive, nullptr); 
    ASSERT_EQ(result_massive[0], 10); 

    delete[] result_massive;
    deleteMatrix(initial_data_flat,M,N);
}