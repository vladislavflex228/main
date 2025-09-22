#include <iostream>

int main()
{
double x,y,z;

std::cin>>x;
std::cin>>y;
std::cin>>z;

if(x <=0 || y <= 0 || z<= 0)
{
    std::cout<<"Треугольника не существует";

}
else if( x+y > z && x +z > y && y+z > x)
{

std::cout<<"Треугольника существует";

}
else
{
    std::cout<<"Треугольника не существует";
}

return 0;

}