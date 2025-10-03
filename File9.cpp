#include<iostream>
#include<cmath>

using namespace std;

int main()
{
double x,y,z,F,a,b;

int N,K;

cout<<"Введите z = ";
cin>>z;
cout<<"Введите N = ";
cin>>N;
cout<<"Введите a = ";
cin>>a;
cout<<"Введите b = ";
cin>>b;

if(z <1)
{
    x = 2 + z;
}
else
{
    x = pow(sin(z),2);
}

K = N%3;

switch(K)
{
case 1:
{
    F = 2 * x;
break;
}
case 2:
{
 F = pow(x,3);
 break;
}
case 3:
{
    F = (double)(x/3);
    break;
}
default:
break;
}


y = (double)((2*a*F + b*cos(sqrt(fabs(x))))/(pow(x,2)+5));

cout<<"Конечное значение y = "<<y<<endl;
    return 0;
}
