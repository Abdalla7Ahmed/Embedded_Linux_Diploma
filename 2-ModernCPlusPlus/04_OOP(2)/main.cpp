#include"operator_overloading.hpp"
#include <vector>
#include<iterator>
#include<functional>


void fun(int a)
{
    std::cout<<__PRETTY_FUNCTION__<<std::endl;
}

void fun(const Complex &a )
{
    std::cout<<__PRETTY_FUNCTION__<<std::endl;
}
int main(int argc, const char** argv) 
{
 
    Complex c1(10,20.5);
    Complex c2(40,90.6);
    Complex c3 = c2-c1; 
    c3.print();
    /*
    operator+   
    15 + i15
    */

   int real1 = c1 - 10 ;
   int real2 = c1 + 10 ;
   float imag1 = c1 - static_cast<float>(10.5) ;
   float imag2 = c1 + static_cast<float>(10.2) ;
   std::cout<<real1<<" "<<real2<<std::endl;
   std::cout<<imag1<<" "<<imag2<<std::endl;
/*
this map to 
  Complex c1 = Complex(10, 20.5);
  Complex c2 = Complex(20, 30.5);
  Complex c3 = c2.operator-(c1);
  c3.print();
  int real1 = c1.operator-(10);
  int real2 = c1.operator+(10);
  float imag1 = c1.operator-(static_cast<float>(10.5));
  float imag2 = c1.operator+(static_cast<float>(10.199999999999999));
*/

    std::vector<Complex> sorting {c1, c2, c3};
    std::sort(sorting.begin(), sorting.end());  
    // without implement the operator overloading < it will give an error 
    ///usr/include/c++/11/bits/predefined_ops.h:69:22: error: no match for ‘operator<’ (operand types are ‘Complex’ and ‘Complex’) 69 |       { return *__it < __val; }
    for(auto x : sorting)
    {
        x.print();
        /*
        10 + i20
        15 + i15    
        25 + i35
        */
    }

    std::cout<<"========================== temp object ============================"<<std::endl;
    Complex().print(); // call default constructor + call print function + call destructor
    /*
    Complex::Complex()
    40 + i90.6
    Complex::~Complex(
    */
    Complex();         // call default constructor + call destructor
    /*
    Complex::Complex()
    Complex::~Complex()
    */
    std::cout<<"================================================================"<<std::endl;

    std::cout<<"========================== functor ============================"<<std::endl;
    Complex c4{12,456.6};
    c4();   // functor
    /*
    Complex::Complex()
    void Complex::operator()(void)
    real is 12 and imag is 456.6
    */
    std::cout<<"================================================================"<<std::endl;


    std::cout<<"========================== pointer to function ============================"<<std::endl;

    std::function<void(void)> t = Complex();
    t();   // functor
    /*
    Complex::Complex()
    Complex::~Complex()
    void Complex::operator()(void)
    real is 40 and imag is 90.6
    */
    std::cout<<"================================================================"<<std::endl;


    std::cout<<"========================== post/pre ============================"<<std::endl;
    Complex c5{10,11.6};
    ++c5;
    c5.print();  //11 + i12.6
    --c5;
    c5.print();  //10 + i11.6
    Complex c6 = c5++;
    c6.print(); //10 + i11.6
    c5.print(); //11 + i12.6
    std::cout<<"================================================================"<<std::endl;

    std::cout<<"========================== friend operator ============================"<<std::endl;
    Complex c7{10,11.6};
    int y = c7+10;
    std::cout<<y<<std::endl;
    /*
    int Complex::operator+(int)
    20
    */
    int z = 30 + c7;  // error no match for ‘operator+’ (operand types are ‘int’ and ‘Complex’) until we write the friend operator
    std::cout<<z<<std::endl;
    /*
    int operator+(int, const Complex&)
    40
    */
    std::cout<<"================================================================"<<std::endl;

    std::cout<<"========================== Implicit Conversion ============================"<<std::endl;
    // Complex c8=5; // in assemble  ==> call 0x555555558266 <Complex::Complex(int)>  
    // the compiler make Implicit Conversion --> Complex c8=Complex(8);
    // misra rule 12-1-3 
    //All constructors that are callable with a single argument of fundamental type shall be declared explicit.
    // make the constructor explicit , the compiler doesn't make Implicit Conversion  --> explicit Complex(int real);
    // Complex c8=5; give error now , to solve this 
    Complex c8=Complex(5);  // work
    // what is the issue , why the rule said that 
    fun(5);  // call  void fun(int a);
    fun(Complex(5)); // call void fun(const Complex &a )
    // if the function fun(int a) doesn't exist :- 
    // with explicit it will give error
    // without explicit it will work and make Implicit Conversion to 5 as Complex(5) , both case will call void fun(const Complex &a )
    //std::cout<<c8<<std::endl;  // without explicit with operator int(){return real;} it will work 
    std::cout<<static_cast<int>(c8)<<std::endl;  // it work 
    std::cout<<"================================================================"<<std::endl;

    return 0;
}