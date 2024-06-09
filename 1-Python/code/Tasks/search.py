#!/usr/bin/python3

import pyautogui
import os
import time
dir_path = os.path.dirname(os.path.realpath(__file__))+"/terminal.png"
#pyautogui.hotkey('win')
#time.sleep(.2)

#pyautogui.typewrite('abc')

image_path =None
while image_path is None:
    image_path = pyautogui.locateOnScreen(dir_path,confidence=.521)
    
#try:
#    image_path = pyautogui.locateOnScreen("/home/abdallah/Pictures/Screenshots/terminal.png", confidence=.6)
    # Rest of your code
#except pyautogui.ImageNotFoundException:
#    print("Image not found with sufficient confidence.")

print(image_path)
pyautogui.moveTo(pyautogui.center(image_path))
#if image_path is not None:
#   pyautogui.hotkey('enter')


  