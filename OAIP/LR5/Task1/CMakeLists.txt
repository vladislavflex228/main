cmake_minimum_required(VERSION 3.10)
project(MyProjectTest CXX)

# Ищем Google Test
find_package(GTest CONFIG REQUIRED)

# *** Добавьте эту строку! ***
include(GoogleTest) # <-- Эта строка включает необходимые функции для gtest_discover_tests

# Добавляем ваш тестируемый класс как библиотеку
add_library(matrix_functions matrix_functions.cpp matrix_functions.h)

# Создаем исполняемый файл для тестов
add_executable(testTask1 test_matrix_functions.cpp)

# Связываем исполняемый файл тестов с вашей библиотекой и Google Test
target_link_libraries(testTask1 PRIVATE matrix_functions GTest::gtest_main GTest::gtest)

# Включаем каталог с тестами в CTest (опционально, но полезно для автоматизации)
include(CTest)
gtest_discover_tests(testTask1)
