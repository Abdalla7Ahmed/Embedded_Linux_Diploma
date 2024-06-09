#include <iostream>
#include <array> 
#include <iterator>
#include <algorithm>

void print(std::string str)
{
    std::cout<<str<<std::endl;
}
void print(int i)
{
    std::cout<<i<<std::endl;
}

int main(void)
{
    std::array<int,5> a1{10,2,36,14,2};
    std::array<char,5> a2= {1,2,3,4,5};
    std::array<std::string,3> a3= {std::string("ab"),"cd","ef"};
    for(auto i:a3)
    {
        print(i);
    }
    print(a1.size());  // 5
    print(a2.size());  // 5 
    print(a3.size());  // 3

    // container operations are supported
    std::sort(a1.begin(), a1.end());

   // Filling a1 with 15
    a1.fill(15);


    print(a3.front());
    print(a3.back());

    std::array <char , 3> arr={'G','f','G'};  // ASCII val of 'G' =71 
    std::array <char , 3> arr1={'M','M','P'}; // ASCII val of 'M' = 77 and 'P' = 80
    arr.swap(arr1);  // now arr = {M,M,P}
    for(int i=0;i<3;i++)
    {
        std::cout<<arr[i]<<std::endl;  // M M P
    }
    for(int i=0;i<3;i++)
    {
        std::cout<<arr1[i]<<std::endl; // G F G
    }
    std::array <char ,0>arr2{};
    print(arr.empty());   // 0
    print(arr2.empty());   // 1

    std::cout<< arr.at(2) <<" " << arr1.at(2)<<std::endl;
    try
    {
        std::cout<< arr.at(3); // exception{Abort signal from abort(3) (SIGABRT)}

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n'; //array::at: __n (which is 3) >= _Nm (which is 3)
    }


    std::array <int , 10> array;    
    print(array.size()); // 10 total num of indexes  `
    print(array.max_size()); // 10  total num of indexes
    print(sizeof(array)); // 10*4 = 40 total size of array
    

    std::array<int , 10> array2 {1,2,3,4,5,6,7,8,9,10};
    int *ptr = array2.data();
    std::cout<<ptr<<std::endl;          // 0x7ffcb9051fd0
    std::cout<<&array2<<std::endl;      //0x7ffcb9051fd0
    std::cout<<&array2[0]<<std::endl;   //0x7ffcb9051fd0
    



    return 0;
}