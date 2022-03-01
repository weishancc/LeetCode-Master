#include <iostream>

void swap(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    std::cout << a << "," << b;
}

int main()
{
    int a = 5, b = 3;
    swap(a, b);

    return 0;
}