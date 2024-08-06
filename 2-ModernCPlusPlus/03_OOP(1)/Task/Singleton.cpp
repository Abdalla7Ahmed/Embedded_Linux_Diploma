#include <iostream>

class Singleton
{
private:
    Singleton(/* args */);
    ~Singleton();

public:
    static Singleton *instance;
    static Singleton &getInstance();
    void display();
};

Singleton::Singleton(/* args */)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Singleton::~Singleton()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void Singleton::display()
{
    std::cout << "Hello, Singleton" << std::endl;
}
Singleton &Singleton::getInstance()
{
    static Singleton s1;
    return s1;
}
int main()
{
    Singleton::getInstance().display();

    return 0;
}