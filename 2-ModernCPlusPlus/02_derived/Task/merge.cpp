// 4- merge two arrays together
// 2- create a function to search to the number in the array which number is taken from user

#include<iostream>
#include <algorithm>

void merge(int *arr1,int *arr2,int *arr3,int size1,int size2)
{
    for(int i=0;i<(size1+size2);i++)
    {
        if(i < size1 )
        {
            arr3[i] = arr1[i];
        }
        else 
        {
            arr3[i] = arr2[i-size1];

        }
    }

}
int main(void)
{
    int array1[6] = {1,2,3,4,5,6};
    int array2[4] = {7,8,9,10};
    int array3[10]{};
    merge (array1,array2,array3,6,4);

    for(auto i : array3)
    {
        std::cout<<i<<"  ";
    }
    std::cout<<"\n";


    // ====================================================

    int arr1[] = {1, 3, 5, 7, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8, 10};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int mergedSize = size1 + size2;
    int merged[mergedSize];

    // Merge the two arrays into a single sorted array
    std::merge(arr1, arr1 + size1, arr2, arr2 + size2, merged);

    // Print the merged array
    for (int i = 0; i < mergedSize; i++) {
        std::cout << merged[i] << " ";
    }
    std::cout << std::endl;



    return 0;
}