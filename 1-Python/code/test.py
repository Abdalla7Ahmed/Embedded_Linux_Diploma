#! /usr/bin/python3



class test:
    """
    __str__ method is a special method and return a string representation that includes 
    information about the object's state. When you use str(obj) or print(obj), 
    it will call the __str__ method to get the string representation.
    """
    name = "abc"
    def __init__(self,name):
        print("Constructor")
        self.name = name
        print(self.name)
    def __str__(self):
        """
        __str__ method is a special method and return a string representation that includes 
        information about the object's state. When you use str(obj) or print(obj), 
        it will call the __str__ method to get the string representation.
        """
        return ("this is return string")
    def __del__(self):
        print("Distructor")



test1 = test("abdallah")
# test2 = test("ahmed")
# test3 = test("mohammed")

print(test1.__str__.__doc__)