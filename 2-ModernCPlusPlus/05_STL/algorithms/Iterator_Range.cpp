#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char **argv)
{

    std::vector<int> v1{1, 2, 3, 45, 100};
    std::for_each(v1.begin(), v1.end(), [](int x)
                  { std::cout << x << std::endl; });

    // std::vector<int> v2{1, 2, 3, 4};

    // std::for_each(v2.begin(), v2.end(), [](auto &x)
    //               { std::cin >> x; });

    // std::for_each(v2.begin(), v2.end(), [](int x)
    //               { std::cout << x << std::endl; });

    std::vector<int>::iterator it = std::find(v1.begin(), v1.end(), 100);
    if (it != v1.end())
    {
        std::cout << "Element " << *it << " is founded in index" << std::distance(v1.begin(), it) << std::endl;
    }
    else
    {
        std::cout << "Element is not found" << std::endl;
    }
    return 0;
}