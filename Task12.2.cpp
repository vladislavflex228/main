#include<iostream>
#include<cmath>


using namespace std;
int main()
{
double x,y,a,b,c,D;



cin>>a>>b>>c;

//Разделим обе части на x в квадрате и сгруппируем
y = x + (double)(1/x);//Сделаем замену
//Тогда наше уравнение придет к виду : a*y^2+b*y+(c−2a)=0,решаем квадратное относительно y

D = b*b - 4*a*(c-2*a);

double y1,y2;
if(D>=0)
{
y1 = (double)((-b + sqrt(D))/(2*a));
y2 = (double)((-b - sqrt(D))/(2*a));
}
else
{
cout<<"Решений нет "<<endl;
}

//Затем мы решаем уравнение x + 1/x = y(x^2 - xy + 1)

double x1,x2;
D = y1*y1 - 4;

if(D>=0)
{
    x1 = (double)((y1 + sqrt(D))/2);
    x2 = (double)((y1 - sqrt(D))/2);
    cout<<"Корни x1,x2 равны = "<<x1<<" и "<<x2<<endl;
}
else
{
    cout<<"Корней в случае  y = y1  нет ";
}

double x3,x4;
D = y2*y2 - 4;

if(D>=0)
{
    x3 = (double)((y2 + sqrt(D))/2);
    x4 = (double)((y2 - sqrt(D))/2);
    cout<<"Корни x3,x4 равны = "<<x3<<" и "<<x4<<endl;
}
else
{
    cout<<"Корней в случае  y = y2  нет ";
    
}




    return 0;
}