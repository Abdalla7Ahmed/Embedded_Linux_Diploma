#include "Complex.hpp"
#include <vector>
#include <algorithm>
int main(int argc, const char **argv)
{

    Complex cx1(1.1, 1.5);
    cx1.display();
    // functor
    cx1();
    double c = cx1 + 2.5;
    std::cout << c << std::endl;
    Complex cx2(10, 5);
    Complex cx3 = cx1 + cx2;
    cx2 = cx1 / cx3;
    std::vector<Complex> v{cx1, cx2, cx3};
    // std::sort(v.begin(), v.end());
    /*/usr/include/c++/11/bits/predefined_ops.h:69:22: error: no match for ‘operator<’ (operand types are ‘Complex’ and ‘Complex’)
    69 |       { return *__it < __val; }
    we have two solution
    1-use lambda function
    2-implement the operator oveloading <
    */
    std::sort(v.begin(), v.end(), [](Complex a, Complex b) { //
        return ((a.get_real() < b.get_real()) && (a.get_imag() < b.get_imag()));
    });
    //
    std::sort(v.begin(), v.end());

    cx3.display();
    cx3++;
    double x = ++cx3;
    std::cout << x << std::endl;
    x = static_cast<double>(cx3);
    std::cout << x << std::endl;
    std::string st = static_cast<std::string>(cx3);
    std::cout << st << std::endl;
    cx3 = 100;
    cx3.display();
    cx3 += 10;
    cx3.display();
    x = 5.5 + cx3;
    std::cout << x << std::endl;
    // Complex cx4 = 2; error
    Complex cx4 = static_cast<Complex>(2);
    cx4.display();
    return 0;
}