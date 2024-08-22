#!/bin/bash
################### 7-operation.sh #####################
x=8
y=2
#expr
expr 1 + 2
#let
let sum=2+20
echo "$sum"
#(())
((++sum))
echo "$sum"
echo "x=8 y=2"
echo "Addition of x and y"
echo $(($x + y))
echo $((x + $y))
echo $(($x + $y))
echo "subtraction of x and y"
echo $(($x - $y))
echo "multiplication of x and y"
echo $(($x * $y))
echo "division of x and y"
echo $(($x / $y))

echo "Increment x by 5"
((x += 5))
echo "$x"
echo "Decrement x by 5"
((x -= 5))
echo "$x"
echo "Multiply x by 5"
((x *= 5))
echo "$x"
echo "Division x by 5"
((x /= 5))
echo "$x"
echo "Division x by 5"
((x /= 5))
echo "$x"
echo "Reminder x after division of  5"
((x %= 5))
echo "$x"

result=$((2 ** 4)) #16
echo "$result"
result=$(echo "2 ^ 4" | bc) #16
echo "$result"

((5 == 5))
if [ $? -eq 0 ]; then # last command if it executed successfully the value of $? will be 0
    echo "true"
else
    echo "false"
fi

(((5 > 3) && (5 < 1)))
if [ $? -eq 0 ]; then
    echo "true"
else
    echo "false"
fi
### bc
echo "1+5" | bc
echo 1+5 | bc

#application  ======================================================
echo "===================================="
read -rp "enter the first number: " first_number
read -rp "enter the operation : " operation
read -rp "enter the second number : " second_number

if [ "${operation}" = "+" ]; then
    echo "${first_number} + ${second_number} = "$((${first_number} + ${second_number}))
elif [ "${operation}" = "-" ]; then
    echo "${first_number} - ${second_number} = "$((${first_number} - ${second_number}))
elif [ "${operation}" = "*" ]; then
    echo "${first_number} * ${second_number} = "$((${first_number} * ${second_number}))
elif [ "${operation}" = "/" ]; then
    if [ "${second_number}" -eq 0 ]; then
        echo "error can't devide by zero"
    else
        echo "${first_number} / ${second_number} = "$((${first_number} / ${second_number}))
    fi
else
    echo "wrong option"
fi
