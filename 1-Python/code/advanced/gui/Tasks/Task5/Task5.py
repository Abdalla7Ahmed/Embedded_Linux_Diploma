#!/usr/bin/python

from tkinter import *
root = Tk()
root.title("test")
root.geometry("350x350+1000+100")
root.resizable(False,False)
myCanvas = Canvas(root)
myCanvas.pack()

#functions 
def create_circle(x, y, r, canvas): #center coordinates, radius
    x0 = x - r
    y0 = y - r
    x1 = x + r
    y1 = y + r
    return canvas.create_oval(x0, y0, x1, y1,fill="white")

def button_callback(value):
    print("Button value: Led", value)
    if value == "ON":
        myCanvas.itemconfig(circle_id, fill="red")
    elif value == "OFF":
        myCanvas.itemconfig(circle_id, fill="white")
    else :
        pass


#Handles
circle_id = create_circle(150, 150, 40, myCanvas)
b1 = Button(root, text="Led ON", width=20, command=lambda: button_callback("ON"))
b2 = Button(root, text="Led OFF", width=20, command=lambda: button_callback("OFF"))


#Placing
b1.place(x=70,y=200)
b2.place(x=70,y=240)

root.mainloop()
