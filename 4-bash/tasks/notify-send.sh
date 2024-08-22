#!/bin/bash
################### notify-send.sh #####################
threshold=90
battery_path="/sys/class/power_supply/BAT0/capacity"
battery_value=$(cat $battery_path)
echo "$battery_value"
if [ "$battery_value" -lt "$threshold" ]; then
    notify-send "take care your battery is less than $threshold"
    espeak "put the laptop on the charge ya basha"
fi
