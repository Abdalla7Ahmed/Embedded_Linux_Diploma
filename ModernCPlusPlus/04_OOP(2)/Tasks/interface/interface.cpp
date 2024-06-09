#include "interface.hpp"

void Circle::shape_area(void)
{
    std::cout << "this is the circular area" << std::endl;
}

void Rectangle::shape_area(void)
{
    std::cout << "this is the Rectangle area" << std::endl;
}

void Triangle::shape_area(void)
{
    std::cout << "this is the Triangle area" << std::endl;
}

void get_area(Shape *Shape)
{
    Shape->shape_area();
}