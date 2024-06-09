#include <iostream>
#include <map>
#include <unordered_map>
void print(std::string str)
{
    std::cout << str << std::endl;
}
void print(int i)
{
    std::cout << i << std::endl;
}

void showmap(std::map<std::string, int> st)
{
    for (auto &it : st)
    {
        std::cout << "Key: " << it.first << " value: " << it.second << std::endl;
    }
    std::cout << std::endl;
}

void showmap(std::map<int, std::string> st)
{
    for (auto &it : st)
    {
        std::cout << "Key: " << it.first << " value: " << it.second << std::endl;
    }
    std::cout << std::endl;
}
int main(int argc, const char **argv)
{

    std::map<std::string, int> mp1;
    mp1["One"] = 1;
    mp1["Two"] = 2;
    mp1["Three"] = 3;
    mp1["Four"] = 4;
    mp1["Four"] = 4;
    std::cout << mp1["One"] << std::endl; // 1
    std::map<std::string, int>::iterator it = mp1.begin();
    /*
    while (it != mp1.end())
    {
        std::cout << "Key: " << it->first << " value: " << it->second << std::endl;
        ++it;
    }
    Key: Four value: 4
    Key: One value: 1
    Key: Three value: 3
    Key: Two value: 2
    */

    mp1.insert({"Five", 5});
    mp1.emplace("Six", 6);
    /*
    showmap(mp1);
    Key: Five value: 5
    Key: Four value: 4
    Key: One value: 1
    Key: Six value: 6
    Key: Three value: 3
    Key: Two value: 2
    */
    std::map<int, std::string> mp2;
    mp2[0] = "zero";
    mp2[1] = "one";
    mp2[2] = "two";
    mp2[3] = "three";
    mp2[4] = "four";
    /*
    showmap(mp2);
    Key: 0 value: zero
    Key: 1 value: one
    Key: 2 value: two
    Key: 3 value: three
    Key: 4 value: four
    */

    auto removed = mp1.erase("One");
    std::cout << removed << " removed" << std::endl; // 1 removed

    auto removed2 = mp2.erase(mp2.begin(), mp2.find(3));
    // showmap(mp2);
    // Key: 3 value: three
    // Key: 4 value: four

    // std::cout << *removed2 << std::endl; // 1 removed

    return 0;
}