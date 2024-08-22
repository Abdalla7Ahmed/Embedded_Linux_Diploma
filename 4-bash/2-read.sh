#!/bin/bash
################### 2-read #####################

read -p "Enter your name : " name
read -sp "Enter your password : " password

echo "your name is $name"
if [ $password -eq 1234 ]; then
    echo "welcome $name"
else
    echo "password is incorrect .. try again"
fi
