#! /usr/bin/python3

import requests
import subprocess

response = requests.get('https://api.ipify.org/?format=json')

print(response.json()["ip"])


