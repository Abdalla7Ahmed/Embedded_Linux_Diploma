#include"header.hpp"


int sum(int x, int y)
{
	return x + y;
}

float average(int sum, int number)
{
	return (sum / number);
}
void Auto_test(void)
{
	auto x0 = 20;                       // x0 is int
	std::cout<<"x0 type is "<<typeid(x0).name()<<std::endl;
	auto x1 = 20.5;                     // x1 is double
	std::cout<<"x1 type is "<<typeid(x1).name()<<std::endl;
	auto x3 = 20.5F;                    // x2 is float
	std::cout<<"x3 type is "<<typeid(x3).name()<<std::endl;
	auto x4 = 's';                      // x4 is char
	std::cout<<"x4 type is "<<typeid(x4).name()<<std::endl;
	auto x5 = "hello char ";            // x5 is const char *
	std::cout<<"x5 type is "<<typeid(x5).name()<<std::endl;
	auto x6 = std::string("Hello string");   // x6 is string
	std::cout<<"x6 type is "<<typeid(x6).name()<<std::endl;

	auto a1 = 10;				// int
	auto a2 = 23.5f;		    // float
	auto a3 = 1 + 5;			// int
	auto a4 = a1 + a3;			// int
	auto a5 = a1 + 32.5f;		// float
	const auto a6 = 10;			// const int
	const int a7 = 20;
	auto a8 = a7;				// int
	const auto a9 = a7;			// const int

	auto& b1 = a1;				// int
	auto& b2 = a6;				// const int because a6 is const int

	auto ptr1 = &a1;			// int *ptr
	auto ptr2 = &a6;			// const int *ptr2
	// auto with function return type
	auto y =  sum(5, 6);		// y is int
	auto avg = average(562, 5); // avg is float

	// initializer list 
	auto list = { 1,2,3,4,5 };   // initializer_list copy initialization must here
	std::cout<<"xlist type is "<<typeid(list).name()<<std::endl;
 
	//auto list2{ 1,2,3,4,5 };	 // error
	auto var{ 1 };			 // var is int type

}