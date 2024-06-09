#include"header.hpp"



class A {
public:
    int x=10;
    void fun_a()
    {
        std::cout << "In class A\n";
    }
};


class B {
public:
    int x=12;
    void fun_b()
    {
        std::cout << "In class B\n";
    }
};


void Casting_test()
{
/*
1.Static_cast 
 This is the simplest type of cast which can be used. 
 It is a compile time cast.It does things like implicit conversions 
 between types (such as int to ﬂoat, or pointer to void*),
 and it can also call explicit conversion functions (or implicit ones).
*/
    int a=10;
    char c='a';

    int *p=&a;
    std::cout<<"a is "<<*p<<std::endl;
    //int *p2=&c;    // invalid ‘static_cast’ from type ‘char*’ to type ‘int*’
    //int *p3=static_cast<int *>(&c);   // invalid ‘static_cast’ from type ‘char*’ to type ‘int*’
    float f=static_cast<float>(a); 
    std::cout<<"f is "<<f<<std::endl;


/*
2.const_cast
const_cast is used to cast away the constness of variables
*/

    const int c1=10;
    const int *pc1=&c1;

    const int *pc = pc1;  // no error
    //int *cpc=pc1;  //invalid conversion from ‘const int*’ to ‘int*’
    //int *cpc=static_cast<int *>(pc1); // invalid ‘static_cast’ from type ‘const int*’ to type ‘int*’
 
    int *cpc=const_cast<int *>(pc1);

/* 
3.reinterpret_cast
It is used to convert a pointer of some data type into a pointer of another data type,
even if the data types before and after conversion are diﬀerent.

*/
    int re{};
    int *pre=&re;
    std::cout<<typeid(pre).name()<<std::endl;  // pi   --> pointer to integer
    float *pre1 = reinterpret_cast<float *>(pre);
    std::cout<<typeid(pre1).name()<<std::endl;  // pf   --> pointer to float

    //creating object of class B
    B* x = new B();
    // converting the pointer to object
    A* new_a = reinterpret_cast<A*>(x);
    // accessing the function of class A
    new_a->fun_a();
    // In class A
    std::cout <<new_a->x<<std::endl; // 12
}