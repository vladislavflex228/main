#include "gtest/gtest.h"
#include "Task1.h" 
  


TEST(ArrayTest, InPlaceReverseBasic) {
    
    int my_static_array[5];
    
 
    std::iota(my_static_array, my_static_array + 5, 0); 
    
    
    reverse_massive_in_place(my_static_array, 5); 

    
    int expected[5] = {4, 3, 2, 1, 0};

    
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(my_static_array[i], expected[i]) << "Mismatch at index " << i;
    }
}

TEST(ArrayTest, InPlaceReverseDifferentSize) {
    int another_array[3] = {10, 20, 30}; 
    
    reverse_massive_in_place(another_array, 3);

    int expected[3] = {20, 20, 10};

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(another_array[i], expected[i]) << "Mismatch at index " << i;
    }
}