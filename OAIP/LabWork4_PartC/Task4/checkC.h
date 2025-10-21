#ifndef CHECKC_H
#define CHECKC_H

#include <cstdio>    // Для std::printf, std::fprintf, std::fgets, stdin, stderr
#include <cstdlib>   // Для std::strtol
#include <cctype>    // Для std::isspace
#include <cstring>   // Для std::strcspn
#include <climits>   // Для INT_MAX, INT_MIN (эти макросы часто остаются глобальными)
#include<cstdbool>

int get_natural_number_c(int *value_ptr);


#endif