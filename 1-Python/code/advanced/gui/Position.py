#!/usr/bin/python

from  tkinter import *

m = Tk()
m.title("test")
m.geometry("500x500+1000+100")
m.resizable(False,False)
#1.pack
#Label(m,text="hello",fg="black",bg="white").pack()
# or 
#lab1 = Label(m,text="World",fg="black",bg="white")
#lab1.pack()



#2.grid
#Label(m,text="hello",fg="black",bg="white").grid(column=0,row=0)
#Label(m,text="hello",fg="black",bg="white").grid(column=1,row=1)
#Label(m,text="hello",fg="black",bg="white").grid(column=2,row=2)
#lab2 = Label(m,text="world",fg="black",bg="white")
#lab2.grid(row=4,column=4)

#3.place
#Label(m,text="world",fg="black",bg="white").place(x=10,y=10)
#Label(m,text="world",fg="black",bg="white").place(x=50,y=50)


#4.we can mix between them place
Label(m,text="hello",fg="black",bg="white").grid(column=0,row=0)
Label(m,text="world",fg="black",bg="white").place(x=50,y=50)



m.mainloop()



