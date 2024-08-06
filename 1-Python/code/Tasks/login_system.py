#! /usr/bin/python3
import pyfiglet


dic={
    "Ahmed":1349,
    "Ali":6078,
    "Amr":9345
}

while True:
    name=input("Please Enter your name: ")
    if dic.get(name) == None:
        print("\tYour are not in the list of welcomed names")
    else:
        ps = int(input("Enter your password: "))
        if dic.get(name) == ps:
            print(pyfiglet.figlet_format("Welcom "+name))
            exit()


