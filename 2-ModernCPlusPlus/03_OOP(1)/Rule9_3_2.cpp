
#include<iostream>

/*

members functions shall not return non-const handles to class data—is typically 
aimed at ensuring that member functions of a class do not return handles
(pointers or references) that allow direct modification of private or 
protected class data without imposing constness.
*/

/*
Explanation:
Consider a scenario where a member function returns a non-const pointer or reference 
to a private data member of a class. This practice can potentially allow external code to 
modify the internal state of the class without any restrictions.
*/

//Example (Non-compliant):
class MyClass1 {
private:
    int data = 0;

public:
    int* getDataPtr() {
        return &data; // Non-const pointer to private data
    }

    int& getDataRef() {
        return data; // Non-const pointer to private data
    }
    void print(void)
    {
        std::cout << data << std::endl;
    }
};


/*

Compliant Solution:
To comply with the rule, you'd provide access to class data through methods that maintain 
const correctness, allowing read-only access or controlled modifications:
*/

class MyClass2 {
private:
    int data=50;

public:
    const int* getDataPtr() const {
        return &data; // Return a const pointer to private data
    }

    int getData() const {
        return data; // Return a copy or const reference to private data
    }
};





int main(void)
{
    MyClass1 obj;
    int *ptr =obj.getDataPtr() ;   
    *ptr = 10;
    obj.print();        // 10 

    MyClass1 obj2;
    obj2.getDataRef() = 20 ;
    obj2.print();      // 20 
    /*
    In the non-compliant example above, getDataPtr() returns a non-const pointer to the private member data.
    This allows external code to directly modify data, violating encapsulation and potentially leading to 
    unintended behavior or inconsistencies within the class.
    */


   MyClass2 obj3;
   const int *ptr1 =obj3.getDataPtr() ;
  // *ptr1 = 30;    // error assignment of read-only location ‘* ptr1’
    
    std::cout << obj3.getData() <<std::endl;
    return 0;
}