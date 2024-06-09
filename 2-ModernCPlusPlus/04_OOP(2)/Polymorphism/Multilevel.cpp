#include<iostream>

class Base
{
public:
    int x1=10;
    Base(){};
    ~Base(){};
    void fun1()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
};

class Derived1 : public Base
{
public:
    int x2=20;

    Derived1(){};
    ~Derived1(){};
    void fun2()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
};


class Derived2 : public Derived1
{
public:
    int x3=30;

    Derived2(){};
    ~Derived2(){};
    void fun3()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
};


int main(void)
{

    Derived2 d2;
    d2.fun3();
    d2.fun2();
    d2.fun1();
    std::cout<<d2.x1<<std::endl;
    std::cout<<d2.x2<<std::endl;
    std::cout<<d2.x3<<std::endl;

    return 0;
}