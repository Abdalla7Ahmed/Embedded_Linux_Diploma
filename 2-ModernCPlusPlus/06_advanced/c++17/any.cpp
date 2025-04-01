#include <iostream>
#include <any>

int main()
{
    std::any value = 42;
    std::cout << std::any_cast<int>(value) << '\n';

    value = "Hello";
    std::cout << std::any_cast<const char *>(value) << '\n';

    return 0;
}
