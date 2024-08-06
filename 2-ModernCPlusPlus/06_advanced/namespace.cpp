/**
 * @file namespace.cpp
 * @author abdallah ahmed
 * @brief this file is explain the useing of namespace in cpp
 * @version 0.1
 * @date 2024-04-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <bits/stdc++.h>

namespace my_namespace
{
    class test_class
    {
    private:
        /* data */
    public:
        test_class(/* args */);
        ~test_class();
        void print_hello();
    };

    void say_welcom();
    namespace subnamespace
    {
        void say_welcom();
    }
}

my_namespace::test_class::test_class(/* args */)
{

    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

my_namespace::test_class::~test_class()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void my_namespace::test_class::print_hello()
{
    std::cout << "Hello " << std::endl;
}

void my_namespace::say_welcom()
{
    std::cout << "welcom " << std::endl;
}
void my_namespace::subnamespace::say_welcom()
{
    std::cout << "welcom2 " << std::endl;
}
// alaises
namespace p = my_namespace;
using u8 = unsigned char;
typedef unsigned int u32;
int main(int argc, const char **argv)
{

    my_namespace::test_class test_class;

    test_class.print_hello();

    my_namespace::say_welcom();
    my_namespace::subnamespace::say_welcom();

    p::say_welcom();
    return 0;
}