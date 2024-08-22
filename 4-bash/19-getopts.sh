#!/bin/bash
################### 19-getopts.sh #####################

usage() {
    echo "Usage: ./getopts.sh [-s <45|90>] [-p <string>]" 1>&2 && exit 1
}

while getopts "s:p:" o; do
    case "$o" in
    s)
        s=${OPTARG}
        ((s == 40 || s == 90)) || usage
        ;;
    p)
        p=${OPTARG}
        ;;
    *)
        usage
        ;;
    esac
done
shift $(($OPTIND - 1))

if [[ -z "$s" || -z "$p" ]]; then
    usage
fi

echo "$s"
echo "$p"

echo "$1"
