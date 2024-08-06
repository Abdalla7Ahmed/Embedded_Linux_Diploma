#!/usr/bin/python3

import webbrowser
import pyautogui
import os
import time


Youtube_link='https://www.youtube.com/'
dir_path = os.path.dirname(os.path.realpath(__file__))+"/images/search_image.png"

searc_text = pyautogui.prompt(text="",title="Enter the search text")
webbrowser.open_new_tab(Youtube_link)
time.sleep(3)
result = pyautogui.locateCenterOnScreen(dir_path,confidence=.9)
pyautogui.moveTo(result)
time.sleep(1)

pyautogui.click()
pyautogui.typewrite(searc_text)
pyautogui.hotkey('enter')

    

