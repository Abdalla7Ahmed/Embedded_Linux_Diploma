#!/bin/bash
################### important_notes.sh #####################
path="/home/abdallah"
file_name=".notes.txt"
value=$(cat "${path}/${file_name}")
add() {
    result=$(rofi -dmenu -p "enter something to add")
    tmp="$value"
    if [[ "${result}" == "c" || "${result}" == "C" ]]; then
        copy=$(xclip -o)
        echo "$copy" >${path}/.notes.txt
    else
        echo "$result" >${path}/.notes.txt
    fi
    echo "$tmp" >>${path}/.notes.txt

}

remove() {
    file_tmp="/home/abdallah/.tmp"
    touch "$file_tmp"
    selected_value=$(echo -e "${value[@]}" | rofi -dmenu -p "what string you want to delete : ")
    while read -r line; do
        # echo "$line"
        if [[ "$line" == "$selected_value" ]]; then
            continue
        else
            echo "$line" >>"$file_tmp"
        fi
    done <"${path}/${file_name}"
    contetn=$(cat "$file_tmp")
    echo "$contetn" >"${path}/${file_name}"
    rm "$file_tmp"
}

selected_value=$(echo -e "${value[@]}" | rofi -dmenu -p "add/rm/exit(q)/select : ")
if [[ "${selected_value}" == "add" ]]; then
    add
elif [[ "${selected_value}" == "rm" ]]; then
    remove
elif [[ "${selected_value}" == "q" ]]; then
    exit 1
elif [[ -n "${selected_value}" ]]; then
    xdotool type --delay 10 "$selected_value"
fi
