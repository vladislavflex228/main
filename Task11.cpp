#include<iostream>
#include<cmath>


using namespace std;

int main()
{
int h1,h2,min1,min2,t;

cout<<"Введите начальное количество часов h1 ";
cin>>h1;
cout<<"Введите начальное количество минут min1 ";
cin>>min1;

cout<<"Введите конечное количество часов h2 ";
cin>>h2;
cout<<"Введите конечное количество минут min2 ";
cin>>min2;


h1 = h1 % 12;
h2 = h2 % 12;
min1 = min1 % 60;
min2 = min2 % 60;

if(h1>h2)
{
    cout<<"Ошибка ввода данных "<<endl;
}
else if(h1 == h2)
{
    if(min1>min2)
    cout<<"Ошибка ввода данных "<<endl;
    else
    t = min2 - min1;
}



else
{
if(min2 >= min1)
{
 t = (h2 - h1)*60 + (min2 - min1);
}
else
{
t = (h2 -h1 -1)*60 + (60 - min1 + min2);
}
}

cout<<"Количество прошедшего времени равно t = "<<t <<" минут " <<endl;
cout<<t/60<<" часов"<< t%60 <<" минут";
    return 0;
}