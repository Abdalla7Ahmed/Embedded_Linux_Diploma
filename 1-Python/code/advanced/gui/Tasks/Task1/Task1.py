#!/usr/bin/python

import tkinter

m = tkinter.Tk()
m.title("Task1 ")
m.geometry("500x500+1000+100")
m.resizable(False,False)

#call back functions
def button1():
    print("button1 is pressed")

def button2():
    print("button2 is pressed")

def button3():
    print("button3 is pressed")

def button4():
    print("button4 is pressed")

#Handlers
button1 = tkinter.Button(m,text="Button1",width=10,command=button1)
button2 = tkinter.Button(m,text="Button2",width=10,command=button2)
button3 = tkinter.Button(m,text="Button3",width=10,command=button3)
button4 = tkinter.Button(m,text="Button4",width=10,command=button4)

#Placing
button1.grid(column=1,row=0)
button2.grid(column=0,row=1)
button3.grid(column=3,row=1)
button4.grid(column=1,row=3)


m.mainloop()