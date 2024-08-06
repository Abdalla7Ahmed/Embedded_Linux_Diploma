// 2- create a function to search to the number in the array which number is taken from user

// 3- delete number in array

#include <iostream>
#include <algorithm>

int main(void)
{
    int arr[] = {10, 20, 7, 15, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    // Find the position of the target value in the array
    int *position = std::find(arr, arr + size, target);

    // Check if the value was found
    if (position != arr + size)
    {
        // Calculate the index of the found element
        int index = std::distance(arr, position);

        // Shift the elements after the target value to the left
        std::copy(position + 1, arr + size, position);

        // Decrease the size of the array
        size--;

        std::cout << "Element " << target << " deleted from the array." << std::endl;

        // Print the updated array
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}