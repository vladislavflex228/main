#include<iostream>
#include<cmath>

using namespace std;

int main()
{
double a,b,c,Y;
int N;


cout<<"Введите а ";
cin>>a;
cout<<"Введите b ";
cin>>b;
cout<<"Введите c ";
cin>>c;
cout<<"Введите N ";
cin>>N;

switch(N)
{
case(2):
Y = b * c - pow(a,2);
break;
case(56):
Y = b*c;
break;
case(7):
Y = pow(a,2) + c;
break;
case(3):
Y = pow(a+b,3);
break;
default:
break;


}
cout<<"Конечный результат равен "<<Y;
    return 0;
}