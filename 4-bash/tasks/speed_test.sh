#!/bin/bash
################### speed_test.sh #####################

#check if speedtest-cli is installed or not
if ! command -v speedtest-cli &>/dev/null; then
    echo "speedtest-cli is not installed , please install it using your package manager"
    exit 1
fi

speedtest_result=$(speedtest-cli)

echo "Speed test result"
echo "$speedtest_result"
