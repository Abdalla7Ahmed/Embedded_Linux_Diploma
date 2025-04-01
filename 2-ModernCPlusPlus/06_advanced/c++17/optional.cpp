#include <iostream>
#include <optional>

std::optional<const char *> GetErrorName(int number)
{
    switch (number)
    {
    case 0:
        return "Error number 0";
        break;
    case 1:
        return "Error number 1";
        break;
    case 2:
        return "Error number 2";
        break;
    default:
        return std::nullopt;
        break;
    }
}

class ContactName
{
    std::string first;
    std::optional<std::string> middle;
    std::string last;

public:
    ContactName(const std::string &f, const std::optional<std::string> &m, const std::string &l)
        : first{f},
          middle{m},
          last{l}
    {
    }

    void Print()
    {
        std::cout << first << ' ';
        std::cout << middle.value_or("") << ' ';
        std::cout << last << ' ';
        std::cout << '\n';
    }
};
int main(int argc, const char **argv)
{
    // std::optional<int> value = 5;
    auto value = std::make_optional(5);
    if (value.has_value())
    {
        // we can print the value like this:
        std::cout << value.value() << std::endl;
        // if it hasn't value, it will throw an exception std::bad_optional_access

        // the dereferance the optional is valid also
        std::cout << *value << std::endl;
    }
    // valid check --> the boolean operator is implemented
    // if (value)
    // {
    // }

    // we can reuse the optional
    value = 20;
    value.reset(); // this also valid and mean that the value inside the optional will be destroyed

    auto ErrorNAme = GetErrorName(5);
    if (ErrorNAme.has_value())
    {
        std::cout << ErrorNAme.value() << std::endl;
    }
    else
    {
        std::cout << "Unknown error" << std::endl;
    }

    if (ErrorNAme)
    {
        std::cout << *ErrorNAme << std::endl;
    }
    else
    {
        std::cout << "Unknown error" << std::endl;
    }

    // we can use value_or instade of this check and the argument in the value_or should be same as the optional type
    std::cout << ErrorNAme.value_or("Unknown error --> default ") << std::endl;
    // return the contained value or the argument passed in the value_or

    ContactName n1{"Umar", "Majid", "Lone"};
    ContactName n2{"Ayaan", std::nullopt, "Lone"};

    n1.Print();
    n2.Print();

    return 0;
}