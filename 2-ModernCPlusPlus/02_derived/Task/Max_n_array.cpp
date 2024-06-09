//1- create a function to find the maximum number of array

#include<iostream>
#include<iterator>
#include<functional>
int max_n_array(int *arr,int size)
{
    int max{};
    for(int i=0;i<size;i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    
    return max;

}
int main(void)
{
    int size ;
    std::cout<<"Enter the number of elements"<<std::endl;
    std::cin>>size;
    int arr[10]{0};
    for(int i=0;i<size;i++)
    {
        std::cout<<"Enter element "<< i+1 <<std::endl;
        std::cin>>arr[i];
    }
    std::cout<<"Max number in array is "<<max_n_array(arr,size)<<std::endl;


    int arr2[10]{1,2,9,4,5,6,10,25,9,48};
    std::cout<<"another way without using function ========== "<<std::endl;
    std::sort(std::begin(arr),std::end(arr),
    [](int first,int last)
    {
        return first > last;
    });

    std::cout<<"Max number in array is "<<arr[0]<<std::endl;



    return 0;
}