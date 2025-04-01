/*

Delegating Constructor
 Allows a constructor to invoke another constructor
 Replacement for common initialization
 Reduces duplicate initialization code in multiple constructors
	class Class{
	Class(): Class(val1, val2){
	Class(arg1, arg2){
	//Initialization code
*/

#include <iostream>

// Delegating Constructor
class MyClass
{
public:
	MyClass();
	~MyClass();
	MyClass(int a);
	MyClass(int a, int b);
	MyClass(int a, int b, int c);

private:
	int a;
	int b;
	int c;
};

MyClass::~MyClass()
{
	std::cout << "MyClass destructor" << std::endl;
}
MyClass::MyClass() : MyClass(0)
{
	std::cout << "MyClass default constructor" << std::endl;
}

MyClass::MyClass(int a) : MyClass(0, 0)
{
	std::cout << "MyClass (int a)" << std::endl;
}

MyClass::MyClass(int a, int b) : MyClass(0, 0, 0)
{
	std::cout << "MyClass (int a, int b)" << std::endl;
}
MyClass::MyClass(int a, int b, int c)
{
	std::cout << "MyClass (int a, int b, int c)" << std::endl;
}

int main(void)
{
	MyClass M1;
	// this is the output
	/*
	MyClass (int a, int b, int c)
	MyClass (int a, int b)
	MyClass (int a)
	MyClass default constructor
	MyClass destructor
	*/

	return 0;
}