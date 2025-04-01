#include "header.hpp"
void print(std::string s)
{
	std::cout << s << std::endl;
}
void print(int x)
{
	std::cout << x << std::endl;
}
// scoped enum
enum class color : int
{
	RED,
	GREEN,
	BLUE
};
// class --> scoped enum , int --> the size of enum
void Fillcolore(color c)
{
	switch (c)
	{
	case color::RED:
		print("the color is RED");
		break;
	case color::GREEN:
		print("the color is GREEN");
		break;
	case color::BLUE:
		print("the color is BLUE");
		break;
	default:
		break;
	}
}

enum class traffic : char
{
	RED = 'c',
	GREEN,
	YELLOW
};
void enum_test(void)
{
	color c = color::RED;
	Fillcolore(c);			  // the color is RED
	Fillcolore(color::GREEN); // the color is GREEN
	Fillcolore(color::BLUE);  // the color is BLUE

	traffic r = traffic::YELLOW;
	// color c = 5;   // error
	color c1 = static_cast<color>(5);
	std::cout << (int)c1 << std::endl; // 5
	// int y = RED; // if we not has scoped enum this expression is valid
	int y = static_cast<int>(color::RED);
	std::cout << "the size of color enum is " << sizeof(color) << std::endl;	 // 4 byte
	std::cout << "the size of traffic enum is " << sizeof(traffic) << std::endl; // 1 byte
}