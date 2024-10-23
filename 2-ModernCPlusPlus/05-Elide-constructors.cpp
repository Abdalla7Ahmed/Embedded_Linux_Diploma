#include <iostream>

// class MyClass
// {
// public:
//     MyClass() { std::cout << "Default constructor called." << std::endl; }
//     MyClass(const MyClass &other) { std::cout << "Copy constructor called." << std::endl; }
//     MyClass(MyClass &&other) { std::cout << "Move constructor called." << std::endl; }
// };

// MyClass createMyClass()
// {
//     return MyClass();
// }

// int main()
// {
//     MyClass obj = createMyClass();
//     return 0;
// }

class MyClass
{
public:
    MyClass() { std::cout << "Default constructor called." << std::endl; }
    MyClass(const MyClass &other) { std::cout << "Copy constructor called." << std::endl; }
    MyClass(MyClass &&other) { std::cout << "Move constructor called." << std::endl; }
};

void createMyClass(const MyClass x)
{
}

int main()
{
    MyClass obj;
    createMyClass(obj);
    return 0;
}