#! /usr/bin/python3


import requests
response = requests.get('https://api.coindesk.com/v1/bpi/currentprice.json')

data = response.json()["bpi"]["USD"]
for i in data:
    print(i," : " , data[i])