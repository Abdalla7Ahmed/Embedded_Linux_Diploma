#! /usr/bin/python3


# this is a single line comment
'''
this 
is
a multi 
line
comment
'''


# string
'''
print("hello world")     # hello world
print('hello world')     # hello world
print('hello "worldr" ') # hello "worldr" 
print("hello 'world' ")  # hello 'world' # hello 'world
print("Name : Abdallah Ahmed ",end=",")
print("Age : 23")  # Name : Abdallah Ahmed ,Age : 23

# variables
x = 5
print(x) # 5
print(type(x)) # <class 'int'>

x = 5.5
print(x) # 5.5
print(type(x)) # <class 'float'>


x="Abdallah"
print(x) # Abdallah
print(type(x)) # <class 'str'>


# data types numerical(complex numbers)
x=5+6j
print(x)   # (5+6j)
print(type(x)) # <class 'complex'>
print(x.real) # 5.0
print(x.imag) # 6.0

# boolean
print(bool(True))   #True
print(bool(False))  #False
print(bool(None))   #False
print(bool(0))      #False
print(bool(""))     #False
print(bool(()))     #False
print(bool([]))     #False
print(bool({}))     #False


# list
# Collection - ordered - mutable(changed)	
ls=[1,2,3,4,5,6,7,8,9]
print(ls)   #[1, 2, 3, 4, 5, 6, 7, 8, 9]
ls[1] = 50
print(ls[1]) #50
print(ls[1:5]) #[50, 3, 4, 5]
print(ls[1:6:2]) #[50, 4, 6]
print(ls[-1]) #9
print(ls[::-1]) #[9, 8, 7, 6, 5, 4, 3, 50, 1]
print(ls[2:]) #[3, 4, 5, 6, 7, 8, 9]
ls=[1,2,3,4,5,"Abdallah",50.5]
print(ls) #[1, 2, 3, 4, 5, 'Abdallah', 50.5]


# tuple
#Collection ordered unchangeable (Immutable)
t=(1,2,3,4,5,6,7,8,9)
print(t)   #(1, 2, 3, 4, 5, 6, 7, 8, 9)
#t[1] = 50   error
print(t[1:5]) #(2, 3, 4, 5)
print(t[1:6:2]) #(2, 4, 6)
print(t[-1]) #9
print(t[::-1]) #(9, 8, 7, 6, 5, 4, 3, 2, 1)
print(t[2:]) #(3, 4, 5, 6, 7, 8, 9)
t=(1,2,3,4,5,"Abdallah",50.5)
print(t) #(1, 2, 3, 4, 5, 'Abdallah', 50.5)



# Dictionary
dic={  
    "Name": "Abdallah",
    "Age": 23,
    "BirthDate": "17/12/2000",
    "Grade": ["A+","A", "B+", "B"]
}
print(type(dic)) #<class 'dict'>
print(dic) #{'Name': 'Abdallah', 'Age': 23, 'BirthDate': '17/12/2000', 'Grade': ['A+', 'A', 'B+', 'B']}
print(dic.keys()) # dict_keys(['Name', 'Age', 'BirthDate', 'Grade'])
print(dic.values()) # dict_values(['Abdallah', 23, '17/12/2000', ['A+', 'A', 'B+', 'B']])
print(dic["Age"]) #23
print(len(dic)) #4


#set
# items are unordered, changeable(mutable), and do not allow duplicate values.
Set = {"Abdallah","Omar","Hossam"} 
print(Set) #{'Omar', 'Hossam', 'Abdallah'}
print(type(Set)) #<class 'set'>



# range 
print(range(10)) #range(0, 10)
print(list(range(10)))  #[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
print(list(range(0,10,2))) #[0, 2, 4, 6, 8]
#print(list(range(0,10,1.5))) # error the increment must be integer 



#Convert string to list 
x="Abdallah"
print(list(x)) #['A', 'b', 'd', 'a', 'l', 'l', 'a', 'h']



# input
name = input("Please enter Your name ")

print(f"Your name is {name}")
print("Your name is {}" .format(name))
print(f"Your name is " , name)
print(f"Your name is {name}")
Age = input("Please enter your age ")
print("your age is ",str(Age))



# if condition
x,y,z=20,30,12
if z>x and z>y:
    print("z is bigger than x and y")
elif x>z and x>y:
    print("x is bigger than y and z")
else:
    print("y is bigger than x and z")

# Shorthand If ... Else
a=20
b=50
print("A") if a>b else print("=") if a == b else print("B") 
if a>b:
   print("A")
else:
    if a ==b :
        print("=")
    else:
        print("B") 

# pass Statement
if 10 >20 :
    pass



# loop

i=5
while i < 10:
    print(i)
    i+=1

for i in range(10):
    if i %2 ==0:
        continue
    else:
        print(i,"odd")  

# Else in For Loop
for i in range (10):
    print(i)
else:
    print("Finally finished")   # it will printed in any case 


# Nested Loops
adj = ["red","big","testy"]
fruits = ["apple","banana","cherry"]

for x in adj:
    for y in fruits:
        print(x,y)



# function

#1. normal function (void , return )
def say_hello():
    print("Hello")

import random

def ret_random():
    return random.randint(0, 100)


say_hello()
print(ret_random())



# 2.Value(assign , default)
def test_function(value1,value2,value3=100):
    print("Value1 is ",value1 , " and Value2 is ",value2 , " and Value3 is ",value3)

test_function(10,20,30)
test_function(10,20)


#3. variadic arguments(*list,**dict)

def my_function(*args):
    for i in args:
        print(i,end=",")
    print("")


my_function("Abdallah","Ahmed","Ali")
my_function(1,2,3,4)


def my_function2(**args):
    print(args.keys())
    print(args.values())
    ls=[]
    for i in args:
        ls.append(i)

    for i in ls:
        print(args[i])

my_function2(Key1=10,Key2=20)


# pass by reference & pass by value 


# pass by value 
def pass_py_value(value):
    value = 10
    print(value) #10 
    print(id(value)) # 140403803275792 --> different addresse

value=20
print(value)  #20
print(id(value)) #140403803276112 --> some address
pass_py_value(value) 
print(value) #20
print(id(value)) #140403803276112 --> same address

print("=============")

# pass by reference
def pass_py_value(value):
    value[0] = 10
    print(value) #10 
    print(id(value)) # 140403804276416 --> same addresse

 
value=[20] # make it list
print(value)  #20
print(id(value)) #140403804276416 --> some address
pass_py_value(value) 
print(value) #10  --> changed 
print(id(value)) #140403804276416 --> same address


import datetime

print(datetime.datetime.now()) #2024-02-23 23:03:54.792671
print(datetime.datetime.now().year)
print(datetime.datetime.now().month) 
print(datetime.datetime.now().hour) 

# deep copy and shallow copy(with list , dictionary)

#shallow copy 
ls1=[10,20,30,40,50]
ls2 = ls1
ls2[0] = 300 
print(ls1)       #[300, 20, 30, 40, 50]
print(ls2)       #[300, 20, 30, 40, 50]           300 change in ls1 and ls2
print(id(ls1))   #140548149337728  some address
print(id(ls2))   #140548149337728  same address

#deep copy

ls3=[10,20,30,40,50]
ls4 = ls3.copy()
ls4[0] = 300 
print(ls3)       #[10, 20, 30, 40, 50]
print(ls4)       #[300, 20, 30, 40, 50]           300 change in ls4 only
print(id(ls3))   #139670113523264  some address
print(id(ls4))   #139670113523200  different address

# the same with dictionary



#class

class MyClass:
    """
    This is a simple example class to demonstrate docstring formatting.
    
    
    Attributes:
    attribute1 (int): This is an example attribute that stores an integer value. attribute2 (str): This attribute stores a string value.
    attribute2 (str): This attribute stores a string value.
    
    Methods:
    method1(): This method performs some action and demonstrates how to document methods.
    
    
    Example:
    >>> obj = MyClass()
    >>> obj.method1()
    Action completed.
    
    """
    name = "" # it's  optional
    def __init__(self,name):
        print("Constructor called ")
        print(self) # <__main__.MyClass object at 0x7f29d3317c10>
        self.name = name
    def __str__(self):
        """
        __str__ method is a special method and return a string representation that includes 
        information about the object's state. When you use str(obj) or print(obj), 
        it will call the __str__ method to get the string representation.
        """
        return ("this is return string")
    def say_hello(self,age):
        """
        function to say welcome
        """
        print(f" Welcome {self.name} your age is {age}")
    def __del__(self):
        print("Destructor called Bye")


Myclass1 = MyClass("Abdallah")
Myclass1.say_hello(23)
print(Myclass1)  # this is return string
print(str(Myclass1))  # this is return string

print(Myclass1.__doc__) #print the documentation of the class
print(Myclass1.__str__.__doc__) #print the documentation of the special method __str__
print(Myclass1.say_hello.__doc__) #print the documentation of any method (say_hello) 




# inheritance
class animal:
    def __init__ (self, name): 
        print("animal class Constructor is called") 
        self.name = name
    def eat(self): 
        print("eat food")
    def __del__ (self): 
        print("animal class Destructor is called")


class cat(animal):
    def __init__ (self): 
        print("cat class Constructor is called")
    def sound(self): 
        print("Meaouuu")
    def __del__ (self): 
        print("cat class Destructor is called")



mycat = cat()
mycat.eat() 
mycat.sound()
'''

