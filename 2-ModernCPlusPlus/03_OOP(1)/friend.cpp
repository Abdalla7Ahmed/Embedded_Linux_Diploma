#include <iostream>

class test_friend
{
private:
    /* data */
    int a = 10;
    int b = 20;

public:
    friend int main();
    friend int sum(test_friend &value);
    test_friend() {}
    ~test_friend() {}
};

int sum(test_friend &value)
{
    value.a = 50;
    value.b = 55;
    return value.a + value.b;
}

int main()
{
    test_friend f1;
    f1.a = 100;
    f1.b = 200;
    std::cout << f1.a << std::endl;
    std::cout << f1.b << std::endl;
    std::cout << sum(f1) << std::endl;
    std::cout << f1.a << std::endl; // 50
    std::cout << f1.b << std::endl; // 55
    return 0;
}