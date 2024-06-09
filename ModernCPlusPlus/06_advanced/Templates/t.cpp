#include <iostream>

template <typename T>
T Max(T a, T b)
{
    std::cout << typeid(T).name() << std::endl;
    return a > b ? a : b;
}
// Exiplict Instantiations
template char Max(char a, char b);

int main(int argc, const char **argv)
{
    // if there is no using of this template , the compiler doesn't generate it .
    auto n1 = Max(10, 20);          // <Max<int>(int, int)>
    auto n2 = Max(10.15f, 200.56f); //<Max<float>(float, float)>
    // auto n3 = Max(10, 20.5f);  // no matching function for call to ‘Max(int, float)’
    auto n3 = Max(static_cast<float>(10), 20.5f);
    auto n4 = Max<double>(10, 20.5);

    int (*fptr)(int x, int y) = Max;
    fptr(20, 40);

    return 0;
}