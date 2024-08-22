#!/bin/bash
################### Colors.sh #####################

declare -A colors=([Red]="\e[31m"
    [Green]="\e[32m"
    [Yellow]="\e[33m"
    [Blue]="\e[34m"
    [Magenta]="\e[35m"
    [Cyan]="\e[36m"
    [White]=:"\e[37m"
    [BOLD]="\e[1m"
    [ITALIC]="\e[3m"
    [UNDERLINE]="\e[4m"
    [RESET]="\e[0m"
)

colors_name=("Red" "Green" "Yellow" "Blue" "Magenta" "Cyan" "White" "BOLD" "ITALIC" "UNDERLINE" "RESET")
selected_color=$(printf "%s\n" "${colors_name[@]}" | rofi -dmenu -p "select color")
xdotool type --delay 10 "${colors[$selected_color]}"
