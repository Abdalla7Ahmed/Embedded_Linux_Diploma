#include"header.hpp"
void print(std::string s)
{
	std::cout<<s<<std::endl;
}
void print(int x)
{
	std::cout<<x<<std::endl;
}
void print(float x)
{
	std::cout << x << std::endl;
}



class A {
public:
	int x=10;
	void fun_a()
	{
		std::cout <<" In class A\n";
	}
};

class B {
public:
	int x=12;
	void fun_b()
	{
		std::cout <<"In class B\n"; 
	}
};


void test_Conversions(void)
{
	/*
	Type Conversions
	� Conversion between types
	� Performed through casts
	� Ordered by compiler (implicit) or user(explicit)
	� Explicit conversion uses casting operators
	� Conversion between
		� basic & basic
		� basic & user-defined
		� user-defined & basic
		� user-defined & user-defined
	*/
	int a(5), b(2);
	float c ;
	c = a / b;
	print(c);			// 2 
	c = (float)a / b;   
	print(c);			// 2.5 
	c =static_cast<float>(a) / b;
	print(c);			// 2.5 
	// why we don't use C cast ?
	int p1;
	char* c1;
	//c1 = &p1;      // error
	c1 =(char *) & p1;      // allowed
	// c1 = static_cast<char*>(&p1);      // error static cast will check first if this conversion is valid or not 
	c1 = reinterpret_cast<char*>(&p1);    // it allowd the conversion between different types 
	
	const int y = 10;
	const int *z = &y; 
	//int* Y = reinterpret_cast<int*>(&y);	// error
	int* Y = const_cast<int*>(&y);
	int* Z = const_cast<int*>(z);

	*Y = 20 ; 	
	print(y);   // 10
	print(*Y);   // 20



	// creating object of class B
	B* x = new B();
	// converting the pointer to object
	A* new_a = reinterpret_cast<A*>(x);
	// accessing the function of class A
	new_a->fun_a();
	// In class A
	std::cout <<new_a->x<<std::endl; // 12

 }