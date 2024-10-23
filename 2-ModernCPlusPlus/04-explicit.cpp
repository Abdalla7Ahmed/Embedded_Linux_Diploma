#include <iostream>

class MyClass
{
public:
    explicit MyClass(int value)
    {
        // Construct MyClass object from an integer
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};
void doSomething(MyClass obj)
{
    // Do something with the MyClass object
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void doSomething(int a)
{
    // Do something with the MyClass object
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main(int argc, const char **argv)
{
    // MyClass obj = 42; // Error: cannot convert 'int' to 'MyClass'
    MyClass obj = MyClass(42);
    // doSomething(42); // Error: cannot convert 'int' to 'MyClass'
    doSomething(MyClass(42));
    // if we have another function that accept an int it will work
    doSomething(42);
    return 0;
}