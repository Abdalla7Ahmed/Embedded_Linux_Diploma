#include <iostream>
#include <set>
#include <unordered_set>
void print(std::string str)
{
    std::cout << str << std::endl;
}
void print(int i)
{
    std::cout << i << std::endl;
}
void showset(std::set<int> st)
{
    for (auto &i : st)
    {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
}

void showset(std::multiset<int> st)
{
    for (auto &i : st)
    {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
}

void showset(std::set<char> st)
{
    for (auto &i : st)
    {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
}

void showset(std::multiset<char> st)
{
    for (auto &i : st)
    {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
}

int main(int argc, const char **argv)
{

    std::set<int> s1{10, 1, 56, 45, 45, 45};
    std::multiset<int> s2{10, 1, 56, 45, 45, 45};

    showset(s1); // 1  10  45  56
    showset(s2); // 1  10  45  45  45  56

    std::set<char> s3;
    s3.insert('A');
    s3.insert('Y');
    s3.insert('Z');
    s3.insert('C');
    s3.insert('C');

    showset(s3); // A  C  Y  Z

    std::set<int, std::greater<int>> s4;
    s4.insert(10);
    s4.insert(5);
    s4.insert(12);
    s4.insert(4);
    for (auto &i : s4)
    {
        std::cout << i << "  "; // 12  10  5  4
    }
    std::cout << std::endl;

    for (std::set<char>::iterator i = s3.begin(); i != s3.end(); i++)
    {
        std::cout << *i << "  "; // A  C  Y  Z
    }
    std::cout << std::endl;

    // assigning the elements from s3 to s5

    std::set<char> s5(s3.begin(), s3.end());
    showset(s5); // A  C  Y  Z

    s5.erase('A');
    showset(s5); // C  Y  Z

    s5.erase(s5.begin());
    showset(s5); //  Y  Z
    s5.insert('A');
    s5.insert('B');
    s5.insert('C');
    showset(s5); // A B C  Y  Z

    // remove all elements up to C in s5
    s5.erase(s5.begin(), s5.find('C'));
    showset(s5); // C  Y  Z
    auto num1 = s5.erase('Y');
    auto num2 = s5.erase('A'); // there is no member in s5 with value A

    std::cout << num1 << " removed" << std::endl; //  1 removed
    std::cout << num2 << " removed" << std::endl; //  0 removed

    std::multiset<int> s6{1, 1, 2, 2, 3, 4, 5, 6};
    showset(s6); // 1 1 2  2  3  4  5  6

    auto num3 = s6.erase(1);                      // return the number of elements that removed
    std::cout << num3 << " removed" << std::endl; //  2 removed
    showset(s6);                                  // 2  2  3  4  5  6

    std::set<int> s7;
    // insert elements in random order
    s7.insert(40);
    s7.insert(30);
    s7.insert(60);
    s7.insert(20);
    s7.insert(50);

    // lower bound and upper bound for set s7
    std::cout << "s7.lower_bound(40) : " << *s7.lower_bound(40) << std::endl; // 40 -->  less than or equal
    std::cout << "s7.upper_bound(40) : " << *s7.upper_bound(40) << std::endl; // 50 -->  grater than

    std::set<int, std::greater<int>> s8;
    // insert elements in random order
    s8.insert(40);
    s8.insert(30);
    s8.insert(60);
    s8.insert(20);
    s8.insert(50);
    for (auto i : s8)
    {
        std::cout << i << "  "; // 60  50  40  30  20   reverse order
    }
    std::cout << std::endl;
    // lower bound and upper bound for set s7
    std::cout << "s7.lower_bound(40) : " << *s8.lower_bound(40) << std::endl; // 40 -->  less than or equal   in the set ( 60  50  40  30  20)
    std::cout << "s7.upper_bound(40) : " << *s8.upper_bound(40) << std::endl; // 30 -->  grater than in the set ( 60  50  40  30  20)

    print(s7.size()); // 5
    if (s7.empty())
    {
        print("the set is empty ");
    }
    else
    {
        print("the set is not empty ");
    }

    // unorder set

    std::unordered_set<int> u1{1, 2, 3, 4, 4, 5, 5, 1};
    for (auto i : u1)
    {
        std::cout << i << "  "; // 5  4  3  2  1
    }
    std::cout << std::endl;

    std::unordered_multiset<int> u2{1, 2, 3, 4, 4, 5, 5, 1};
    for (auto i : u2)
    {
        std::cout << i << "  "; // 5  5  4  4  3  2  1 1
    }
    std::cout << std::endl;
    return 0;
}
