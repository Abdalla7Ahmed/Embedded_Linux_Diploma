#include "operator_overloading.hpp"

/*

C++ Operator Overloading
C++ has the ability to provide the operators with a special meaning for a data type,
this ability is known as operator overloading. Operator overloading is a compile-time polymorphism.
For example, we can overload an operator ‘+’ in a class like String so that we can concatenate two
strings by just using +.Other example classes where arithmetic operators may be overloaded
are Complex Numbers, Fractional Numbers, Big integers, etc.
*/

Complex::Complex()
{
    // std::cout<<__PRETTY_FUNCTION__<<std::endl;
}
Complex::~Complex()
{
    // std::cout<<__PRETTY_FUNCTION__<<std::endl;
}
Complex::Complex(int r, float i)
{
    this->real = r;
    this->imag = i;
}
Complex::Complex(int real) : real(real)
{
}
// This is automatically called when '+' is used with
// between two Complex objects
Complex Complex::operator+(const Complex &obj)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    Complex result;
    result.real = this->real + obj.real;
    result.imag = this->imag + obj.imag;

    return result;
}
void Complex::print()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    std::cout << real << " + i" << imag << '\n';
}

Complex Complex::operator-(const Complex &obj)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    Complex result;
    result.real = this->real - obj.real;
    result.imag = this->imag - obj.imag;

    return result;
}
int Complex::operator+(int real)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    int result;
    result = this->real + real;
    return result;
}
int Complex::operator-(int real)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    int result;
    result = this->real - real;
    return result;
}

float Complex::operator+(float imag)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    float result;
    result = this->imag + imag;
    return result;
}
float Complex::operator-(float imag)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    float result;
    result = this->imag - imag;
    return result;
}
bool Complex::operator<(const Complex &obj)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return (this->real < obj.real) && (this->imag < obj.imag);
}

void Complex::operator()(void)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "real is " << real << " and imag is " << imag << std::endl;
}

void Complex::operator++()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    this->real++;
    this->imag++;
}
void Complex::operator--()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    this->real--;
    this->imag--;
}
Complex Complex::operator++(int)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    Complex tmp;
    tmp.real = this->real++;
    tmp.imag = this->imag++;
    return tmp;
}
Complex Complex::operator--(int)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    Complex tmp;
    tmp.real = this->real--;
    tmp.imag = this->imag--;
    return tmp;
}

int operator+(int real, const Complex &obj)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    // error: ‘int Complex::real’ is private within this context
    // to solve this , make this function friend
    return (real + obj.real);
}
