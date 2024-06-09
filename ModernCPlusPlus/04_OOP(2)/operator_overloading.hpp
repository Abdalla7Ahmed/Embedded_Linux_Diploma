#include<iostream>



class Complex {
private:
    int real;
    float imag;
    int a = 135;
 
public:
    Complex();
    ~Complex();
    explicit Complex(int real);
    Complex(int r , float i );
    void print();

    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator+(const Complex& obj);
    Complex operator-(const Complex& obj);
    int operator+(int real);
    int operator-(int real);
    float operator+(float imag);
    float operator-(float imag);
    bool operator<(const Complex&obj);
    void operator()(void);
    void operator++();
    void operator--();
    Complex operator++(int);
    Complex operator--(int);
    friend int  operator+(int real,const Complex&obj);
    explicit operator int(){return real;}
};
