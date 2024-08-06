
Elided constructors, also known as copy elision or copy initialization, is a C++ optimization technique that allows the compiler to skip the creation of temporary objects in certain situations.

In C++, when an object is passed by value or returned from a function, the compiler typically creates a temporary object and then copies or moves that object to the destination. This process can be inefficient, especially for large or complex objects. The copy elision optimization allows the compiler to skip the creation of the temporary object and instead directly construct the object in its final destination.


Here's an example of copy elision in C++:

```cpp
#include <iostream>

class MyClass {
public:
    MyClass() { std::cout << "Default constructor called." << std::endl; }
    MyClass(const MyClass& other) { std::cout << "Copy constructor called." << std::endl; }
    MyClass(MyClass&& other) { std::cout << "Move constructor called." << std::endl; }
};

MyClass createMyClass() {
    return MyClass();
}

int main() {
    MyClass obj = createMyClass();
    return 0;
}
```

In this example, when the `createMyClass()` function returns, the compiler is able to elide the copy or move construction of the `MyClass` object and directly construct the object in the `main()` function. This means that the copy constructor or move constructor is not called, and only the default constructor is called.

### Output with and without Copy Elision
**With copy elision enabled (default):**
```kotlin
Default constructor called.
```

**With copy elision disabled:**
```bash
$ g++ 05-Elide-constructors.cpp  -fno-elide-constructors -std=c++14 -O0
$ ./a.out 
Default constructor called.
Move constructor called.
Move constructor called.
```



```asm
      {
   0x0000555555555221 <+0>:     endbr64 
   0x0000555555555225 <+4>:     push   %rbp
   0x0000555555555226 <+5>:     mov    %rsp,%rbp
   0x0000555555555229 <+8>:     sub    $0x10,%rsp
=> 0x000055555555522d <+12>:    mov    %fs:0x28,%rax
   0x0000555555555236 <+21>:    mov    %rax,-0x8(%rbp)
   0x000055555555523a <+25>:    xor    %eax,%eax

18          MyClass obj = createMyClass();
   0x000055555555523c <+27>:    lea    -0x9(%rbp),%rax
   0x0000555555555240 <+31>:    mov    %rax,%rdi
   0x0000555555555243 <+34>:    call   0x5555555551c9 <createMyClass()>
   0x0000555555555248 <+39>:    lea    -0x9(%rbp),%rdx
   0x000055555555524c <+43>:    lea    -0xa(%rbp),%rax
--Type <RET> for more, q to quit, c to continue without paging--
   0x0000555555555250 <+47>:    mov    %rdx,%rsi
   0x0000555555555253 <+50>:    mov    %rax,%rdi
   0x0000555555555256 <+53>:    call   0x555555555324 <MyClass::MyClass(MyClass&&)>

19          return 0;
   0x000055555555525b <+58>:    mov    $0x0,%eax

20      }
```
first call the function  createMyClass 

in the createMyClass function 
```asm
     {
   0x00005555555551c9 <+0>:     endbr64 
   0x00005555555551cd <+4>:     push   %rbp
   0x00005555555551ce <+5>:     mov    %rsp,%rbp
   0x00005555555551d1 <+8>:     sub    $0x20,%rsp
   0x00005555555551d5 <+12>:    mov    %rdi,-0x18(%rbp)
   0x00005555555551d9 <+16>:    mov    %fs:0x28,%rax
   0x00005555555551e2 <+25>:    mov    %rax,-0x8(%rbp)
   0x00005555555551e6 <+29>:    xor    %eax,%eax

13          return MyClass();
   0x00005555555551e8 <+31>:    lea    -0x9(%rbp),%rax
   0x00005555555551ec <+35>:    mov    %rax,%rdi
   0x00005555555551ef <+38>:    call   0x5555555552e6 <MyClass::MyClass()>
   0x00005555555551f4 <+43>:    lea    -0x9(%rbp),%rdx
--Type <RET> for more, q to quit, c to continue without paging--
   0x00005555555551f8 <+47>:    mov    -0x18(%rbp),%rax
   0x00005555555551fc <+51>:    mov    %rdx,%rsi
   0x00005555555551ff <+54>:    mov    %rax,%rdi
   0x0000555555555202 <+57>:    call   0x555555555324 <MyClass::MyClass(MyClass&&)>

14      }
```

call the default constructor to create an instance <MyClass::MyClass()> 
then assign the instance to temporary object that's why the move constructor called <MyClass::MyClass(MyClass&&)>

finally in the main function the move constructor call again to assign the temporary object to the base object .

When copy elision is enabled, the compiler constructs the `MyClass` object directly in the location of `obj` in the `main()` function, skipping the creation of any temporary objects.

**Without copy elision:**

1. The `createMyClass` function calls the default constructor to create a temporary `MyClass` object.
2. The move constructor is called to move this temporary object to another temporary location.
3. The move constructor is called again to move the object from the temporary location to `obj` in the `main()` function.


Here's another example of copy elision in the context of function parameters:
```cpp
#include <iostream>

#include <iostream>

class MyClass {
public:
    MyClass() { std::cout << "Default constructor called." << std::endl; }
    MyClass(const MyClass& other) { std::cout << "Copy constructor called." << std::endl; }
    MyClass(MyClass&& other) { std::cout << "Move constructor called." << std::endl; }
};

void createMyClass(MyClass obj) {
}

int main() {
    MyClass obj = createMyClass();
    return 0;
}
```

### Output with and without Copy Elision
**With copy elision enabled (default):**

```kotlin
Default constructor called.
```

**Output with copy elision disabled:**
```bash
$ g++ 05-Elide-constructors.cpp  -fno-elide-constructors -std=c++14 -O0
$ ./a.out 
Default constructor called.
Copy constructor called.
```

```asm
35      {
   0x00005555555551d8 <+0>:     endbr64 
   0x00005555555551dc <+4>:     push   %rbp
   0x00005555555551dd <+5>:     mov    %rsp,%rbp
   0x00005555555551e0 <+8>:     sub    $0x10,%rsp
=> 0x00005555555551e4 <+12>:    mov    %fs:0x28,%rax
   0x00005555555551ed <+21>:    mov    %rax,-0x8(%rbp)
   0x00005555555551f1 <+25>:    xor    %eax,%eax

36          MyClass obj;
   0x00005555555551f3 <+27>:    lea    -0xa(%rbp),%rax
   0x00005555555551f7 <+31>:    mov    %rax,%rdi
   0x00005555555551fa <+34>:    call   0x5555555552a8 <MyClass::MyClass()>

37          createMyClass(obj);
--Type <RET> for more, q to quit, c to continue without paging--
   0x00005555555551ff <+39>:    lea    -0xa(%rbp),%rdx
   0x0000555555555203 <+43>:    lea    -0x9(%rbp),%rax
   0x0000555555555207 <+47>:    mov    %rdx,%rsi
   0x000055555555520a <+50>:    mov    %rax,%rdi
   0x000055555555520d <+53>:    call   0x5555555552e6 <MyClass::MyClass(MyClass const&)>
   0x0000555555555212 <+58>:    lea    -0x9(%rbp),%rax
   0x0000555555555216 <+62>:    mov    %rax,%rdi
   0x0000555555555219 <+65>:    call   0x5555555551c9 <createMyClass(MyClass)>

38          return 0;
   0x000055555555521e <+70>:    mov    $0x0,%eax

39      }
```

first create an object so it will call the default constructor <MyClass::MyClass()>
then assign this object to a temporary one , so it will call the copy constructor <MyClass::MyClass(MyClass const&)> , then call the function.

