#!/bin/bash
################### 21-Tips.sh #####################

#declare an integer
declare -i counter

counter=10
counter+=1
echo "$counter" ##11

c=10
c+=1
echo "$c" #101

#python inside the script
python3 -c "print (\"hello\")
x=10
print(\"the value of x is\" , x)
"
