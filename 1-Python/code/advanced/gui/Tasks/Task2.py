#!/usr/bin/python

import tkinter

m = tkinter.Tk()
m.title("Task1 ")
m.geometry("500x500+1000+100")
m.resizable(False,False)

#call back functions
def button():
    print("User name is ",e1.get())
    print("Password is ",e2.get())




#Handlers

lab1 = tkinter.Label(m,text="user name")
lab2 = tkinter.Label(m,text="Password")
e1 = tkinter.Entry(m)
e2 = tkinter.Entry(m)
button = tkinter.Button(m,text="Button",width=15,command=button)


#Placing
lab1.grid(row = 0,column=0)
lab2.grid(row = 1,column=0)
e1.grid(row = 0,column=1)
e2.grid(row = 1,column=1)
button.grid(row = 2 ,column =0)

m.mainloop()