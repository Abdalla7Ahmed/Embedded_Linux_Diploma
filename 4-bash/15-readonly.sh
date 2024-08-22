#!/bin/bash
################### 15-read_only.sh #####################

readonly x=10
#x=20  #./15-readonly.sh: line 5: x: readonly variable
echo "$x"

y=50
readonly y

echo "$y"

hi() {
    echo "hi"
}
hi
readonly -f hi
# -f	refer to shell functions
hi() {
    echo "welcome"
} #./15-readonly.sh: line 21: hi: readonly function
hi
