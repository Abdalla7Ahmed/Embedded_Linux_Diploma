#include <iostream>
#include <algorithm>

bool compare(int a, int b)
{
    return (a > b);
}
int main(int argc, char **argv)
{
    std::vector<int> l1{1, 2, 3, 4, 5}, l2{1, 2, 3, 4, 5}, l3{0, 1, 2, 3, 4, 5};

    auto i = std::equal(l1.begin(), l1.end(), l2.begin());

    std::cout << std::boolalpha << i << std::endl; // true

    i = std::equal(l1.begin() + 1, l1.end() + 1, l3.begin() + 1); // compair with the  length of the  v1.end() + 1
    std::cout << std::boolalpha << i << std::endl;                // false

    i = std::equal(l1.begin(), l1.end(), l3.begin() + 1, l3.end());
    std::cout << std::boolalpha << i << std::endl; // true

    // initializing vectors
    std::vector<int> v1 = {1, 10, 15, 20};
    std::vector<int> v2 = {1, 10, 25, 30, 45};
    std::vector<int> v3 = {1, 10, 15, 20};
    std::vector<int> v4 = {1, 10, 15, 20, 24};

    // declaring pointer pair
    std::pair<std::vector<int>::iterator,
              std::vector<int>::iterator>
        mispair;
    // using mismatch() to search for 1st mismatch
    mispair = mismatch(v1.begin(), v1.end(), v2.begin());

    // printing the mismatch pair
    // 1st mismatch at 15 and 25
    std::cout << "The 1st mismatch element of 1st container : ";
    std::cout << *mispair.first << std::endl; // 15

    std::cout << "The 1st mismatch element of 2nd container : ";
    std::cout << *mispair.second << std::endl; // 25

    // using mismatch() to search for 1st mismatch
    mispair = mismatch(v3.begin(), v3.end(), v4.begin());
    // printing the mismatch pair
    // no mismatch
    // points to position after last 0 and corresponding 24
    std::cout << "The returned value from 1st container is : ";
    std::cout << *mispair.first << std::endl; // 0

    std::cout << "The returned value from 2nd container is : ";
    std::cout << *mispair.second << std::endl; // 24

    // =========================

    // initializing vectors
    std::vector<int> v10 = {23, 13, 15, 20};
    std::vector<int> v20 = {1, 10, 25, 30, 45};
    std::vector<int> v30 = {12, 100, 152, 204};
    std::vector<int> v40 = {1, 10, 15, 20, 24};

    // using mismatch() to search for 1st mismatch
    mispair = mismatch(v10.begin(), v10.end(), v20.begin(), compare);

    // printing the mismatch pair
    // 1st mismatch at 15 and 25
    // 15 is 1st element less than 2nd at same position
    std::cout << "The 1st mismatch element of 1st container : ";
    std::cout << *mispair.first << std::endl;

    std::cout << "The 1st mismatch element of 2nd container : ";
    std::cout << *mispair.second << std::endl;

    // using mismatch() to search for 1st mismatch
    mispair = mismatch(v30.begin(), v30.end(), v40.begin(), [](int x, int y)
                       { return x > y; });

    // printing the mismatch pair
    // no mismatch
    // all elements in 1st container are greater than 2nd
    // points to position after last 0 and corresponding 24
    std::cout << "The returned value from 1st container is  : ";
    std::cout << *mispair.first << std::endl;

    std::cout << "The returned value from 2nd container is  : ";
    std::cout << *mispair.second << std::endl;

    return 0;
}