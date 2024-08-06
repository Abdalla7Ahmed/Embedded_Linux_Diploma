// 6.Simple Lambda: Write a lambda function to calculate the square of a given number.

#include <iostream>
#include <math.h>

int main(void)
{
    auto fun = [](double number) -> double
    {
        int p = 2;
        return pow(number, p);
    };
    double n;
    std::cout << "Enter the number " << std::endl;
    std::cin >> n;
    std::cout << fun(n) << std::endl;
    std::cout << typeid(fun(10)).name() << std::endl;

    return 0;
}