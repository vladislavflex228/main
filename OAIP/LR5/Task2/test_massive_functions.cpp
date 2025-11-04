#include "gtest/gtest.h" 
#include "massive_functions.h"


TEST(ArrayCheckerTest, AllElementsPassCondition) {
  
    int N = 8;
    int* A = new int[N]{-2, -1, 0, 1, 2, -1, 0, 1}; 
   

    ASSERT_TRUE(checkElements(A, 0, N - 1));

    delete[] A; 
}

TEST(ArrayCheckerTest, OneElementFailsCondition) {
    
    int N = 4;
    int* A = new int[N]{-3, 0, 1, 2}; 

    ASSERT_FALSE(checkElements(A, 0, N - 1));

    delete[] A;
}

TEST(ArrayCheckerTest, AnotherElementFailsCondition) {
   
    int N = 5;
    int* A = new int[N]{0, 1, 2, 3, 0}; 

    ASSERT_FALSE(checkElements(A, 0, N - 1));

    delete[] A;
}

TEST(ArrayCheckerTest, SingleElementPasses) {

    int N = 1;
    int* A = new int[N]{-1}; 
    ASSERT_TRUE(checkElements(A, 0, N - 1));
    delete[] A;
}