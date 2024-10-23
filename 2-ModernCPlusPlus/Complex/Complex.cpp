

#include "Complex.hpp"

Complex::Complex(/* args */)
{
    // std::cout << "Complex" << std::endl;
}

Complex::Complex(double real, double imag)
{
    this->real = real;
    this->imag = imag;
}
Complex::Complex(double real)
{
    this->real = real;
}
void Complex::set(double real, double imag)
{
    this->real = real;
    this->imag = imag;
}
float Complex::get_real(void)
{
    return this->real;
}
float Complex::get_imag(void)
{
    return this->imag;
}
void Complex::operator()(void)
{
    display();
}

// operator overloading  +
double Complex::operator+(double real)
{
    double result = this->real + real;
    return result;
}
Complex Complex::operator+(const Complex &other)
{
    Complex result;
    result.real = this->real + other.real;
    result.imag = this->imag + other.imag;
    return result;
}

// operator overloading  -
double Complex::operator-(double real)
{
    double result = this->real - real;
    return result;
}
Complex Complex::operator-(const Complex &other)
{
    Complex result;
    result.real = this->real - other.real;
    result.imag = this->imag - other.imag;
    return result;
}
// operator overloading  *
Complex Complex::operator*(const Complex &other)
{
    Complex result;
    result.real = this->real * other.real;
    result.imag = this->imag * other.imag;
    return result;
}
// operator overloading  /
Complex Complex::operator/(const Complex &other)
{
    Complex result;
    if (other.real != 0 && other.imag != 0)
    {
        result.real = this->real / other.real;
        result.imag = this->imag / other.imag;
        return result;
    }
    else
    {
        std::cout << "invalid div Floating point exception (core dumped)" << std::endl;
        exit(1);
    }
}

//
bool Complex::operator<(const Complex &other)
{
    return ((this->real < other.real) && (this->imag < other.imag));
}
bool Complex::operator>(const Complex &other)
{
    return ((this->real > other.real) && (this->imag > other.imag));
}

// operator overloading ++ (pre increment)
double Complex::operator++()
{
    return ++(this->real);
}
// operator overloading -- (pre decrement)
double Complex::operator--()
{
    return --(this->real);
}
// operator overloading ++ (pre increment)
double Complex::operator++(int)
{
    double tmp = this->real;
    this->real++;
    return tmp;
}
// operator overloading -- (pre decrement)
double Complex::operator--(int)
{
    double tmp = this->real;
    this->real--;
    return tmp;
}
// operator overloading =
void Complex::operator=(double real)
{
    this->real = real;
}

// operator overloading +=
void Complex::operator+=(double real)
{
    this->real += real;
}
// operator overloading -=
void Complex::operator-=(double real)
{
    this->real -= real;
}
// operator overloading /=
void Complex::operator/=(double real)
{
    if (real == 0)
    {
        std::cout << "invalid div Floating point exception (core dumped)" << std::endl;
        exit(1);
    }
    else
    {
        this->real /= real;
    }
}
// operator overloading *=
void Complex::operator*=(double real)
{
    this->real *= real;
}

// conversion to double
Complex::operator double() const
{
    return this->real;
}
// conversion to string
Complex::operator std::string() const
{
    std::string st;
    st = std::to_string(real) + "i" + std::to_string(imag);
    return st;
}

double operator+(double real, const Complex &other)
{
    Complex ret;
    ret.real = real + other.real;
    return ret;
}

void Complex::display(void)
{
    std::cout << real << "+i" << imag << std::endl;
}

Complex::~Complex()
{
    // std::cout << "~Complex" << std::endl;
}