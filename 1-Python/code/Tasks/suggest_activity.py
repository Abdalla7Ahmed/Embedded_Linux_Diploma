#! /usr/bin/python3

import requests
import subprocess

response = requests.get('https://www.boredapi.com/api/activity')

data = response.json()["activity"]

subprocess.run(['notify-send',data])

