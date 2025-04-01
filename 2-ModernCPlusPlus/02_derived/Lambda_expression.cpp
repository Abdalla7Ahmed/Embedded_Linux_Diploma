#include "header.hpp"
#include <iterator>
#include <functional>
int g = 10;
void Test_Lambda_expression(void)
{

  // C++ 11 introduced lambda expressions

  /*
   Syntax :
  [capture](parameters)->return-type
  {
      defination
  }
  */

  [](int x, int y)
  {
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
  }(5, 20);

  // we can't call this lambda expression again

  //    auto fun =  [](int x,int y)
  //    {
  //         std::cout<<"x = "<<x<<std::endl;
  //         std::cout<<"y = "<<y<<std::endl;
  //    };
  //     fun(50,300);

  // this will replaces by this class
  class __lambda_16_16
  {
  public:
    inline /*constexpr */ void operator()(int x, int y) const
    {
      std::operator<<(std::cout, "x = ").operator<<(x).operator<<(std::endl);
      std::operator<<(std::cout, "y = ").operator<<(y).operator<<(std::endl);
    }

    using retType_16_16 = void (*)(int, int);
    inline constexpr operator retType_16_16() const noexcept
    {
      return __invoke;
    };

  private:
    static inline /*constexpr */ void __invoke(int x, int y)
    {
      __lambda_16_16{}.operator()(x, y);
    }
  };

  __lambda_16_16 fun = __lambda_16_16{};
  fun.operator()(50, 300);

  int temp = 50;
  auto fun1 = [](int x, int y)
  {
    // x = temp + 100 ;  // error temp’ is not captured we need to capture it
    // to solve this error just pass temp in capture
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
  };
  auto fun2 = [temp](int x, int y)
  {
    x = temp + 100;
    //  temp = 100 ;  //  error assignment of read-only variable ‘temp’ note that operator above is a const
    // to solve this we need pass the temp as a reference not value
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
  };
  fun2(50, 300); // 150 , 300

  auto fun3 = [&temp](int x, int y)
  {
    x = temp + 100;
    temp = 100;

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
  };
  fun3(50, 300);                               // 150 , 300
  std::cout << "temp = " << temp << std::endl; // temp = 100
  auto fun4 = [&](void)
  {
    // capture all by reference
    temp++;
    g++; // it is a global var
    return temp + g;
  };
  std::cout << "temp = " << fun4() << std::endl; // temp = 112

  auto fun5 = [=](void)
  {
    // capture all by value
    // temp ++;  // error   increment of read-only variable ‘temp’
    g++; // no error
    return temp + g;
  };
  std::cout << "temp = " << fun5() << std::endl; // temp = 113

  int t1{5}, t2{6}, t3{7};
  auto fun6 = [=, &t1, &t2](void) -> int
  {
    // capture all by value except t1 and t2
    t1++;
    t2++;
    // t3 ++ ;   // error increment of read-only variable t3
    // temp ++ ;   // error increment of read-only variable temp
    return t1 + t2;
  };
  std::cout << "return  = " << fun6() << std::endl; // return = 13

  auto fun7 = [t1, t2](void) mutable -> void
  {
    // capture all by value but we can modify the variables
    // but this update will be only in this scope mean the values of variables doesn't change outside this scope
    t1 = 10;
    t2 = 10;
    std::cout << "t1 = " << t1 << std::endl; // t1 = 10
    std::cout << "t2 = " << t2 << std::endl; // t2 = 10
  };
  fun7();
  std::cout << "=================" << std::endl;
  std::cout << "t1 = " << t1 << std::endl; // t1 = 6
  std::cout << "t2 = " << t2 << std::endl; // t2 = 7

  auto fun8 = [](auto x1, auto x2)
  {
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;
  };
  // auto not allowed in c++11
  // g++ -std=c++11 main.cpp Lambda_expression.cpp  will give a compiler error
  // use of ‘auto’ in lambda parameter declaration only available with ‘-std=c++14’ or ‘-std=gnu++14’

  // if we compile it by using c++14
  // it will pass
  fun8(10, 8);
  fun8(10.8, 8.5);

  int arr[5]{10, 20, 7, 15, 9};

  std::sort(std::begin(arr), std::end(arr),
            [](int first, int second)
            {
              return first > second;
            });

  for (auto i : arr)
  {
    std::cout << i << std::endl;
  }

  /*

  * The first argument is std::begin(arr), which returns an iterator pointing to the beginning of the array.
  * The second argument is std::end(arr), which returns an iterator pointing to the end of the array.
  * The third argument is a lambda function that defines the comparison criteria for sorting.
    The lambda function takes two integers (first and second) as parameters and returns a boolean value
    indicating whether first should come before second in the sorted order. In this case, the lambda
    function compares the integers in descending order (first > second), meaning that larger numbers
    will come before smaller numbers in the sorted array.
  */
}