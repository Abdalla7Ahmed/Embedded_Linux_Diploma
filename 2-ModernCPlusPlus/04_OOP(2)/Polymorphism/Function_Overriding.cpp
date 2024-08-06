#include<iostream>
class Base
{
public: 
    int B=5;
    virtual void fun1(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
    virtual void fun2(){ std::cout<<__PRETTY_FUNCTION__<<std::endl ;}
};
class child1 : public Base
{
public: 
    int C1=10;
    void fun1(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
    void fun2(){ std::cout<<__PRETTY_FUNCTION__<<std::endl ;}
};
class child2 : public Base
{
public: 
    int C2=20;
    void fun1(){std::cout<<__PRETTY_FUNCTION__<<std::endl;}
    void fun2(){ std::cout<<__PRETTY_FUNCTION__<<std::endl ;}
};

void print_fun_ref(Base& base)
{
    base.fun1();
    base.fun2(); 
}
void print_fun_pointer(Base*base)
{
    base->fun1();
    base->fun2(); 
}
int main(void)
{
    Base B1;
    B1.fun1();  // void Base::fun1()
    B1.fun2();  // void Base::fun2()
    std::cout<<sizeof(B1)<<std::endl;  // 16 byte   --> (int B) + 8 byte for virtual pointer + 4 byte padding
    child1 ch1;
    child2 ch2;
    std::cout<<sizeof(ch1)<<std::endl;  // 16 byte   --> (int c1) + (int B) + 8 byte for virtual pointer
    std::cout<<sizeof(ch2)<<std::endl;  // 16 byte   --> (int c2) + (int B) + 8 byte for virtual pointer
    Base *B1ptr;
    B1ptr = &ch1;
    B1ptr->fun1();  //void child1::fun1()
    B1ptr->fun2();  //void child1::fun2()
    B1ptr = &ch2;
    B1ptr->fun1();  //void child2::fun1()
    B1ptr->fun2();  //void child2::fun2()
    print_fun_ref(ch1);  // virtual void child1::fun1()   virtual void child1::fun2()
    print_fun_ref(ch2);  // virtual void child2::fun1()   virtual void child2::fun2()

    print_fun_pointer(&ch1);   // virtual void child1::fun1()   virtual void child1::fun2()
    print_fun_pointer(&ch2);   // virtual void child2::fun1()   virtual void child2::fun2()
    
    return 0;
}