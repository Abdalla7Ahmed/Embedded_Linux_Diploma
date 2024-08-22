#!/bin/bash
################### 11-select.sh #####################

select name in "Abdallah" "Ali" "Osman" "Elsayed"; do
    echo "$name"
    break
done

select name in "Abdallah" "Ali" "Osman" "Elsayed"; do
    echo "$name"
    case $name in
    Abdallah)
        echo "welcome abdallah your name in the list"
        ;;
    Ali)
        echo "welcome Ali your name in the list"

        ;;
    Osman)

        echo "welcome Osman your name in the list"
        ;;
    Elsayed)
        echo "welcome Elsayed your name in the list"
        ;;
    *)
        echo "You are not welcome"
        break
        ;;
    esac
done
