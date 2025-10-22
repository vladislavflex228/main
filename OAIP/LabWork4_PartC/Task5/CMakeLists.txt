cmake_minimum_required(VERSION 3.10)
project(MyProjectTest CXX)

# Ищем Google Test
find_package(GTest CONFIG REQUIRED)

# *** Добавьте эту строку! ***
include(GoogleTest) # <-- Эта строка включает необходимые функции для gtest_discover_tests

# Добавляем ваш тестируемый класс как библиотеку
add_library(funcTask5 funcTask5.cpp funcTask5.h)

# Создаем исполняемый файл для тестов
add_executable(testTask5 testTask5.cpp)

# Связываем исполняемый файл тестов с вашей библиотекой и Google Test
target_link_libraries(testTask5 PRIVATE funcTask5 GTest::gtest_main GTest::gtest)

# Включаем каталог с тестами в CTest (опционально, но полезно для автоматизации)
include(CTest)
gtest_discover_tests(testTask5)