#!/bin/bash
################### cheat.sh #####################

cheat="/home/abdallah/important_scripts/cheat.sh"

lan=$(echo -e "cpp\nrust\npython\nbash\nlinux" | rofi -dmenu -p "select the language ")

# /home/abdallah/important_scripts/cheat.sh ${app} list

function Handler() {
    list=$(${cheat} "$1" list)
    selected_app=$(echo "${list}" | rofi -dmenu)
    echo "$selected_app"

    if [ -n "$selected_app" ]; then
        example=$("${cheat}" "$1" "${selected_app}")
        touch /home/abdallah/tmp.txt
        echo "$example" >/home/abdallah/tmp.txt
        gnome-terminal --window --full-screen -- bash -c "cat /home/abdallah/tmp.txt && read -p 'thank you' "
        rm /home/abdallah/tmp.txt
    fi
}
case "$lan" in
cpp)
    Handler "cpp"
    ;;
rust)
    Handler "rust"
    ;;
python)
    Handler "rust"
    ;;
bash)
    Handler "bash"
    ;;
linux)
    Handler "bash"
    ;;
*) ;;
esac
