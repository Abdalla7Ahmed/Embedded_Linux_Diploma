#!/bin/bash
################### ping.sh #####################

string=" 0% packet"

for i in {1..10}; do
    ping=$(ping -c 1 -W 1 "192.168.122.${i}")
    if [[ $ping == *"${string}"* ]]; then
        echo "this 192.168.122.${i} is exist"
    fi
done
