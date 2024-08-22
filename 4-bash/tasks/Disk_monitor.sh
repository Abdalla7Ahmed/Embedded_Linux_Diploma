#!/bin/bash
################### Disk_monitor.sh #####################

max=90
storage=$(df -h | grep "/dev/nvme1n1p2" | awk '{print $5}')
size=${storage::-1}
if [ "$size" -lt "$max" ]; then
    notify-send "disk :$storage"
    /usr/bin/python3 /usr/bin/x-terminal-emulator -e "/bin/sh -i -c \"watch df -h \""
    #x-terminal-emulator -e "watch df -h" #work also

fi
