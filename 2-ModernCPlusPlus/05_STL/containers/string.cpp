#include <iostream>

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

    std::string s{"hi , this is test text"};
    s.insert(13, "very important "); // add the test at index 13
    print(s);                        // hi , this is very important test text
    s.erase(13, 15);
    print(s); // hi , this is test text
    s.replace(13, 4, "important");
    print(s);         // hi , this is important text
    print(sizeof(s)); // 32
    s.resize(40, '.');
    print(s); // hi , this is important text.............

    print(s.find('i')); // 1
    print(s.find('/')); // -1  or return std::string::npos
    if (s.find('/') == std::string::npos)
    {
        print("not found"); // not found
    }

    print(s.rfind('h'));   // 6  find from the end
    print(s.find('h'));    // 0  find from the begine
    print(s.find('h', 3)); // 6 starting from 3  posirion
    std::string s1 = s.substr(0, 3);
    print(s1); // hi
    print(s);  // hi , this is important text.............

    // joining
    std::string s2 = "this is the first line"
                     "this is the second line"
                     "this is the third line";
    print(s2); // this is the first linethis is the second linethis is the third line

    // Row string literals
    // R"Delimiter(text)Delimiter"
    std::string s3 = R"..(/home/abdallah/Documents/Github/ModernCPlusPlus/05_STL)..";
    std::string s4 = R"Delimiter(/home/abdallah/Documents/Github/ModernCPlusPlus/05_STL)Delimiter";

    print(s3);
    print(s4);

    s.push_back('a');
    print(s);
    s.pop_back();
    print(s);

    // geeksforgeeks

    // Initializing string
    std::string str = "geeksforgeeks is for geeks";

    // Displaying string
    print("The initial string is : ");
    print(str);

    // Resizing string using resize()
    str.resize(13);

    // Displaying string
    print("The string after resize operation is : ");
    print(str);

    // Displaying capacity of string
    print("The capacity of string is : ");
    print(str.capacity());

    // Displaying length of the string
    print("The length of the string is :");
    print(str.length());

    // Decreasing the capacity of string
    // using shrink_to_fit()
    str.shrink_to_fit();

    // Displaying string
    print("The new capacity after shrinking is : ");
    print(str.capacity());

    // std::getline

    std::string s5;
    std::getline(std::cin, s5);
    print(s5);
    std::getline(std::cin, s5, 'a'); // untill a
    print(s5);

    return 0;
}