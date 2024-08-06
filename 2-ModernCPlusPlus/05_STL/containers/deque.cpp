#include <iostream>
#include <deque>

void print(std::string str)
{
    std::cout << str << std::endl;
}
void print(int i)
{
    std::cout << i << std::endl;
}

void showdq(std::deque<std::string> d)
{
    std::deque<std::string>::iterator it;
    for (it = d.begin(); it != d.end(); ++it)
    {
        std::cout << *it << "   ";
    }

    std::cout << std::endl;
}

void showdq(std::deque<int> d)
{
    std::deque<int>::iterator it;
    for (it = d.begin(); it != d.end(); ++it)
    {
        std::cout << *it << "   ";
    }

    std::cout << std::endl;
}

int main(void)
{
    std::deque<std::string> d1{"Abdallah", "Ali", "Omar", "Ahmed"};

    d1.push_back("back");
    d1.push_front("front");
    showdq(d1);
    d1.pop_back();
    d1.pop_front();
    showdq(d1);

    print(d1.size());     // 4
    print(d1.max_size()); // max number 288230376151711743

    print(d1.front());
    print(d1.back());
    try
    {
        print(d1.at(5));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n'; // deque::_M_range_check: __n (which is 5)>= this->size() (which is 4)
    }

    d1.erase(d1.begin() + 1, d1.end());
    showdq(d1); // Abdallah
    d1.insert(d1.begin() + 1, "Ahmed");
    d1.emplace(d1.begin() + 2, "Omar");
    showdq(d1); // Abdallah Ahmed Omar
    d1.emplace_back("back");
    d1.emplace_front("Front");
    showdq(d1); // Front Abdallah Ahmed Omar back
    d1.resize(10, "Empty");
    showdq(d1); // Front Abdallah   Ahmed   Omar   back   Empty   Empty   Empty   Empty   Empty   Empty
    d1.clear();
    print(d1.size()); // 0

    if (d1.empty())
    {
        print("the list is empty");
    }
    else
    {
        print("the list is not empty");
    }
    return 0;
}