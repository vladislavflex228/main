#include <iostream>
#include <cmath>

using namespace std;

int main()
{
double p,q,D,u,v,x1,x2,x3;
cout<<"Введите число p = ";
cin>>p;

cout<<"Введите число q = ";
cin>>q;

//Будем решать формулой Кардано
D = pow((double)(q/2),2) + pow((double)(p/3),3);

u = cbrt((double)(-q/2)+sqrt(D));
v = cbrt((double)(-q/2)-sqrt(D));

if(D>=0)
{
x1 = u + v;
cout<<"Единственный действительный корень x = "<<x1;
}
else
{
double r,fi;
r = sqrt(-pow((double)(p/3),3));
fi = acos((double)(-q/(2*r)));
x1 = 2*sqrt((double)(-p/3))*cos((double)(fi/3));
x2 = 2*sqrt((double)(-p/3))*cos((double)((fi + 2*M_PI)/3));
x3 = 2*sqrt((double)(-p/3))*cos((double)((fi + 4*M_PI)/3));

cout<<"Три действительных корня равны = "<<x1 <<';'<<';'<< x2 <<';'<< x3<<endl;

}


    return 0;
}