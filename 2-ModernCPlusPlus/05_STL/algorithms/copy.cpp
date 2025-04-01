#include <iostream>
#include <vector>
#include <algorithm>

bool compair(int a)
{
    return a > 20;
}
int main(int argc, char **argv)
{

    std::vector<std::string> str2{"Abdallah", "Ali", "Omar", "Hossam"}, str1(10);

    std::copy(str2.begin(), str2.end(), str1.begin());

    std::for_each(str1.begin(), str1.end(), [](std::string str)
                  { std::cout << str << " "; });
    std::cout << std::endl;

    std::vector<int> v1{10, 20, 30, 40, 50, 60}, v2(10);

    std::copy_if(v1.begin(), v1.end(), v2.begin(), compair);

    std::for_each(v2.begin(), v2.end(), [](int x)
                  { std::cout << x << " "; });
    std::cout << std::endl;

    std::vector<int> v3{10, 20, 30, 40, 50}, v4(5);
    std::copy_n(v3.begin(), 3, v4.begin());

    std::for_each(std::begin(v4), std::end(v4), [](int x)
                  { std::cout << x << " "; });
    std::cout << std::endl;

    return 0;
}