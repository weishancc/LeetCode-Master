#include <iostream>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{

    int a = 24;
    int b = 36;

    std::cout << gcd(a, b) << std::endl;
    std::cout << lcm(a, b);

    return 0;
}