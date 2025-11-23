#include"functions.h"
#include <gtest/gtest.h>

TEST(ReplaceWordsTest, EmptyText) {
    char* res = replaceWords("", 3, "XYZ");
    EXPECT_STREQ(res, "");
    delete[] res;
}

TEST(ReplaceWordsTest, NoMatchingWords) {
    char* res = replaceWords("hi world test", 6, "ABC");
    EXPECT_STREQ(res, "hi world test");
    delete[] res;
}

TEST(ReplaceWordsTest, AllWordsMatch) {
    char* res = replaceWords("hi by my do", 2, "XX");
    EXPECT_STREQ(res, "XX XX XX XX");
    delete[] res;
}

TEST(ReplaceWordsTest, MixedWordLengths) {
    char* res = replaceWords("hi world test a", 2, "XX");
    EXPECT_STREQ(res, "XX world test a");
    delete[] res;
}

TEST(ReplaceWordsTest, ReplaceShorter) {
    char* res = replaceWords("abcd efgh", 4, "X");
    EXPECT_STREQ(res, "X X");
    delete[] res;
}

TEST(ReplaceWordsTest, ReplaceLonger) {
    char* res = replaceWords("hi ok", 2, "LONG");
    EXPECT_STREQ(res, "LONG LONG");
    delete[] res;
}

TEST(ReplaceWordsTest, ReplaceEmpty) {
    char* res = replaceWords("hi ok bye", 2, "");
    EXPECT_STREQ(res, "  bye");
    delete[] res;
}

TEST(ReplaceWordsTest, SingleWordMatch) {
    char* res = replaceWords("hello", 5, "world");
    EXPECT_STREQ(res, "world");
    delete[] res;
}

TEST(ReplaceWordsTest, SingleCharacterWord) {
    char* res = replaceWords("a b c", 1, "X");
    EXPECT_STREQ(res, "X X X");
    delete[] res;
}

TEST(ReplaceWordsTest, MultipleSeparators) {
    char* res = replaceWords("hi  ok\tbye\nend", 2, "XX");
    EXPECT_STREQ(res, "XX  XX\tbye\nend");
    delete[] res;
}
