// 6-Sort with Lambda: Use lambda functions to sort an array of integers in ascending and descending order.

#include <iostream>
#include <iterator>
#include <functional>

int main(void)
{
    int order_type;
    int arr[] = {10, 20, 7, 15, 9};
    std::cout << "do you want to sort the array in ascending(0) or descending(1) ?" << std::endl;
    std::cin >> order_type;
    std::sort(std::begin(arr), std::end(arr),
              [order_type](int first, int second)
              {
                  if (order_type == 0)
                  {
                      return first < second;
                  }
                  else
                  {
                      return first > second;
                  }
              });

    for (auto i : arr)
    {
        std::cout << i << std::endl;
    }

    return 0;
}