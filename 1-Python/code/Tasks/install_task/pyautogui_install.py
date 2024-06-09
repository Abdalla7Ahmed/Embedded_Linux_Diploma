#!/usr/bin/python3


import pyautogui 
import os
import time

Extensions_shortcut = 'ctrl','shift','x'
dir_path = os.path.dirname(os.path.realpath(__file__))



def clangd_install():
    image_path = None
    pyautogui.hotkey(Extensions_shortcut)
    pyautogui.typewrite('clangd')
    time.sleep(1)
    pyautogui.moveTo(526,248)
    time.sleep(1)
    pyautogui.click()
    print("the image was founded ")

#print(pyautogui.position())

clangd_install()
