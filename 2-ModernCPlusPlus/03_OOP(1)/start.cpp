#include <iostream>

/*

Encapsulation in the context of classes in object-oriented programming (OOP) 
refers to the bundling of data (attributes) and methods (functions) that operate 
on the data into a single unit, known as a class. It allows the internal representation 
of an object to be hidden from the outside and only exposes the necessar

*/

class Car {
private:
    int speed; // Private data member

public:
    Car();
    ~Car();
    void setSpeed(int s);
    int getSpeed(void);
    void printSpeed(void);
    void test();

};

void Car::setSpeed(int s) {
    speed = s;
}

    // Public member function to get speed
int Car::getSpeed() {
    return speed;
}
    // Public member function to print speed
void Car::printSpeed() {
    std::cout << "speed is "<<speed << std::endl;
}

void Car::test()
{
    std::cout<<"test"<<std::endl;
}

Car::Car()
{
    std::cout<<"Constructor  "<<std::endl;

}
Car::~Car()
{
    std::cout<<"Destructor "<<std::endl;
}


int main() {
    Car myCar;
    myCar.setSpeed(60); // Encapsulated method call
    int currentSpeed = myCar.getSpeed(); // Encapsulated method call
	myCar.printSpeed();
	//myCar.speed = 20 ; // Error speed is private within this context

    return 0;
}
