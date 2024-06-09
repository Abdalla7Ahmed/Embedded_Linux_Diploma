#include <iostream>
#include <string>
#include <cstring>
class Shape
{
public:
    virtual void shape_area() = 0;
};
class Circle : public Shape
{
public:
    void shape_area(void);
};
class Rectangle : public Shape
{
public:
    void shape_area(void);
};

class Triangle : public Shape
{
public:
    void shape_area(void);
};

void get_area(Shape *Shape);