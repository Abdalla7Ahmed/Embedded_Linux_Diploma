#!/usr/bin/python3


import pyautogui
import os
import time
dir_path = os.path.dirname(os.path.realpath(__file__))
#pyautogui.hotkey('win')
#time.sleep(1)
#pyautogui.typewrite('dog')


image_path =None
while image_path is None:
    image_path = pyautogui.locateCenterOnScreen("/home/abdallah/Pictures/Screenshots/abc.png",confidence=.9)
    



pyautogui.moveTo(image_path)
pyautogui.click()



  