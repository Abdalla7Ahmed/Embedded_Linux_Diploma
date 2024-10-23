#include <iostream>

class test
{
private:
public:
    void display_hello();
};

void test::display_hello()
{
    std::cout << "hello world " << std::endl;
}

int main(int argc, const char **argv)
{
    return 0;
}