#!/bin/bash
################### logout.sh #####################

choice=$(echo -e "Logout\nReboot\nShutdown" | dmenu -p "select an action")
echo "$choice"
if [ "$choice" == "Logout" ]; then
    pkill -KILL -u "$USER"
elif [ "$choice" == "Reboot" ]; then
    sudo reboot
elif [ "$choice" == "Shutdown" ]; then
    sudo shutdown -h now
else
    echo "invalid choice"
fi
