#include <iostream>

int main()
{
    int X, Y;
    double A, B, C, K;

    std::cout << "Введите X и Y: ";
    std::cin >> X >> Y;

    std::cout << "Введите A, B и C: ";
    std::cin >> A >> B >> C;

    std::cout << "Введите K: ";
    std::cin >> K;

    
    if (X == Y)
    {
        X = 0;
        Y = 0;
    }
    else if (X > Y)
    {
        Y = 0;
    }
    else
    {
        X = 0;
    }

    
    if (A > B && C > B)
    {
        B -= K;
    }
    else if (A > C && B > C)
    {
        C -= K;
    }
    else if (B > A && C > A)
    {
        A -= K;
    }

    
    std::cout << "X = " << X << " Y = " << Y << "\n";
    std::cout << "A = " << A << " B = " << B << " C = " << C << "\n";

    return 0;
}
