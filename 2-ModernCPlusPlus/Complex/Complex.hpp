#pragma once

#include <iostream>

class Complex
{
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double real, double imag);
    explicit Complex(double real);

    void operator()(void);
    double operator+(double real);
    Complex operator+(const Complex &other);
    double operator-(double real);
    Complex operator-(const Complex &other);
    Complex operator*(const Complex &other);
    Complex operator/(const Complex &other);
    bool operator<(const Complex &other);
    bool operator>(const Complex &other);
    double operator++();
    double operator--();
    double operator++(int);
    double operator--(int);
    // Assignment
    void operator=(double real);
    void operator+=(double real);
    void operator-=(double real);
    void operator*=(double real);
    void operator/=(double real);

    // Conversion
    operator double() const;
    operator std::string() const;
    // friend operator
    friend double operator+(double real, const Complex &other);
    void set(double real, double imag);
    float get_real(void);
    float get_imag(void);
    void display(void);

    ~Complex();
};
