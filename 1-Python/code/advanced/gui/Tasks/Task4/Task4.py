#!/usr/bin/python
from tkinter import *
from tkinter.ttk import *

m = Tk()
V = IntVar()
style = Style()

m.title("Task1 ")
m.geometry("400x400+1000+100")
m.resizable(False,False)

#call back functions

def callback():
    global V
    select = V.get()
    try:
        if select == 1:
            final = int(e1.get()) + int(e2.get())
            txt = f"the sum is {final}.0"
        elif select == 2:
            final = int(e1.get()) - int(e2.get())
            txt = f"the sum is {final}.0"
        else:
            pass
        lab4 = Label(m,text=txt).grid(row=2,column=1)
    except ValueError:
        print("Invalid data")
    
        
#Handlers
lab1 = Label(m,text="Enter the value of M : ")
lab2 = Label(m,text="Enter the value of V : ")
lab3 =  Label(m)
e1 = Entry(m)
e2 = Entry(m)
button1 = Button(m,text="Validate",width=15,command=callback)
R1 = Radiobutton(m, text="sum", variable=V, value=1, style="TRadiobutton")
R2 = Radiobutton(m, text="sub", variable=V, value=2, style="TRadiobutton")

#Placing
lab1.grid(row=0,column=0)
lab2.grid(row=1,column=0)
lab3.grid(row=2,column=1)
e1.grid(row=0,column=1)
e2.grid(row=1,column=1)
button1.grid(row=3,column=1)
R1.grid(row=3, column=0)
R2.grid(row=4, column=0)

m.mainloop()