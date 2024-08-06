#!/usr/bin/python

from  tkinter import *

m = Tk()
m.title("test")
m.geometry("500x500+1000+100")
m.resizable(False,False)
#1.lable
#Label(m,text="hello",fg="black",bg="white").pack()


def button():
    print("hello world")
#2.Button
#button = Button(m,text="Button",width=25,command=button).pack()


#once the button is pressed the gui will closed 
#button = Button(m,text="Button",width=25,command=m.destroy).pack()



#3.entry
#lab1 = Label(m,text="user name",fg="black",bg="white").grid(row = 0)
#lab2 = Label(m,text="passowrd",fg="black",bg="white").grid(row = 1)

#e1 = Entry(m).grid(row = 0,column=1)
#e2 = Entry(m).grid(row = 1,column=1)

#4.Listbox
'''
def item_select(event):
    Select_index = lb.curselection()
    print(f"{Select_index} is {lb.get(Select_index)}" )


lb = Listbox(m)
lb.insert(0,"line 1 ")
lb.insert(1,"line 2 ")
lb.insert(2,"line 3 ")
lb.insert(3,"line 4 ")
lb.insert(4,"line 5 ")
lb.pack()
lb.bind('<<ListboxSelect>>',item_select)
'''


#5.RadioButton
'''
def display():
    global V
    print(V.get())
V = IntVar()
Radiobutton(m,text="abc",variable=V,value=1).grid(row=0,column=0)
Radiobutton(m,text="efg",variable=V,value=2).grid(row=1,column=0)
Button(m,text="Get",width=25,command=display).grid(row=2,column=0)
'''


#6.checkbox
'''
c1= Checkbutton(m,text="Checkbutton1")
c1.select()
c1.pack()
Checkbutton(m,text="Checkbutton2").pack()
Checkbutton(m,text="Checkbutton3").pack()
'''

#7.scale
'''
def display_scale(value):
    print(value)
s1 = Scale(m,from_ = 0,to = 100,orient=HORIZONTAL,command = display_scale)
s1.set(25)
s1.pack()
'''


#8.Text Widget.
'''
txt = Text(m,width=20,height=3)
txt.insert(END,"the is the first text ")
txt.insert(END,"the is the second text")
txt.pack()
'''

#New Form


def open_new_Window():
    newwindwo = Toplevel(m)
    newwindwo.title("New Window")
    newwindwo.geometry("200x200+900+100")
    Label(newwindwo,text="this the new window").pack()
    Button(newwindwo,text= "button1",command=newwindwo.destroy).pack()

lab = Label(m,text="this is the main window").pack()

button = Button(m,text="Button",width=10,command=open_new_Window).pack()






m.mainloop()


















