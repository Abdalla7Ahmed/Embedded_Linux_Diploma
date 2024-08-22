#!/bin/bash
################### 9-dmenu.sh #####################

bash_path="/home/abdallah/Documents/Github/Embedded_Linux_Diploma/4-bash"
linux_path="/home/abdallah/Documents/Github/Embedded_Linux_Diploma/3-Linux"
cpp_path="/home/abdallah/Documents/Github/Embedded_Linux_Diploma/2-ModernCPlusPlus"
python_path="/home/abdallah/Documents/Github/Embedded_Linux_Diploma/1-Python"

#using dmenu
# select=$(echo -e "python\ncpp\nlinux\nbash" | dmenu)
# if [ "$select" = "python" ]; then
#     nautilus $python_path &
# elif [ "$select" = "cpp" ]; then
#     nautilus $cpp_path &
# elif [ "$select" = "linux" ]; then
#     nautilus $linux_path &
# elif [ "$select" = "bash" ]; then
#     nautilus $bash_path &
# fi

# using fzf
# select=$(echo -e "python\ncpp\nlinux\nbash" | fzf)
# if [ "$select" = "python" ]; then
#     nautilus $python_path &
# elif [ "$select" = "cpp" ]; then
#     nautilus $cpp_path &
# elif [ "$select" = "linux" ]; then
#     nautilus $linux_path &
# elif [ "$select" = "bash" ]; then
#     nautilus $bash_path &
# fi

#using rofi

select=$(echo -e "python\ncpp\nlinux\nbash" | rofi -dmenu)
if [ "$select" = "python" ]; then
    nautilus $python_path &
elif [ "$select" = "cpp" ]; then
    nautilus $cpp_path &
elif [ "$select" = "linux" ]; then
    nautilus $linux_path &
elif [ "$select" = "bash" ]; then
    nautilus $bash_path &
fi
