#include<iostream>
 
int main(void)
{
    char x1=10;
    std::cout <<x1<< std::endl;          // nothing to print because operator overloading of char doesn't have the valid ascii with 10 
    std::cout <<static_cast<int>(x1)<< std::endl; // 10 because casting
    char x2=98; 
    std::cout<<x2<<std::endl;          // b  the ascii of 98
    
    std::cout<<sizeof(std::string)<<std::endl;    // 32  bit 
    int x{};
    std::cout << x << std::endl;
    return 0;
}
