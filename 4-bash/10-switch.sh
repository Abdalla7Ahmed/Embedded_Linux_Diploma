#!/bin/bash
################### 10-switch.sh #####################

read -rp "Do you know me ? " answer

case $answer in
Yes | yes)
    echo "Welcome"
    ;;
NO | no)
    echo "Nice to meet you"
    ;;
*)
    echo "wrong option"
    ;;
esac

read -rp "enter your name " name
case ${name} in
"ahmed" | "ali" | "omar")
    echo "welcome ${name}"
    ;;
*)
    echo "${name} not welcomed"
    ;;
esac
