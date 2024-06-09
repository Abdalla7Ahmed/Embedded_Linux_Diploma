#include<iostream>
#include <bitset>
#include <algorithm>



#include <numeric>
#include <vector>

void fillArray(std::vector<int>& arr, int start, int end) {
    if (start <= end) {
        arr.push_back(start);
        fillArray(arr, start + 1, end);
    }
}


int &fun(void)
{
    static int i = 0 ;
    std::cout << i << std::endl;
    return i;
}
int main(void)
{
    // 1.Convert from decimal to binary?
    std::cout<<std::bitset<8>(15)<<std::endl;


    //2.Convert from string to data type ?
    std::string number{"123"};
    int n=std::stoi(number);
    std::cout<<n<<std::endl;

    // 3.Find Number in array ?

    int arr[] = {1, 2, 3, 4, 5, 0, 6, 7, 8};

    // Find the first occurrence of 0 in the array
    auto add = std::find(std::begin(arr), std::end(arr), 0);

    // Check if the element was found
    if (add != std::end(arr)) {
        std::cout << "Element found at index: " << std::distance(std::begin(arr), add) << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }



    // check if the character is digit ?
    try {
        int converted = std::stoi("5");
        std::cout << "Converted value: " << converted << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    char ch{'a'};
    if(std::isdigit(ch))
    {
        std::cout << "The character is a digit." << std::endl;    
    } 
    else 
    {
        std::cout << "The character is not a digit." << std::endl;
    }

    // -check if all the array is even ?
    int arr1[] {0,2,4,5,6,6};
    bool flag = false;
    for (int i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++)
    {
        if(arr1[i] %2 != 0)
        {
            flag = true;
            break;
        }
    }

    if(flag)
    {
        std::cout << "All the array is not even." << std::endl;
    }
    else
    {
        std::cout << "All the array is even." << std::endl;
    }
    

    //-check if there is any value of array is even ?
    int arr2[] {1,3,5,7,9,11,2,4,6};
    bool flag1 = false;
    for (int i = 0; i < sizeof(arr2)/sizeof(arr2[0]); i++)
    {
        if(arr2[i] %2 == 0)
        {
            std::cout << "There is value in array is even." << std::endl;
            flag1 = true;
            break;
        }
    }
    if(!flag1)
    {
        std::cout << "There is no value in array is even." << std::endl;
    }


    // fun retern reference 
    fun() = 10 ;    // 0 default value of i above 
    fun() = 0;      // 10 the value changed to 10 from the first call


    // 3- fill array from 10 to 10000 sequentially without using loop

    std::vector<int> myArray;

    // Using std::iota and vector to store 
    myArray.resize(9991); // To store 10 to 10000 inclusive
    std::iota(myArray.begin(), myArray.end(), 10);

    // Output a few elements as an example
    std::cout << "First 10 elements: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Using std::iota and array to store 

    int arraa[9991];
    // Using std::iota
    std::iota(std::begin(arraa), std::end(arraa), 10);
    std::cout << "First 10 elements: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << arraa[i] << " ";
    }
    std::cout << std::endl;

    // Using recursion
    std::vector<int> anotherArray;
    fillArray(anotherArray, 10, 10000);



    // Output a few elements as an example
    std::cout << "First 10 elements (using recursion): ";
    for (int i = 0; i < 10; ++i) {
        std::cout << anotherArray[i] << " ";
    }
    std::cout << std::endl;

    // 4-try and / or

    int x = 10 ;
    int y = 20 ;
    if(x == 10 and y == 20 )
    {
        std::cout << "x = 10 and y = 20" << std::endl;
    }

    if(x == 10 or y == 10)
    {
        std::cout<<"may x == 10 or  y == 10 "<<std::endl;    
    }

    //5- calculate accumulate of array
    int array[] = {10,20,30};

    int sum = std::accumulate(std::begin(array),std::end(array),0 /*start value of sum*/ );
    std::cout<<sum<<std::endl;

    return 0;
}