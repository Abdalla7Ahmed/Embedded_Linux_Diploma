#include<iostream>

class Base
{
public:
    int B=10;
    Base(){};
    ~Base(){};
    void fun()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
};

class child1 : public Base 
{
public:
    int C1=20;

    child1(){};
    ~child1(){};
    void fun()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
};

class child2 : public Base
{
public:
    int C2=20;

    child2(){};
    ~child2(){};
    void fun()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
        Base::fun();
    }
};

class GrandChild : public child1,public child2 
{
public:
    int GC=20;

    GrandChild(){};
    ~GrandChild(){};
    void fun()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
};



int main(void)
{

    GrandChild G;
    //G.B1=20;  //  request for member ‘B’ is ambiguous
    G.child1::B = 100 ;
    std::cout<<G.child1::B<<std::endl;  //100
    std::cout<<G.child2::B<<std::endl;  // 10 
    G.child2::fun();

    

    return 0;
}