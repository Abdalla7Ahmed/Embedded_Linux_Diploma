The Singleton method or Singleton Design pattern is one of the simplest design patterns. It ensures a class only has one instance, and provides a global point of access to it.

```cpp
#include <iostream>

class Singleton
{
private:
    Singleton() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~Singleton() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

public:

    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void display() {
        std::cout << "Hello, Singleton" << std::endl;
    }
};

int main() {
    Singleton::getInstance().display();
    return 0;
}
```
no memory leakage
```bash
abdallah@abdallah:~/Documents/Github/Embedded_Linux_Diploma/2-ModernCPlusPlus/03_OOP(1)/Task$ g++ Singleton.cpp 
abdallah@abdallah:~/Documents/Github/Embedded_Linux_Diploma/2-ModernCPlusPlus/03_OOP(1)/Task$ leakage ./a.out 
==47054== Memcheck, a memory error detector
==47054== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==47054== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==47054== Command: ./a.out
==47054== 
Singleton::Singleton()
Hello, Singleton
Singleton::~Singleton()
==47054== 
==47054== HEAP SUMMARY:
==47054==     in use at exit: 0 bytes in 0 blocks
==47054==   total heap usage: 2 allocs, 2 frees, 73,728 bytes allocated
==47054== 
==47054== All heap blocks were freed -- no leaks are possible
==47054== 
==47054== For lists of detected and suppressed errors, rerun with: -s
==47054== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
there is another way 

```cpp
#include <iostream>

class Singleton
{
public:
    // Static method to access the singleton instance
    static Singleton &getInstance()
    {
        // If the instance doesn't exist, create it
        if (!instance)
        {
            instance = new Singleton();
        }
        return *instance;
    }

    // Public method to perform some operation
    void someOperation()
    {
        std::cout << "Singleton is performing some operation." << std::endl;
    }

    // Delete the copy constructor and assignment operator to prevent copying
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

private:
    // Private constructor to prevent external instantiation
    Singleton()
    {
        std::cout << "Singleton instance created." << std::endl;
    }

    // Private destructor to prevent external deletion
    ~Singleton()
    {
        std::cout << "Singleton instance destroyed." << std::endl;
    }

    // Private static instance variable
    static Singleton *instance;
};

// Initialize the static instance variable to nullptr
Singleton *Singleton::instance = nullptr;

int main()
{
    // Access the Singleton instance
    Singleton &singleton = Singleton::getInstance();

    // Use the Singleton instance
    singleton.someOperation();

    // Attempting to create another instance will not work
    // Singleton anotherInstance; // This line would not compile

    return 0;
}


```

there is memory leakage here 
```bash
abdallah@abdallah:~/Documents/Github/Embedded_Linux_Diploma/2-ModernCPlusPlus/03_OOP(1)/Task$ g++ Singleton2.cpp 
abdallah@abdallah:~/Documents/Github/Embedded_Linux_Diploma/2-ModernCPlusPlus/03_OOP(1)/Task$ leakage ./a.out 
==46899== Memcheck, a memory error detector
==46899== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==46899== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==46899== Command: ./a.out
==46899== 
Singleton instance created.
Singleton is performing some operation.
==46899== 
==46899== HEAP SUMMARY:
==46899==     in use at exit: 1 bytes in 1 blocks
==46899==   total heap usage: 3 allocs, 2 frees, 73,729 bytes allocated
==46899== 
==46899== 1 bytes in 1 blocks are still reachable in loss record 1 of 1
==46899==    at 0x4849013: operator new(unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==46899==    by 0x1092C0: Singleton::getInstance() (in /home/abdallah/Documents/Github/Embedded_Linux_Diploma/2-ModernCPlusPlus/03_OOP(1)/Task/a.out)
==46899==    by 0x109219: main (in /home/abdallah/Documents/Github/Embedded_Linux_Diploma/2-ModernCPlusPlus/03_OOP(1)/Task/a.out)
==46899== 
==46899== LEAK SUMMARY:
==46899==    definitely lost: 0 bytes in 0 blocks
==46899==    indirectly lost: 0 bytes in 0 blocks
==46899==      possibly lost: 0 bytes in 0 blocks
==46899==    still reachable: 1 bytes in 1 blocks
==46899==         suppressed: 0 bytes in 0 blocks
==46899== 
==46899== For lists of detected and suppressed errors, rerun with: -s
==46899== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
