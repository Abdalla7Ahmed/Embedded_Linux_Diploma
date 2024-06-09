//2- maximum number between three values
#include<iostream>

int main(void)
{
    int n1,n2,n3,max{};
    std::cout<<"enter the first number"<<std::endl;
    std::cin>>n1;
    std::cout<<"enter the second number"<<std::endl;
    std::cin>>n2;
    std::cout<<"enter the tgird number"<<std::endl;
    std::cin>>n3;
    if(n1==n2 && n2 == n3)
    {
        std::cout<<"the three numbers are equals"<<std::endl;
    }
    else
    { 
       max=(n1>n2)?(n1>n3)?n1:n3:(n2>n3)?n2:n3;
       std::cout<<"the maximum number is "<<max<<std::endl;
    }

    std::cout<<"======================================="<<std::endl;

    // or 
    std::cout<<"the maximum number is "<<std::max(std::max(n1,n2),n3)<<std::endl;


    return 0;
}
