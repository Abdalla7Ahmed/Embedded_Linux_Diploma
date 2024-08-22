#!/bin/bash
################### 20-file.sh #####################
value1=$(cat 20-file.sh)
# echo "${value1}"
IFS=$'\n'
value2=$(<20-file.sh)
# echo "${value2}"

# while read -r line; do
#     echo "$line"
# done <20-file.sh

# echo "hello" >>20.txt

# -e  FILE exists
#-f FILE exists and is a regular file
if [ -f 20-file.sh ]; then
    echo "file exist"
fi

#read file into array

value=$(cat 20-file.sh)
declare -a ARRAY
index=0

for i in $value; do
    ARRAY[index]=$i
    ((index++))
done

# for i in "${ARRAY[@]}"; do
#     echo "$i"
# done

echo "${ARRAY[1]}"

#find max
max="${ARRAY[0]}"

for i in "${!ARRAY[@]}"; do
    if [ "${ARRAY[$i]}" \> "$max" ]; then
        max="${ARRAY[$i]}"
    fi
done

echo "$max"