'''
this is the output 
cat class Constructor is called
eat food
Meaouuu
cat class Destructor is called

note that the constructor and destructor of the animal class not called how to solve this ?
'''
'''
class animal:
    def __init__ (self): 
        print("animal class Constructor is called") 
    def eat(self): 
        print("eat food")
    def __del__ (self): 
        print("animal class Destructor is called")

class cat(animal):
    def __init__ (self): 
        super().__init__()
        print(super) # <class 'super'>
        print("cat class Constructor is called")
        self.eat()  # we can access the methods of the base class now 
    def sound(self): 
        print("Meaouuu")
    def __del__ (self): 
        print("cat class Destructor is called")
        super().__del__()



mycat = cat()
mycat.eat() 
mycat.sound()
'''

'''
animal class Constructor is called
<class 'super'>
cat class Constructor is called
eat food
eat food
Meaouuu
cat class Destructor is called
animal class Destructor is called
'''

'''
# private members and private methods
class test:
    __member1 = 10
    member2 = 20 
    def __func(self):
        print("this is private method")
    @staticmethod
    def func1():
        print("this is static method")



test1 = test()
print(test1.member2)
#print(test.__member1) #error
print(test1._test__member1) #not error syntax --> _{class_name}__{private_variable}
test1._test__func()  #this is private method --> _{class_name}__{private_method}

# static
test1.func1()  #this is static method   
test1.func1()  #the static methods are related to the class not the instance , so we can call it without creating any objects 

'''
'''
class test:
    def __init__(self,var1):
        self.var1 = var1
    def __add__(self,other):
        return test(self.var1 + other.var1)
    def __mul__(self,other):
        return test(self.var1 * other.var1)
    
       
test1 = test(50)
test2 = test(20)
test3 = test1 + test2
test4 = test1 * test2
print(test3.var1)  #70
print(test4.var1)  #1000  --> 50*20

class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def __eq__(self, other):
        return self.width == other.width and self.height == other.height

    def __ne__(self, other):
        return not self.__eq__(other)

    def __lt__(self, other):
        return self.area() < other.area()

    def __gt__(self, other):
        return self.area() > other.area()

    def __le__(self, other):
        return self.area() <= other.area()

    def __ge__(self, other):
        return self.area() >= other.area()

    def area(self):
        return self.width * self.height

# Creating rectangles
rect1 = Rectangle(4, 5)
rect2 = Rectangle(3, 6)
rect3 = Rectangle(4, 5)

# Equality comparison
print(rect1 == rect2)  # Output: False
print(rect1 == rect3)  # Output: True

# Inequality comparison
print(rect1 != rect2)  # Output: True
print(rect1 != rect3)  # Output: False

# Less than comparison
print(rect1 < rect2)   # Output: False
print(rect2 < rect3)   # Output: True

# Greater than comparison
print(rect1 > rect2)   # Output: True
print(rect2 > rect3)   # Output: False

# Less than or equal to comparison
print(rect1 <= rect2)  # Output: False
print(rect2 <= rect3)  # Output: True

# Greater than or equal to comparison
print(rect1 >= rect2)  # Output: True
print(rect2 >= rect3)  # Output: True


# exceptions handling
# Try /except/else/finally

try:
    print(5)
except:
    print("something is wrong")
else:
    print("everything is okay")
finally:
    print("this will executed in any case")

try:
    print(1/0)
except NameError:
    print("NameError: name 'x' is not defined")
except ZeroDivisionError:
    print("ZeroDivisionError: division by zero")
'''
#threading
import threading
import time
def task1(num):
    while True:
        print(f"Task1 is running now {num}")
        time.sleep(1)
def task2(num):
    while True:
        print(f"Task2 is running now {num}")
        time.sleep(1)
t1 = threading.Thread(target=task1,args=(1,))
t2 = threading.Thread(target=task2,args=(2,))
t1.start()
t2.start()
t1.join()
t2.join()
print("Done")
