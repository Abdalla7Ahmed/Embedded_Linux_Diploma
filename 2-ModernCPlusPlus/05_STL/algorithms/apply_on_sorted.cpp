#include <iostream>
#include <algorithm>

int main(int argc, char **argv)
{

    std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    auto f = std::binary_search(v1.begin(), v1.end(), 5); // reurn bool 1 / 0
    std::cout << f << std::endl;
    auto f2 = std::lower_bound(v1.begin() + 1, v1.end() + 1, 5); // les than or equal
    std::cout << *f2 << std::endl;                               // 5

    f2 = std::upper_bound(v1.begin() + 1, v1.end() + 1, 5); // grater than
    std::cout << *f2 << std::endl;                          // 6

    std::vector<int> v2{1, 2, 3, 4, 5, 6, 7, 8, 9}, v3{5, 6, 7, 8};

    auto f3 = std::includes(v2.begin(), v2.end(), v3.begin(), v3.end());
    std::cout << std::boolalpha << f3 << std::endl; // true

    f3 = std::includes(v3.begin(), v3.end(), v2.begin(), v2.end());
    std::cout << std::boolalpha << f3 << std::endl; // false

    std::vector<int> v4{1, 2, 3, 3, 3, 4, 5, 6, 6, 6, 7, 8, 9};

    auto f4 = std::equal_range(v4.begin(), v4.end(), 3);
    std::cout << *f4.first << std::endl;  // 3
    std::cout << *f4.second << std::endl; // 4

    std::cout << *(std::equal_range(v4.begin(), v4.end(), 5)).first << std::endl;  // 5
    std::cout << *(std::equal_range(v4.begin(), v4.end(), 5)).second << std::endl; // 6

    std::vector<int> v5{1, 2, 45, 1, 3, 56, 12, 12, 48, 2};
    std::sort(v5.begin(), v5.end(), [](int x, int y)
              { return x < y; });

    for (auto i = v5.begin(); i != v5.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}