#!/bin/bash
################### 12-string.sh #####################

str1="abdallah Ahmed"
str2="abdallah Ahmed"

if [ "${str1}" = "${str2}" ]; then
    echo "${str1} equal ${str2}"
elif [ "${str1}" != "${str2}" ]; then
    echo "${str1} not equal ${str2}"
else
    echo
fi

str1="helloworld"
str2="hello"

if [ ${str1} \> ${str2} ]; then
    echo "${str1} grater than  ${str2}"
elif [ ${str1} \< ${str2} ]; then # elif [ str1 < str2 ]  --> error
    echo "${str1} less ${str2}"
else
    echo
fi

# -n ---> check is not empty ?

str="helloworld"

if [ -n "${str}" ]; then
    echo "str is not empty "
else
    echo "str is empty "
fi

#the length of STRING is zero
if [ -z "${str}" ]; then
    echo "str is empty "
else
    echo "str is not empty "
fi

str="helloworld"
length=${#str}
echo "the length of ${str} is ${length}" # 10

length=$(echo ${str} | wc -c)
echo "the length of ${str} is ${length}" # 11

# why in first case print 10 and in second case print 11 ?
# wc --> count from 1 not 0

#splitting

address=egypt,cairo,street20
IFS="," #setting , as a delimiter
read -ra ADDR <<<"$address"
echo "your country is ${ADDR[0]}"
echo "your town is ${ADDR[1]}"
echo "your street is ${ADDR[2]}"

for i in "${ADDR[@]}"; do
    echo "${i}"
done

str="hellofromegypt"
echo "the string is ${str}"
read -rp "enter the start location of the string " start
read -rp "enter the number of charachters " number
echo ${str:${start}:${number}}
