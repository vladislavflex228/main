#include<iostream>

using namespace std;
int main()
{
double X,Y;
cout<<"Введите число X = ";
cin>>X;
cout<<"Введите число Y = ";
cin>>Y;

bool IsXGreater = (X>Y);

double max = IsXGreater ? X : Y;

cout<<"Максимальное число равно = "<<max;


}