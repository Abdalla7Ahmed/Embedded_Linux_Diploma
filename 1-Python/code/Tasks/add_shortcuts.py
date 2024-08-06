#!/usr/bin/python3



# Keyboard module in Python 
import keyboard 
import subprocess

def on_trigger():
    subprocess.run(['nautilus','/home/abdallah/Documents/Motasem'])
 
def listen_for_shortcut():
    shortcut = "ctrl + shift + z"
    keyboard.add_hotkey(shortcut,on_trigger)
    keyboard.wait('esc') 


listen_for_shortcut()

