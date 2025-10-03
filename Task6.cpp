#include <iostream>

#include <cmath>


using namespace std;

int main()
{
double x,p,K,D,C,A,B,Y;
cout<<"Введите число x = ";
cin>>x;
cout<<"Введите число p = ";
cin>>p;
cout<<"Введите число K = ";
cin>>K;
cout<<"Введите число D = ";
cin>>D;
cout<<"Введите число C = ";
cin>>C;

A = x + sin(p);
B = exp(K);

Y = 1 + (double)pow(K,2)/(2 *A * B) -B + D*C;

cout<<"Результат равен = "<<Y;

    return 0;
}