#include "header.hpp"

void fun(int *ptr)
{
	std::cout << __FUNCTION__ << std::endl;
}

void fun(int x)
{
	std::cout << __FUNCTION__ << std::endl;
}
void Pointer_test(void)
{
	/*

	Pointer
	� Points to another type
	� Holds the memory address of another variable
	� Used for indirect access to other variables
	� Need not be initialized during declaration
	� Declared with * operator
	int * ptr;
	int *p1, *p2, *p3, p4;      note that --> p4 is not a pointer
	*/

	int x{10};
	int *ptr1 = &x;
	// float* ptr3 = &x;   // error initializing cann't convert from int to float
	void *ptr4 = &x; // wild pointer

	std::cout << " x = " << x << std::endl;
	std::cout << " address of x  = " << &x << std::endl;
	std::cout << " address of x  = " << ptr1 << std::endl;
	std::cout << " address of x  = " << ptr4 << std::endl;

	/*
	Null Pointer
	� NULL is a macro in C & pre-C++11
	� It is defined as 0 in most compilers
	� Used to initialize pointer types
	� C++11 introduced a new type of null called nullptr
	� This is type safe and better than NULL macro
	Always use nullptr to initialize a pointer, instead of NULL macro

	*/

	int *ptr5 = nullptr;
	// std::cout << *ptr5 << std::endl;    //crash --> Exception thrown: read access violation.
	//*ptr5 = 10;						  //crash --> write access violation
	int *ptr6 = NULL;
	// std::cout << *ptr6 << std::endl;    //crash --> Exception thrown: read access violation.
	//*ptr6 = 10;                         //crash --> write access violation

	fun(nullptr); // fun(int *ptr)
	// fun(NULL);     // compiler error call of overloaded ‘fun(NULL)’ is ambiguous can call fun(int *ptr) or fun(int x)

	fun(static_cast<int *>(NULL)); // fun(int *ptr)

	/*
	In C++, `nullptr` is a special keyword that represents a null pointer of any type.
	On the other hand, `NULL` is a preprocessor macro that is typically defined as `0` or `(void*)0`.

	1. `fun(nullptr);`: This calls the function `fun` with a `nullptr` argument. Since `nullptr`
	represents a null pointer of any type, the function `fun(int *ptr)` is a perfect match because
	it takes a pointer to an `int`. Therefore, this call will invoke the `fun(int *ptr)` overload.

	2. `fun(NULL);`: This calls the function `fun` with a `NULL` argument. The `NULL` macro is typically defined
	as `0` or `(void*)0`. In this case, the compiler encounters an ambiguity because both `fun(int *ptr)` (taking
	a pointer to an `int`) and `fun(int x)` (taking an `int`) can be called with an argument of value `0`.
	The compiler cannot determine which overload to choose, and hence it raises an error stating that the call to `fun(NULL)` is ambiguous.

	To resolve the ambiguity, you can explicitly cast `NULL` to the desired type. For example,
	if you want to call `fun(int *ptr)`, you can cast `NULL` to `int*` as follows: `fun(static_cast<int*>(NULL));`.
	Alternatively, you can use `nullptr`, which is the preferred way in modern C++: `fun(nullptr);`.

	*/
}