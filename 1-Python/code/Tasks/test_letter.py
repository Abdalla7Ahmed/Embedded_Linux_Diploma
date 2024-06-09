#! /usr/bin/python3


#Write a Python program to test whether a passed letter is a vowel or not.
vowels = "aeiouAEIOU"  

word = input("Enter the word ")

letter= input("Enter the letter to test is it vowel or not ")

if word.find(letter) == -1:
    print("the letter doesn't exist in the word")
else:
    if letter in vowels:
        print("the letter is vowel")
    else:
        print("the letter is not a vowel")
