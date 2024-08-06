#include <iostream>
class Base
{
public:
    virtual void fun1() = 0;
};
class child1 : public Base
{
public:
    int C1 = 10;
    void fun1() override { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    void fun2() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};
class child2 : public Base
{
public:
    int C2 = 20;
    void fun1() override { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    void fun2() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

int main(void)
{
    // Base B1; //cannot declare variable ‘B1’ to be of abstract type ‘Base’    because the following virtual functions are pure within ‘Base’
    child1 c1;
    c1.fun1();

    child2 c2;
    c2.fun1();

    return 0;
}