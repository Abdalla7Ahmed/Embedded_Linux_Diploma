#!/bin/bash
################### 6-loops.sh #####################
###### for
for i in 1 2 3 4 5 6 7; do
    echo $i
done

for i in {1..10}; do
    echo $i
done

files=$(ls)
for i in $files; do
    echo "the file name is $i"
done

files=$(ls)
for i in $files; do
    echo "the content in file $i is "
    cat "$i"
done

####### while

x=5
y=10
while [ $x -lt $y ]; do
    echo "x still less than y"
    echo "x = $x and y = $y"
    ((x++))
done

######### untill
i=10
until [ $i -lt 1 ]; do
    echo "$i is grater than 1"
    ((i--))
done
