#!/bin/bash
################### 16-export.sh #####################

handle_signal() {
    echo "signal received cleaning up and exit"
    exit 1
}

trap 'handle_signal' SIGINT SIGTERM

while true; do
    echo "waiting for signal"
    sleep 1
done
