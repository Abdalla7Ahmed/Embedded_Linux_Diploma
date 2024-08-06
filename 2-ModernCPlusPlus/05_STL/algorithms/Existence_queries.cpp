#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
int main(void)
{

    // all of
    std::vector<int> values{100, 50, 12, 3, 46, 56, 10, 5};
    auto f = [](int x)
    { return x > 2; };

    auto i = std::all_of(values.begin(), values.end(), f);

    if (i == 1)
    {
        std::cout << " Alla values is grater than 2" << std::endl;
    }

    std::vector<int> values2;
    std::cout << "Enter the number of values" << std::endl;
    int size;
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Value " << i + 1 << " : ";
        int tmp;
        std::cin >> tmp;
        values2.push_back(tmp);
    }

    for (auto i : values2)
        std::cout << i << std::endl;
    auto is_even = [](int x)
    { return !(x & 1); };
    auto b = std::all_of(values2.begin(), values2.end(), is_even);
    if (b == 1)
    {
        std::cout << "All the values are even " << std::endl;
    }
    else
    {
        std::cout << "Not all the values are even " << std::endl;
    }

    // any of
    std::vector<std::string> str;
    auto contain_a = [](std::string str)
    {
        auto i = std::find(str.begin(), str.end(), 'a');
        if (i != str.end())
            return true;
        return false;
    };
    str.push_back("Ala");
    str.push_back("Ali");
    str.push_back("Ali");
    str.push_back("Ali");

    auto any_a = std::any_of(str.begin(), str.end(), contain_a);

    if (any_a == false)
    {
        std::cout << "there is no any string contain a" << std::endl;
    }
    else
    {
        std::cout << "there is a string contain a" << std::endl;
    }

    // none of

    std::set<int> st{-1, -2, -3, -4, -6, -5, -21, -32, -1, 0};
    std::cout << std::none_of(st.begin(), st.end(), [](int x)
                              { return x > 0; })
              << std::endl;

    // count

    std::vector<int> ms{1, 2, 1, 3, 40, 5, 5, 5, 5};
    std::cout << std::count(std::begin(ms) + 1, std::begin(ms) + 6, 5) << std::endl;

    auto is_odd = [](int x)
    {
        return (x % 2);
    };

    auto number_of_odd = std::count_if(ms.begin(), ms.end(), is_odd);
    std::cout << "the number of odd numbers is " << number_of_odd << std::endl;
    return 0;
}