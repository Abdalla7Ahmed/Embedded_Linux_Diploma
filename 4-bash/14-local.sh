#!/bin/bash
################### 14-local.sh #####################

var1="this is global variable 1 "
var2="this is global variable 2"

say() {
    var1="this is local variable 1 "
    local var2="this is local variable 2"
}

echo "$var1"
echo "$var2"
say
echo "$var1"
echo "$var2"

# this is global variable 1
# this is global variable 2
# this is local variable 1
# this is global variable 2
