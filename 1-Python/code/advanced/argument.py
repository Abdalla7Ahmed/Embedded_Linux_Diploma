#! /usr/bin/python3
# Write a Python program to get the command-line arguments


 
import sys
 
# total arguments
n = len(sys.argv)
print("Total arguments passed:", n-1)
 
# Arguments passed
print("\nName of Python script:", sys.argv[0])
 
print("\nArguments passed:", end = " ")
for i in range(1, n):
    print(sys.argv[i], end = " ")
     
print("\n")
