#include <gtest/gtest.h>
#include"functions.h"

TEST(MinArrayTest, SingleChar) {
    int len = 1;
    char* arr = new char[2]{'0', '\0'};

    minArray(arr, len);

    EXPECT_EQ(len, 1);
    EXPECT_STREQ(arr, "0");

    delete[] arr;
}

TEST(MinArrayTest, TwoSameChars) {
    int len = 2;
    char* arr = new char[3]{'1','1','\0'};

    minArray(arr, len);

    EXPECT_EQ(len, 2);
    EXPECT_STREQ(arr, "11");

    delete[] arr;
}

TEST(MinArrayTest, TwoDifferentChars) {
    int len = 2;
    char* arr = new char[3]{'0','1','\0'};

    minArray(arr, len);

    EXPECT_EQ(len, 1);
    EXPECT_TRUE(arr[0] == '0' || arr[0] == '1');
    EXPECT_EQ(arr[1], '\0');

    delete[] arr;
}

TEST(MinArrayTest, LongestSequenceAtStart) {
    int len = 6;
    char* arr = new char[7]{'1','1','1','0','1','0','\0'};

    minArray(arr, len);

    EXPECT_EQ(len, 3);
    EXPECT_STREQ(arr, "111");

    delete[] arr;
}

TEST(MinArrayTest, LongestSequenceAtEnd) {
    int len = 7;
    char* arr = new char[8]{'0','1','0','1','1','1','1','\0'};

    minArray(arr, len);

    EXPECT_EQ(len, 4);
    EXPECT_STREQ(arr, "1111");

    delete[] arr;
}

TEST(MinArrayTest, EqualMaxSequencesPickFirst) {
    int len = 10;
    char* arr = new char[11]{'0','0','1','1','1','0','0','1','1','1','\0'};

    minArray(arr, len);

    EXPECT_EQ(len, 3);
    EXPECT_STREQ(arr, "111");

    delete[] arr;
}

TEST(MinArrayTest, AllSameChars) {
    int len = 5;
    char* arr = new char[6]{'1','1','1','1','1','\0'};

    minArray(arr, len);

    EXPECT_EQ(len, 5);
    EXPECT_STREQ(arr, "11111");

    delete[] arr;
}

TEST(MinArrayTest, AlternatingPattern) {
    int len = 6;
    char* arr = new char[7]{'0','1','0','1','0','1','\0'};

    minArray(arr, len);

    EXPECT_EQ(len, 1);
    EXPECT_TRUE(arr[0] == '0' || arr[0] == '1');

    delete[] arr;
}

TEST(MinArrayTest, EdgeEqualSegments) {
    int len = 4;
    char* arr = new char[5]{'0','0','1','1','\0'};

    minArray(arr, len);

    EXPECT_EQ(len, 2);
    EXPECT_STREQ(arr, "00");

    delete[] arr;
}

TEST(MinArrayTest, OneCharBetweenLongerSegments) {
    int len = 7;
    char* arr = new char[8]{'1','1','1','0','0','0','0','\0'};

    minArray(arr, len);

    EXPECT_EQ(len, 4);
    EXPECT_STREQ(arr, "0000");

    delete[] arr;
}
