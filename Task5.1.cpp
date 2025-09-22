#include<iostream>

using namespace std;
int main()
{
double X,Y;
cout<<"Введите число X = ";
cin>>X;
cout<<"Введите число Y = ";
cin>>Y;
double max;
if ( X>Y)
{
   max = X;
}
else
{
    max = Y;
}

cout<<"Максимальное число равно = "<< max;


}