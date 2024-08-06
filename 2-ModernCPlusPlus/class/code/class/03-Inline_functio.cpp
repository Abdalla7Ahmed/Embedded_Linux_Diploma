#include <iostream>

class test
{
private:
public:
    void display_hello()
    {
        std::cout << "Hello!" << std::endl;
    }
};

int main(int argc, const char **argv)
{
    test t1;
    t1.display_hello();
    return 0;
}