#include <iostream>
#include <list>

void print(std::string str)
{
    std::cout << str << std::endl;
}
void print(int i)
{
    std::cout << i << std::endl;
}

void showlist(std::list<std::string> d)
{
    std::list<std::string>::iterator it;
    for (it = d.begin(); it != d.end(); ++it)
    {
        std::cout << *it << "   ";
    }

    std::cout << std::endl;
}

void showlist(std::list<int> d)
{
    std::list<int>::iterator it;
    for (it = d.begin(); it != d.end(); ++it)
    {
        std::cout << *it << "   ";
    }

    std::cout << std::endl;
}

int main(void)
{
    std::list<std::string> d1{"Abdallah", "Ali", "Omar", "Ahmed"};

    d1.push_back("back");
    d1.push_front("front");
    showlist(d1);
    d1.pop_back();
    d1.pop_front();
    showlist(d1);

    print(d1.size());     // 4
    print(d1.max_size()); // max number 288230376151711743

    print(d1.front()); // Abdallah
    print(d1.back());  // Ahmed

    d1.erase(d1.begin());
    showlist(d1); // Ali   Omar   Ahmed
    d1.erase(d1.begin(), d1.end());
    print(d1.size()); // 0

    d1.insert(d1.begin(), "Ahmed");
    d1.emplace(d1.begin(), "Omar");
    showlist(d1); // Omar Ahmed
    d1.emplace_back("back");
    d1.emplace_front("Front");
    showlist(d1); // Front   Omar   Ahmed   back
    d1.resize(10, "Empty");
    showlist(d1); // Front   Omar   Ahmed   back   Empty   Empty   Empty   Empty   Empty   Empty
    d1.clear();
    print(d1.size()); // 10

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