

/*

const Member Functions & const Class Objects
 Constant member functions are those functions that are denied permission to change the values of the data members of their class
 the keyword const is appended to the function prototype and also to the function definition header.
 the objects of a class can also be declared as const.
 Any attempt to change the data member of const objects results in a compile-time error.
 Constant object can only call constant members.
 When a function is declared as const, it can be called on any type of object(const,non-const)
 Non-const functions can only be called by non-const objects.
 Constant objects are initialized at the time of decleration using constructor


*/


/*


======= Static Member Variables =======
 Member variables qualified with static keyword
 Not part of the object
 Belong to the class.
 Only one copy exists
 Shared between objects
 Cannot be initialized inside the class
 Have to be defined outside the class for initialization
 Default initialization assigns default value of the type
//Car.h
	class Car{ static int totalCars;
//Car.cpp
	int Car::totalCars; //Default init to 0

======= Static Member Functions =======
 Functions qualified with static keyword
 Required only in declaration
 Belong to class and not objects
 Do not receive this pointer
 Cannot access non-static members of the class
 Can be invoked directly through the class name
 static member function can be called even if no class objects.
 static member function can only access
	1. static data member 
	2. other static member functions
	3. any other functions from outside the class.



*/
#include<iostream>
class car
{
public:
	car();
	car(float fuel,float speed,int passengers,int const_value);
	~car();
	void FillFuel(float fuel);
	void Accelerate(void);
	void Break(void);
	void AddPassengers(int passengers);
	void set_values(float ammount, float speed, int pass);
	void Dashboard(void);
	static void Show_Total_Cars(void);
	void Const_Function(int temp)const;

	//Overload const method
	void fun(int x)
	{
		std::cout<<"normal function x = "<<x<<std::endl;
	}
	void fun(int x) const
	{
		std::cout<<"const function x = "<<x<<std::endl;
    }

private:
	float fuel;
	float speed;
	int passengers;
	//auto x ;		// error auto is not allowed here
	static int static_TotalCars;
	static int static_member1;
	static int static_member2;
	const int const_value;//must initialized here or within the constrictor 
	// we can't use the default constructor without initialize this const member 
	const static int static_const_value1 = 10 ;
	const static int static_const_value2  ;
	static const int static_const_value3  ;
};


int car::static_TotalCars = 0;
int car::static_member1 = 10;
int car::static_member2 = 0;
const int car::static_const_value2 = 20;

car::car():const_value(0)
{
	static_TotalCars++;
	fuel = 0;
	speed = 0;
	passengers = 0;
	
	std::cout << "default constructor " << std::endl;
}

car::car(float fuel, float speed, int passengers, int const_value):fuel(fuel), speed(speed), passengers(passengers), const_value(const_value)//Initialization Lists
{ 
	//this->fuel = fuel;
	//this->speed = speed;
	//this->passengers = passengers;
	

	// error because const_value is constant must initialize in the Initialization Lists or within the class
	//this->const_value = const_value;          // error
	//const_value = 0;						// error   
	


	std::cout << "parametarize constructor " << std::endl;
	static_TotalCars++;
}

car::~car()
{
	static_TotalCars--;
	std::cout << "destructor " << std::endl;
}

void car::FillFuel(float fuel)
{
	this->fuel += fuel;
}

void car::Accelerate(void)
{
	speed++;
	fuel -= 0.5f;
}

void car::Break(void)
{
	speed = 0;
}

void car::AddPassengers(int passengers)
{
	this->passengers = passengers;
}

void car::set_values(float ammount, float speed, int pass)
{
	fuel = 0;
	speed = 0;
	++pass;
}

void car::Dashboard(void)
{
	std::cout << "fuel " << fuel << std::endl;
	std::cout << "speed " << speed << std::endl;
	std::cout << "passengers " << passengers << std::endl;
}


void sayhello(void)
{
	std::cout << "hello " << std::endl;
}
void car::Show_Total_Cars(void)
{
	std::cout << "TotalCars " << static_TotalCars << std::endl;
	// static member function can access any other functions from outside the class.
	sayhello();
	static_TotalCars ++ ; 
	//fuel = 10;//error Cannot access non-static members of the class

}

void car::Const_Function(int temp) const
{
	// the const function can't change any parameter is the class
	//passengers = 10;	//error
    int x = 10 ; 
    x ++ ; 
    temp = x ; 
    ////////// valid 

	std::cout << "this is const function" << std::endl;
}



int main(void)
{
	// we can called the static function with the name of class because it related to the class not the object 
	car::Show_Total_Cars();
	car car1(6, 200, 5,10),car2,car3,car4;
	// we can't create a default constructor if we not set the const value on it 
	car1.FillFuel(20);
	car1.Accelerate();
	car1.Accelerate();
	car1.Accelerate();
	car1.Accelerate();
	car1.Accelerate();
	car1.Accelerate();
	car1.Dashboard();
	car::Show_Total_Cars();
	// =============================================================
	std::cout<<"normal instance"<<std::endl;

	car c1;					// normal instance
	c1.Dashboard();			// 	normal instance can access non-const methods 
	c1.Const_Function(20);	//  normal instance can access const methods 
	std::cout<<"const instance"<<std::endl;
	const car c2;
	c2.Show_Total_Cars();     //  const instance can access static methods 
	c2.Const_Function(20);    //  const instance can access const methods 
//	c2.Accelerate();		  // error  const instance can't access normal methods

	car c3;
	c3.fun(50);    //normal function x = 50
	const car c4;	
	c4.fun(50);		//const function x = 50

}