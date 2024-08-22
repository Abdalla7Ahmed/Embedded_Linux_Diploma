#!/bin/bash
################### 13-function.sh #####################

function say_hello1() {
    echo "Hello1"
}
say_hello1
function say_hello2 {
    echo "Hello2"
}
say_hello2

say_hello3() {
    echo "Hello3"
}
say_hello3

Display_Arguments() {
    if [ -z "$1" ]; then
        echo "no arguments passed to this function"
        exit 1
    fi

    echo "your name is $1"
    echo "your email is $2"
    echo "your phone number is $3"

}

Display_Arguments "abdallah" "abdallahahmed17120@gmail.com" "01018982284"
Display_Arguments "$1" "$2" "$3"

add() {
    if [[ -z "$1" && -z "$2" ]]; then
        echo "usage is add <number1> <number2>"
        exit 1
    fi
    sum=$(($1 + $2))
    return $sum
}

add 10 20
echo $? #have the value of the last return

get_squares() {
    if [ -z "$1" ]; then
        echo "usage is get_squares <number1> "
        exit 1
    fi
    sum=$(($1 * $1))
    return $sum
}

result=$(get_squares 10)
echo "$result"
