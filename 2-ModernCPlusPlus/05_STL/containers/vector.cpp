#include <iostream>
#include <vector>
void print(std::string str)
{
    std::cout << str << std::endl;
}
void print(int i)
{
    std::cout << i << std::endl;
}

int main(void)
{

    std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto &i : v1)
    {
        // print(i);
    }
    std::vector<int> v2(5, 2); // vector of 5 elements with value 2
    // std::vector<int> v1(1,2,3,4,5,6,7,8,9,10); // error
    std::vector<int> v3(10); // 10 elements
    // print(v3.size());   // 10

    for (auto &i : v2)
    {
        // print(i);
    }

    std::vector<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    std::cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        std::cout << *i << " ";

    std::cout << "\nOutput of cbegin and cend: ";
    for (auto i = g1.cbegin(); i != g1.cend(); ++i)
        std::cout << *i << " ";

    std::cout << "\nOutput of rbegin and rend: ";
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
        std::cout << *ir << " ";

    std::cout << "\nOutput of crbegin and crend : ";
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
        std::cout << *ir << " ";

    std::cout << '\n';

    std::vector<int> g2;

    for (int i = 1; i <= 5; i++)
        g2.push_back(i);

    std::cout << "Size : " << g2.size();
    std::cout << "\nCapacity : " << g2.capacity();
    std::cout << "\nMax_Size : " << g2.max_size();

    // resizes the vector size to 4
    g2.resize(4);

    // prints the vector size after resize()
    std::cout << "\nSize : " << g2.size();

    // checks if the vector is empty or not
    if (g2.empty() == false)
        std::cout << "\nVector is not empty";
    else
        std::cout << "\nVector is empty";

    // Shrinks the vector
    g2.shrink_to_fit();
    std::cout << "\nCapacity : " << g2.capacity();
    std::cout << "\nVector elements are: ";
    for (auto it = g2.begin(); it != g2.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::vector<int> g3;
    for (int i = 1; i <= 10; i++)
    {
        g3.push_back(i * 10);
    }
    print(g3.front());
    print(g3.back());

    std::cout << "Reference operator [g] : g3[2] = \n"
              << g3[2];
    std::cout << "\nat : g3.at(4) = " << g3.at(4);
    // pointer to the first element
    int *pos = g3.data();

    std::cout << "\nThe first element is " << *pos;

    std::cout << std::endl;

    std::vector<int> g4;
    g4.assign(5, 10);

    std::cout << "The vector elements are: ";
    for (int i = 0; i < g4.size(); i++)
        std::cout << g4[i] << " "; // 10 10 10 10 10
    std::cout << std::endl;
    print(g4.size()); // 5
    g4.push_back(15);
    print(g4.size()); // 6
    g4.pop_back();
    print(g4.size()); // 5

    g4.insert(g4.begin(), 300);
    print(g4.front()); // 300

    g4.erase(g4.begin());
    print(g4.front()); // 10
    g4.emplace(g4.begin(), 300);
    print(g4.front()); // 300
    g4.clear();
    if (g4.empty())
    {
        print("g4 vector is empty");
    }
    else
    {
        print("g4 vector is not empty");
    }

    std::vector<int> g5, g6;
    g5.push_back(1);
    g5.push_back(2);
    g6.push_back(10);
    g6.push_back(20);

    g5.swap(g6);

    print(g5.front()); // 10
    print(g6.front()); // 1

    std::vector<int> t1{2, 9, 18, 5, 4};
    std::vector<int> t2(begin(t1) + 1, end(t1)); // 9 18 5 4

    t1.assign({1, 2, 3, 4, 5}); // t1 now have 1 2 3 4 5

    return 0;
}