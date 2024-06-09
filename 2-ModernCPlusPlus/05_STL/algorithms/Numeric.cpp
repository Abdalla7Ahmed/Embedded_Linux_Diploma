#include <iostream>
#include <algorithm>
#include <numeric>

int main(int argc, char **argv)
{

    std::vector<int> v1{5, 10, 15};
    int sum = 1;
    v1.resize(10);

    std::cout << std::accumulate(v1.begin(), v1.begin() + 3, sum) << std::endl;                    // 1+5+10+15 = 31
    std::cout << std::accumulate(v1.begin(), v1.begin() + 3, sum, std::plus<int>()) << std::endl;  // 1+5+10+15 = 31
    std::cout << std::accumulate(v1.begin(), v1.begin() + 3, sum, std::minus<int>()) << std::endl; // 1-5-10-15 = -29
    std::cout << std::accumulate(v1.begin(), v1.begin() + 3, sum, [](int x, int y)
                                 { return x * y; })
              << std::endl;                                                                             // 5 * 10 * 15 = 750
    std::cout << std::accumulate(v1.begin(), v1.begin() + 3, sum, std::multiplies<int>()) << std::endl; // 750

    // iota
    std::vector<int> v2(10);
    std::fill_n(v2.begin(), v2.size(), 0);
    std::iota(v2.begin(), v2.end(), 0);
    std::for_each(std::begin(v2), std::end(v2), [](int x)
                  { std::cout << x << " "; }); // 0 1 2 3 4 5 6 7 8 9

    return 0;
}