#! /usr/bin/python3

#Write python code to generate Init function of GPIO  for AVR
import os
ls = []
counter = 0
while counter < 8:
    x = input(f"please enter Bit{counter} mode : ")
    ls.append(x)
    counter += 1
x = "".join(ls)[::-1]
with open("init.c", "w") as fd:
    fd.write(f"void Init_PORTA_Dir(void)\n{{\n\tDDRA = 0b{x} ;\n}}")


