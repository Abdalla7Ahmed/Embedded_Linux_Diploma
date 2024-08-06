#include<iostream>

class Base1
{
public:
    int x1=10;
    Base1(){};
    ~Base1(){};
    void fun()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
};

class Base2 
{
public:
    int x2=20;

    Base2(){};
    ~Base2(){};
    void fun()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
};


class Derived2 : public Base1, public Base2
{
public:
    int x3=30;

    Derived2(){};
    ~Derived2(){};
    void fun2()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
};


int main(void)
{

    Derived2 d2;
    d2.fun2();
    d2.Base1::fun();
    d2.Base2::fun();

    return 0;
}