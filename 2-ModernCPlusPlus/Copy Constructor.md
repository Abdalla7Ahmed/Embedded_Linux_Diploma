
## why we implement the copy constructor ?

![screen](./images/1.0.png)

the compiler by default generate the copy constructor and do the shallow copy , this mean any update in first object will updated also in the second one and vice versa
![screen](./images/1.1.png)

### to solve this problem we must implement the copy constructor 

![screen](./images/1.2.png)
### it work and the deep copy achieved
![screen](./images/1.3.png)

## the copy constructor implemented as Classname (const Classname &obj)
what if we remove the (&) and remove the const from it ?

if we remove the reference it will give an error because an infinite recursive calling of the copy constructor will happen .
![screen](./images/1.4.png)

if we remove the const from it , it will work but when we trying to return an  object from function it will give an error , because it create a temporary object before return and then return this temporary .
note that in c++17 the compiler make optimization to resolve this issue.
![screen](./images/1.5.png)


### it work now 
![screen](./images/1.6.png)


## what exactly happen in the return ?
by setting this flag -fno-elide-constructors we see that the copy constructor called twice why ?
![screen](./images/1.7.png)

the compiler typically creates a temporary object to hold the return value. Then, this temporary object is used to initialize the object in the calling function (in this case, the `main` function). This process is known as copy initialization.
here the in the return line , the copy constructor is called 
![screen](./images/1.8.png)
and in the calling line the copy constructor is called also 
![screen](./images/1.9.png)

**return value optimization** (**RVO**) is a compiler optimization  that involves eliminating the temporary object  created to hold a function's return value.

Copy elision is an optimization technique employed by compilers to avoid unnecessary object copies. It allows the compiler to optimize away the copy constructor calls in certain cases, resulting in improved performance.
In some cases, the compiler may elide the copy constructor calls altogether and construct the object directly in the memory allocated by the caller function. This optimization eliminates the need for the copy constructor to be called twice.

### what is the  Resource acquisition is initialization (RAII) ?
RAII stands for Resource Acquisition Is Initialization. It is a C++ programming technique that ensures that resources (such as memory, file handles, network connections, etc.) are acquired and released in a deterministic and exception-safe manner.

in the above example if we see is there any memory leakage or not ?

runinng this command 
```shell
valgrind valgrind --leak-check=full --show-leak-kinds=all ./a.out
```
![screen](./images/1.10.png)


there is 12 bytes leakage why ?
there are  three objects form the class Integer (4*3 = 12 byte ) alocated without releasing   
if we implement the destructor to release these pointers in the heap section , there is no lekeage

![screen](./images/1.11.png)

### Operator = copy overload
if we assign i2 like this (i2=i1) the operator = overloading will be called , same problem (shallow copy ) and double free to ptr pointer because the same pointer we try to release it .
![screen](./images/1.12.png)
to resolve this problem we will implement the operator = overloading
![screen](./images/1.13.png)

## note that if we assign the object with other during the initialization --> copy constructor
![screen](./images/1.14.png)
