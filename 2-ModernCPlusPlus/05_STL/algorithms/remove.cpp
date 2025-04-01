#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char **argv)
{

    std::vector<int> v1{1, 2, 3, 40, 2, 60, 2};
    std::for_each(std::begin(v1), std::end(v1), [](int x)
                  { std::cout << x << " "; }); // 1 2 3 40 2 60 2
    std::cout << std::endl;

    auto re = std::remove(v1.begin(), v1.end(), 2);
    std::fill(re, v1.end(), 0);
    std::for_each(std::begin(v1), std::end(v1), [](int x)
                  { std::cout << x << " "; }); // 1 3 40 60 0 0 0

    std::cout << std::endl;
    std::cout << v1.size() << std::endl; // 7

    v1.erase(re, v1.end());
    // v1.resize(4);
    std::for_each(std::begin(v1), std::end(v1), [](int x)
                  { std::cout << x << " "; }); // 1 3 40 60
    std::cout << std::endl;
    std::cout << v1.size() << std::endl; // 4

    return 0;
}