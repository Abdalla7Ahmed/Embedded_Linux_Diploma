/*
In object-oriented programming (OOP), encapsulation, inheritance, and polymorphism are three fundamental concepts. 
Here's an explanation of each:

1. Encapsulation:
Encapsulation is the process of bundling data and methods (or functions) that operate on that data into a single unit 
called a class. It allows you to hide the internal details of an object and provide a public interface through which 
other objects can interact with it. The data within the class is typically accessed and manipulated through methods, 
which provides control over how the data is modified. Encapsulation helps achieve data abstraction, data hiding, 
and modularity, making code more maintainable and reducing dependencies between different parts of a program.

2. Inheritance:
Inheritance is a mechanism that allows a class (called a "subclass" or "derived class") to inherit properties and behaviors 
from another class (called a "superclass" or "base class"). The subclass can extend or specialize the functionality of 
the superclass by adding new methods or overriding existing methods. Inheritance promotes code reuse and supports 
the concept of "is-a" relationships, where a subclass is a more specific type of the superclass. The subclass inherits 
the attributes and behaviors of the superclass, allowing you to create hierarchical relationships between classes.

3. Polymorphism:
Polymorphism refers to the ability of objects of different classes to be treated as objects of a common superclass. 
It allows you to write code that can work with objects of different types and still perform the appropriate behavior 
based on the actual type of the object. Polymorphism is typically achieved through method overriding and method overloading. 
Method overriding occurs when a subclass provides a different implementation of a method that is already defined in 
its superclass. Method overloading happens when a class has multiple methods with the same name but different parameter lists. 
Polymorphism enables code to be more flexible, extensible, and modular, as it allows objects to be used interchangeably 
based on their common interface or superclass.

To summarize, encapsulation focuses on bundling data and methods together, inheritance allows 
classes to inherit and extend the functionality of other classes, and polymorphism enables objects of different 
types to be treated uniformly based on a common interface or superclass. These concepts are key elements of OOP and 
help in designing modular, reusable, and maintainable code.
*/
#include <iostream>
using namespace std;

// Encapsulation
class Shape {
protected:
    int width;
    int height;
public:
    void setDimensions(int w, int h) {
        width = w;
        height = h;
    }
    virtual void calculateArea() = 0;  // Pure virtual function
};

// Inheritance
class Rectangle : public Shape {
public:
    void calculateArea() override {
        int area = width * height;
        cout << "Rectangle area: " << area << endl;
    }
};

class Triangle : public Shape {
public:
    void calculateArea() override {
        int area = (width * height) / 2;
        cout << "Triangle area: " << area << endl;
    }
};

// Polymorphism
void printArea(Shape* shape) {
    shape->calculateArea();
}

int main() {
    Rectangle rectangle;
    rectangle.setDimensions(5, 3);
    
    Triangle triangle;
    triangle.setDimensions(4, 6);
    
    printArea(&rectangle);  // Rectangle area: 15       Polymorphic call       
    printArea(&triangle);   // Triangle area: 12        Polymorphic call

    return 0;
}