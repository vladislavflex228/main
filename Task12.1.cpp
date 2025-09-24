#include<cmath>
#include<iostream>

using namespace std;

int main()
{
double a,b,c,D,x1,x2,x3,x4,q,p;
cout<<"Введите число а = ";
cin>>a;
cout<<"Введите число b = ";
cin>>b;
cout<<"Введите число c = ";
cin>>c;

D = b*b - 4*a*c;

if(D<0)
{
    cout<<"Вещественных решений нет";
}
else
{
q = (double)((-b + sqrt(D))/(2*a));
p = (double)((-b - sqrt(D))/(2*a));
if(q < 0 && p < 0)
{
    cout<<"Вещественных решений нет";
}
else
{
if(q>0)
{
    x1 = +sqrt(q);
    x2 = -sqrt(q);
    cout<<"Первых два корня уравнения равны = "<<x1<<" и "<<x2<<endl;
}    
else if(q == 0)
{
    x1 = x2 = 0;
    cout<<"Первых два корня уравнения равны нулю"<<endl;
}

if(p>0)
{
    x3 = +sqrt(p);
    x4 = -sqrt(p);
    cout<<"Последних два корня уравнения равны = "<<x3<<" и "<<x4<<endl;
}    
else if(p == 0)
{
    x3 = x4 = 0;
    cout<<"Последних два корня уравнения равны нулю"<<endl;
}
}
}

    return 0;
}