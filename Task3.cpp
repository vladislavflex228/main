#include <iostream>

int main()
{
double b1,q,sum;
int n;
std::cout<<"Введите ваш номер в журнале = ";
std::cin>>n;

std::cout<<"Введите первый член БГП = ";
std::cin >>b1;

q = (double)1/(n+1);

sum = (double)b1/(1-q);

std::cout<<"Сумма БГП равна = " <<sum;

}