#include <iostream>
#include <algorithm>
#include <list>
int main(int argc, const char **argv)
{
    // find with single element

    std::vector<std::string> str{"Abdallah", "Ali", "Omar", "Osman"};

    std::vector<std::string>::iterator it = std::find(str.begin(), str.end(), "Ali");

    std::cout << *it << std::endl; // Ali

    std::vector<int> v{1, 21, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    auto if_even = [](int x)
    { return !(x & 1); };

    auto ff = std::find_if(v.begin(), v.end(), if_even);
    std::cout << *ff << std::endl; // 4
    ff = std::find_if_not(v.begin(), v.end(), if_even);
    std::cout << *ff << std::endl; // 1

    std::vector<int> v1{0, 1, 2, 1, 1, 3, 4, 5, 6, 20}, v2{6, 7, 8, 9, 10, 11, 12};
    std::vector<int>::iterator it2 = std::find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end());
    std::cout << *it2 << std::endl;       // 6
    std::cout << *(it2 + 1) << std::endl; // 20

    // search with range
    it2 = std::adjacent_find(v1.begin(), v1.end());
    std::cout << *it2 << std::endl; // 1  first occurrence repeated twice sequentially or more , if v = 1,2,1 --> 0 , if v= 2,2,2,1,1 --> 2

    std::vector<int> v3{0, 5, 1, 2, 2, 3, 4, 4, 5, 5, 5, 9, 10};
    auto it3 = std::search_n(v3.begin(), v3.end(), 2, 2); // (@begin, @end,n , value)
    std::cout << it3[0] << std::endl;                     // 2

    it3 = std::search_n(v3.begin(), v3.end(), 3, 5); // (@begin, @end,n , value)
    std::cout << *it3 << std::endl;                  // 2

    it3 = std::search_n(v3.begin(), v3.end(), 4, 5); // (@begin, @end,n , value)
    if (it3 != v3.end())
    {
        std::cout << "element 5 is found 4 time sequentially" << std::endl;
    }
    else
    {
        std::cout << "element 5 not found 4 time sequentially" << std::endl;
    }

    std::vector<int> l1{5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 8}, l2{5, 6, 7}, l3{5, 7, 6};
    auto it4 = std::search(l1.begin(), l1.end(), l2.begin(), l2.end());
    std::cout << *it4 << std::endl;   // 5
    std::cout << it4[3] << std::endl; // 1

    it4 = std::search(l1.begin(), l1.end(), l3.begin(), l3.end());
    if (it4 != l1.end())
    {
        std::cout << "l3{5,7,6} found in l1" << std::endl;
    }
    else
    {
        std::cout << "l3{5,7,6} not found in l1" << std::endl;
    }

    // search from the end
    it4 = std::find_end(l1.begin(), l1.end(), l2.begin(), l2.end());
    std::cout << *it4 << std::endl;   // 5
    std::cout << it4[3] << std::endl; // 8

    it4 = std::find_end(l1.begin(), l1.end(), l3.begin(), l3.end());
    if (it4 != l1.end())
    {
        std::cout << "l3{5,7,6} found in l1" << std::endl;
    }
    else
    {
        std::cout << "l3{5,7,6} not found in l1" << std::endl;
    }

    return 0;
}
