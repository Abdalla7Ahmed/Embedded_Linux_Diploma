#! /usr/bin/python3

import requests
response = requests.get(
    'https://api.aladhan.com/v1/calendarByAddress/2024/8?address=Sultanahmet%20Mosque,%20sohag,%20Turkey&method=2')

# Check if the request was successful
if response.status_code == 200:
    data = response.json()
    print(data["data"][0]["timings"])


