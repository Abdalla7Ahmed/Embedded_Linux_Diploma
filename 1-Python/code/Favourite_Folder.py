#! /usr/bin/python3
import os



# index
Favourite_Folder = [
    "/home/abdallah/Documents/Github",
    "/home/abdallah/Documents/Linux",
    "/home/abdallah/Documents/Motasem"
]

while True:
    val = int(input("please enter your dir "))
    os.popen(r"nautilus {}".format(Favourite_Folder[val]))

'''
Favourite_Folder = {
    "github":"/home/abdallah/Documents/Github",
    "Linux":"/home/abdallah/Documents/Linux",
    "diploma":"/home/abdallah/Documents/Motasem"
}

for i in Favourite_Folder:
    print(i)

val = (input("please enter your dir "))

os.popen(r"nautilus {}".format(Favourite_Folder[val]))
'''