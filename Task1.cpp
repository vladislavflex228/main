#include <iostream>

int main()
{
double x;

std::cin >> x;

double y = x*x;


double a = x*(23*y + 32);

double b = 69 *y + 8;

double sum = a+b;

double diff = b -a;

std::cout<< "Сумма равна "<<sum <<std::endl << "Разность равна "<<diff <<std::endl;

return 0;
}