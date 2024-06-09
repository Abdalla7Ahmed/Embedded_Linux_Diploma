
#include<iostream>
#include <functional>
#include <complex>
/*
A literal is used for representing a fixed value in a program. 
A literal could be anything in a code like a, b, c2. , ‘ACB’, etc.

Similarly, User-Defined Literals (UDL) provides literals for a variety of built-in types
that are limited to integer, character, floating-point, string, boolean, and pointer. 
In simple terms, they combine values with units.


Let us consider the below example to understand the need for UDLs.

long double Weight = 2.3; //  pounds? kilograms? grams?

// With UDL, we attach units to the values which has
// following advantages
// 1) The code becomes readable.
// 2) Conversion computations are done at compile time. 
weight = 2.3kg;
ratio = 2.3kg/1.2lb;

*/

// KiloGram
long double operator "" _kg(long double value)
{
    std::cout<<__PRETTY_FUNCTION__<<std::endl;
    return value*1000;
}

long double operator "" _g(long double value)
{
    std::cout<<__PRETTY_FUNCTION__<<std::endl;
    return value;
}
long double operator "" _mg(long double value)
{
    std::cout<<__PRETTY_FUNCTION__<<std::endl;
    return value/1000;
}

// imaginary literal
constexpr std::complex<double> operator"" _i(long double d)
{
    return std::complex<double>{ 0.0, static_cast<double>(d) };
}

void operator "" _print(const char str[],std::size_t)
{
    std::cout<<std::string{str}<<std::endl;
}

int main(int argc, const char** argv)
{

    long double weight1 = 3.6_kg;
    long double weight2 = 5000.0_g;
    long double weight3 = 1000.0_mg;
    std::cout<<weight1<<std::endl;
    std::cout<<weight2<<std::endl;
    std::cout<<weight3<<std::endl;

    long double weight4 = weight2 +1000.0_mg+1.0_kg;
    long double weight5 = 1.0_kg + weight1;

    std::cout<<weight4<<std::endl;  //6001
    std::cout<<weight5<<std::endl;  //4600


    std::complex<double> z = 3.0 + 4.0_i;
    std::complex<double> y = 2.3 + 5.0_i;
    std::cout << "z + y = " << z + y << std::endl;
    std::cout << "z * y = " << z * y << std::endl;
    std::cout << "abs(z) = " << abs(z) << std::endl;


    "Helloworld"_print;
    return 0;
}