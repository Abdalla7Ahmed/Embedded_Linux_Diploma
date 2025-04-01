#include <iostream>
#include <variant>

int main()
{
    std::variant<int, double, std::string> myVariant;

    myVariant = 10;
    std::cout << std::get<int>(myVariant) << '\n';

    myVariant = "Hello";
    std::cout << std::get<std::string>(myVariant) << '\n';

    return 0;
}
