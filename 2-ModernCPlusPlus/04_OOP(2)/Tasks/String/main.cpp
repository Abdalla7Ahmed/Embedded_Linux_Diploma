#include "string.hpp"

int main(void)
{
    char str1[] = "hello world ";
    char str2[] = "abdallah";
    string s1(str1);
    string s2(str2);
    string s3(s1 + s2);
    // s3.print();
    std::cout << s3 << std::endl;

    std::cin >> s3;
    std::cout << s3 << std::endl;
    return 0;
}
