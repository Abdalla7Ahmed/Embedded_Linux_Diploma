#include <iostream>

void print()
{
    std::cout << std::endl;
}
template <typename T, typename... params>

void print(T &&a, params &&...args)
{
    std::cout << a;
    if (sizeof...(args) != 0)
    {
        std::cout << ", ";
    }
    print(std::forward<params>(args)...);
}

int main(int argc, const char **argv)
{

    print(1, 2, 3, 4, 5);
    return 0;
}