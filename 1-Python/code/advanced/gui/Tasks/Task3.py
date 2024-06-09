#!/usr/bin/python

from  tkinter import *

m = Tk()
m.title("Task1 ")
m.geometry("500x500+1000+100")
m.resizable(False,False)

#call back functions
def callback():
    data = e1.get()[::-1]
    print(data)
    lab2 = Label(m,text=data)  
    lab2.place(x=120,y=50)  


#Handlers
lab1 = Label(m,text="Enter a word : ")
e1 = Entry(m)
button1 = Button(m,text="Validate",width=15,command=callback)


#Placing
lab1.place(x = 10,y = 22)
e1.place(x = 120,y = 20)
button1.place(x=120 , y = 70)

m.mainloop()