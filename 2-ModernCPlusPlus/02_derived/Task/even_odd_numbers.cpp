// 5-find the even and odd numbers in the array

#include <iostream>
#include <algorithm>
void print_even_odd(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            std::cout << arr[i] << "--> is even" << std::endl;
            ;
        }
        else
        {
            std::cout << arr[i] << "--> is odd" << std::endl;
            ;
        }
    }
}

int main(void)
{
    int arr[] = {10, 20, 7, 15, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    print_even_odd(arr, size);
    return 0;
}