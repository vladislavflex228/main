#include<iostream>
#include<cmath>

using namespace std;

int main()
{

double x1,x2,x3,y1,y2,y3,a,b,c;
cout<<"Введите координаты точки B = ";
cin>>x1;
cin>>y1;

cout<<"Введите координаты точки C = ";
cin>>x2;
cin>>y2;

cout<<"Введите координаты точки A = ";
cin>>x3;
cin>>y3;

a = (double)sqrt(pow((x1-x2),2) + pow((y1-y2),2));
b = (double)sqrt(pow((x3-x2),2) + pow((y3-y2),2));
c = (double)sqrt(pow((x1-x3),2) + pow((y1-y3),2));


cout<<"Сторона BC равна "<<a<<endl;
cout<<"Сторона AC равна "<<b<<endl;
cout<<"Сторона AB равна "<<c<<endl;

double fa,fb,fc;

fa = acos((double)((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c)));
fc = acos((double)((pow(b,2)+pow(a,2)-pow(c,2))/(2*b*a)));
fb= acos((double)((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c)));

cout<<"Угол BAC в радианах равен "<<fa << " Угол BAC в градусах равен "<< (double)fa*180/M_PI<<endl;
cout<<"Угол ABC в радианах равен "<<fb << " Угол ABC в градусах равен "<< (double)fb*180/M_PI<<endl;
cout<<"Угол ACB в радианах равен "<<fc << " Угол ACB в градусах равен "<< (double)fc*180/M_PI<<endl;


double ha,hb,hc;

ha =(double)(b * sin(fc));
hb = (double)(c * sin(fa));
hc = (double)(a * sin(fb));


cout<<"Высота ha треугольника ABC равна = " <<ha<<endl;
cout<<"Высота hb треугольника ABC равна = " <<hb<<endl;
cout<<"Высота hc треугольника ABC равна = " <<hc<<endl;

double S,P,p;

P = a + b + c;

p = (double)(P/2);


S = sqrt(p*(p-a)*(p-b)*(p-c)) ;//Нахождение по формуле Герона
S = (double)((ha * a)/2);//Нахождение через высоту проведенную к основанию
S = (double)((b * c * sin(fa))/2);//Нахождение через синус между двумя сторонами

cout<<"Площадь треугольника S = "<<S<<endl;

cout<<"Периметр треугольника P = "<<P<<endl;

double R,r,S_R,S_r,l_R,l_r;

R = (double)a/(2*sin(fa));
r = S/p;
S_R = M_PI * pow(R,2);
l_R = 2 * M_PI * R;
S_r= M_PI * pow(r,2);
l_r = 2 * M_PI * r;


cout<<"Радиус описанной окружности = "<<R<<endl;
cout<<"Площадь описанной окружности = "<<S_R<<endl;
cout<<"Длина описанной окружности = "<<l_R<<endl;

cout<<"Радиус вписанной окружности = "<<r<<endl;
cout<<"Площадь вписанной окружности = "<<S_r<<endl;
cout<<"Длина вписанной окружности = "<<l_r<<endl;


double ma,mb,mc,la,lb,lc;


ma = (double)(sqrt(2*pow(b,2)+2*pow(c,2)-pow(a,2)))/2;
mb = (double)(sqrt(2*pow(a,2)+2*pow(c,2)-pow(b,2)))/2;
mc = (double)(sqrt(2*pow(a,2)+2*pow(b,2)-pow(c,2)))/2;


cout<<"Медиана проведенная к стороне BC равна "<<ma<<endl;
cout<<"Медиана проведенная к стороне AС равна "<<mb<<endl;
cout<<"Медиана проведенная к стороне AB равна "<<mc<<endl;


la = (double)(sqrt(b*c*(pow(b+c,2)-pow(a,2)))/(b+c));
lb = (double)(sqrt(a*c*(pow(a+c,2)-pow(b,2)))/(a+c));
lc = (double)(sqrt(b*a*(pow(b+a,2)-pow(c,2)))/(b+a));

cout<<"Биссектриса проведенная к стороне BC равна "<<la<<endl;
cout<<"Биссектриса проведенная к стороне AC равна "<<lb<<endl;
cout<<"Биссектриса проведенная к стороне AB равна "<<lc<<endl;

    return 0;
}