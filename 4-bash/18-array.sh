#!/bin/bash
################### 18-array.sh #####################

declare -a arr1=("abdallah" "ahmed" "mohammed" 50 60 70)
arr2=(4 5 6 10 "ali" "osman")
arr2[0]=20
echo "${arr2[@]}" # all element as array

echo "${arr1[0]}"
echo "${arr1[@]}"  # all element as array
echo "${arr1[*]}"  # all element as string
echo "${#arr1[@]}" # length of array (6)

unset "arr1[0]"
echo "${arr1[@]}"  # ahmed mohammed 50 60 70
echo "${#arr1[@]}" # 5 but the first elemnt is null
echo "${arr1[0]}"  # nothing
echo "${arr1[1]}"  # ahmed
########################
#Slicing
sliced_array=("${arr2[@]:0:3}")
echo "${sliced_array[@]}" # 20 5 6 from index 0 and count 3
########################
#map

arr=("BMW" "MERCEDESE" "TOTYTA")
echo "${arr[@]}"

declare -A login=([user]=abdallah [password]=123456)
echo "${login[user]}"
echo "${login[password]}"

#########################
#looping

for i in "${arr[@]}"; do
    echo "$i"
done

for i in "${!arr[@]}"; do #make i hold the index
    echo "$i - ${arr[$i]}"
done
