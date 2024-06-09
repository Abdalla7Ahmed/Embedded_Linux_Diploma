#include <iostream>
#include <algorithm>

int main(int argc, char **argv)
{

    std::vector<int> v{1, 2, 3, 51, 23, 46, 130, 123};
    auto it = std::min_element(v.begin(), v.end());
    std::cout << *it << std::endl; // 1
    it = std::max_element(v.begin(), v.end());
    std::cout << *it << std::endl; // 130

    it = std::min_element(v.begin(), v.end(), [](int x, int y)
                          { return x < y; });
    std::cout << *it << std::endl; // 130

    return 0;
}