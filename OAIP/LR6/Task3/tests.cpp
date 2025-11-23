#include"functions.h"
#include <gtest/gtest.h>

TEST(CompressStringTest, EmptyString) {
    int newLen;
    wchar_t input[] = L"";
    wchar_t* result = compressString(input, 0, newLen);
    EXPECT_EQ(newLen, 0);
    delete[] result;
}

TEST(CompressStringTest, SingleChar) {
    int newLen;
    wchar_t input[] = L"a";
    wchar_t expected[] = {L'a'};
    wchar_t* result = compressString(input, 1, newLen);
    EXPECT_EQ(newLen, 1);
    EXPECT_TRUE(compareArrays(result, expected, newLen));
    delete[] result;
}

TEST(CompressStringTest, TwoRepeats) {
    int newLen;
    wchar_t input[] = L"aa";
    wchar_t expected[] = {255, (wchar_t)'a', 2};
    wchar_t* result = compressString(input, 2, newLen);
    EXPECT_EQ(newLen, 3);
    EXPECT_TRUE(compareArrays(result, expected, newLen));
    delete[] result;
}

TEST(CompressStringTest, MixedRepeatsAndSingles) {
    int newLen;
    wchar_t input[] = L"abbcccde";
    wchar_t expected[] = {
        L'a',
        255, (wchar_t)'b', 2,
        255, (wchar_t)'c', 3,
        L'd', L'e'
    };
    wchar_t* result = compressString(input, 8, newLen);
    EXPECT_EQ(newLen, 9);
    EXPECT_TRUE(compareArrays(result, expected, newLen));
    delete[] result;
}

TEST(CompressStringTest, AllSingles) {
    int newLen;
    wchar_t input[] = L"abcdef";
    wchar_t expected[] = {L'a', L'b', L'c', L'd', L'e', L'f'};
    wchar_t* result = compressString(input, 6, newLen);
    EXPECT_EQ(newLen, 6);
    EXPECT_TRUE(compareArrays(result, expected, newLen));
    delete[] result;
}

TEST(CompressStringTest, LongSequenceStart) {
    int newLen;
    wchar_t input[] = L"aaaaabc";
    wchar_t expected[] = {255, (wchar_t)'a', 5, L'b', L'c'};
    wchar_t* result = compressString(input, 7, newLen);
    EXPECT_EQ(newLen, 5);
    EXPECT_TRUE(compareArrays(result, expected, newLen));
    delete[] result;
}

TEST(CompressStringTest, LongSequenceEnd) {
    int newLen;
    wchar_t input[] = L"xyzzz";
    wchar_t expected[] = {L'x', L'y', 255, (wchar_t)'z', 3};
    wchar_t* result = compressString(input, 5, newLen);
    EXPECT_EQ(newLen, 5);
    EXPECT_TRUE(compareArrays(result, expected, newLen));
    delete[] result;
}

TEST(CompressStringTest, CyrillicRepeats) {
    int newLen;
    wchar_t input[] = L"ааабвввг";
    wchar_t expected[] = {255, L'а', 3, L'б', 255, L'в', 3, L'г'};
    wchar_t* result = compressString(input, 8, newLen);
    EXPECT_EQ(newLen, 8);
    EXPECT_TRUE(compareArrays(result, expected, newLen));
    delete[] result;
}

TEST(CompressStringTest, SpacesAndRepeats) {
    int newLen;
    wchar_t input[] = L"a  bb c";
    wchar_t expected[] = {L'a', 255, L' ', 2, 255, L'b', 2, L' ', L'c'};
    wchar_t* result = compressString(input, 7, newLen);
    EXPECT_EQ(newLen, 9);
    EXPECT_TRUE(compareArrays(result, expected, newLen));
    delete[] result;
}

TEST(CompressStringTest, SinglesAndPairs) {
    int newLen;
    wchar_t input[] = L"abccdeffg";
    wchar_t expected[] = {
        L'a', L'b',
        255, (wchar_t)'c', 2,
        L'd', L'e',
        255, (wchar_t)'f', 2,
        L'g'
    };
    wchar_t* result = compressString(input, 9, newLen);
    EXPECT_EQ(newLen, 11);
    EXPECT_TRUE(compareArrays(result, expected, newLen));
    delete[] result;
}
