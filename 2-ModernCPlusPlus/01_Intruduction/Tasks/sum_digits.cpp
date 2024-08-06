// 6-summation the digits of integer entered by user


#include<iostream>


int main(int argc, const char** argv) {
    int number,sum{};

    std::cout<<"Enter the number"<<std::endl;
    std::cin>>number;

    std::string str= std::to_string(number);
    for(char digit : str)
    {
        sum += digit - '0';
    }

    std::cout<<"the sum of digits is "<<sum<<std::endl;
    return 0;
}
 