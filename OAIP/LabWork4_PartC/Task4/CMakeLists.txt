cmake_minimum_required(VERSION 3.10)
project(MyProjectTest CXX)

# Ищем Google Test
find_package(GTest CONFIG REQUIRED)

# *** Добавьте эту строку! ***
include(GoogleTest) # <-- Эта строка включает необходимые функции для gtest_discover_tests

# Добавляем ваш тестируемый класс как библиотеку
add_library(funcTask4 funcTask4.cpp funcTask4.h)

# Создаем исполняемый файл для тестов
add_executable(testTask4 testTask4.cpp)

# Связываем исполняемый файл тестов с вашей библиотекой и Google Test
target_link_libraries(testTask4 PRIVATE funcTask4 GTest::gtest_main GTest::gtest)

# Включаем каталог с тестами в CTest (опционально, но полезно для автоматизации)
include(CTest)
gtest_discover_tests(testTask4)