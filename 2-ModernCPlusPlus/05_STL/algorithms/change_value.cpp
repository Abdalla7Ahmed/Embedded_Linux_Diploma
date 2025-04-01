#include <iostream>
#include <vector>
#include <algorithm>

unsigned long long factorial(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
int main(int argc, char **argv)
{
    std::vector<char> letter1, letter2, letter3(10);
    letter1.resize(10);
    letter2.resize(10);
    std::fill(letter1.begin(), letter1.end(), 'A');
    std::fill(letter2.begin(), letter2.begin() + 5, 'B');
    std::fill(letter2.begin() + 5, letter2.end(), 'C');
    std::fill_n(letter3.begin(), 5, 'D');
    std::fill_n(letter3.begin() + 5, 5, 'E');

    std::cout << "printing letter1 contents..." << std::endl;
    std::for_each(letter1.begin(), letter1.end(), [](char x)
                  { std::cout << x << " "; }); // A A A A A A A A A A

    std::cout << "\nprinting letter2 contents..." << std::endl;
    std::for_each(letter2.begin(), letter2.end(), [](char x)
                  { std::cout << x << " "; }); // A A A A A A A A A A

    std::cout << "\nprinting letter3 contents..." << std::endl;
    std::for_each(letter3.begin(), letter3.end(), [](char x)
                  { std::cout << x << " "; }); // A A A A A A A A A A
    std::cout << std::endl;

    /*
    printing letter1 contents...
    A A A A A A A A A A
    printing letter2 contents...
    B B B B B C C C C C
    printing letter3 contents...
    D D D D D E E E E E
    */

    // transform
    std::vector<unsigned long long> v1{1, 2, 3, 4, 5, 6, 7, 8, 9}, v2;
    v2.resize(v1.size());
    std::transform(v1.begin(), v1.end(), v2.begin(), [](unsigned long long x)
                   { return factorial(x); });

    for (auto i = 0; i <= 9; i++)
    {
        std::cout << "the factorial of " << v1[i] << " is " << v2[i] << std::endl;
    }
    /*
    the factorial of 1 is 1
    the factorial of 2 is 2
    the factorial of 3 is 6
    the factorial of 4 is 24
    the factorial of 5 is 120
    the factorial of 6 is 720
    the factorial of 7 is 5040
    the factorial of 8 is 40320
    the factorial of 9 is 362880
    the factorial of 81 is 60497
    */

    std::vector<int> v3{10, 20, 30, 40, 50}, v4{1, 2, 3, 4, 5}, v5(5);
    std::transform(v3.begin(), v3.end(), v4.begin(), v5.begin(), [](int x, int y)
                   { return x + y; });

    for (auto i = 0; i < 5; i++)
    {
        std::cout << "the summation of " << v3[i] << " + " << v4[i] << " is " << v5[i] << std::endl;
    }

    /*
    the summation of 10 + 1 is 11
    the summation of 20 + 2 is 22
    the summation of 30 + 3 is 33
    the summation of 40 + 4 is 44
    the summation of 50 + 5 is 55
    */
    return 0;
}