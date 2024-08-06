// 5-multiplication table

#include <iostream>

int main(int argc, const char **argv)
{
    int number;
    std::cout << "Enter the number " << std::endl;
    std::cin >> number;

    std::cout << "     multiplication Table :" << std::endl;
    std::cout << "+---------+---------+---------+" << std::endl;
    std::cout << "|   i     |  number |  result |" << std::endl;
    std::cout << "+---------+---------+---------+" << std::endl;
    for (int i = 0; i < 20; i++)
    {
        if (i >= 10)
        {
            std::cout << "    " << number << "   *   " << i << "         " << i * number << std::endl;
        }
        else
        {
            std::cout << "    " << number << "   *    " << i << "         " << i * number << std::endl;
        }
    }

    return 0;
}