#include <gtest/gtest.h>
#include "funcTask2.h"

TEST(CountNegativesTest, AboveMainDiagonal) {
   
    const int rows = 3, cols = 3;
    int matrix[rows][cols] = {
        {1,  -2, 3},   
        {4,  5,  -6},  
        {7,  8,  9}    
    };
    
    int result = CountNegativeNumbers(&matrix[0][0], rows, cols);
    EXPECT_EQ(result, 2); 
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
        {1,  -1, -2},  
        {4,  5,  -3},  
        {7,  8,  9}    
    };
    
    int result = CountNegativeNumbers(&matrix[0][0], rows, cols);
    EXPECT_EQ(result, 3);
}

TEST(CountNegativesTest, NonSquareMatrix) {
 
    const int rows = 2, cols = 3;
    int matrix[rows][cols] = {
        {1, -2, 3},  
        {4, 5,  6}    
    };
    
    int result = CountNegativeNumbers(&matrix[0][0], rows, cols);
    EXPECT_EQ(result, 2); 
}

TEST(CountNegativesTest, SingleElement) {
    const int rows = 1, cols = 1;
    int matrix[rows][cols] = {{-1}};
    
    int result = CountNegativeNumbers(&matrix[0][0], rows, cols);
    EXPECT_EQ(result, 0); 
}