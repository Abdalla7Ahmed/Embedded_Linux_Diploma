#include <iostream>

constexpr int sum(int a, int b)
{
    return a + b;
}
class test
{
private:
    /* data */
    int a = 10;

public:
    static constexpr int SUM = sum(10, 20);
    static int aa;
    static const int bb{10};
    test(/* args */);
    ~test();
    test *ptr;
    void print()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};
int test::aa = 20;
test::test(/* args */)
{
    std::cout << this << std::endl;
    ptr = static_cast<test *>(this);
}

test::~test()
{
}

int main(int argc, const char **argv)
{
    test a;
    std::cout << a.ptr << std::endl;
    a.ptr->print();
    std::cout << a.SUM << std::endl;
    std::cout << test::SUM << std::endl;
    std::cout << a.aa << std::endl;
    std::cout << test::aa << std::endl;

    return 0;
}