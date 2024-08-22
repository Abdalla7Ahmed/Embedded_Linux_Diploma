#!/bin/bash
################### 5-condition.sh #####################

# to compair two strings we use
# = 	    the first string equal the second string
# != 	    the first string not equal the second string
# to compair integer we use
# -eq       equal
# -ge       grater than or equal
# -gt       grater than
# -le       less than or equal
# -lt       less than
# -ne       not equal
# there are other arguments used with test & if
# -d        FILE exists and is a directory
# -f  	    FILE exists and is a regular file
# -e        FILE exists
# -h        FILE exists and is a symbolic link (same as -h)
# -s        FILE exists and has a size greater than zero
# -z        the length of STRING is zero
# open manual page to see more (man test or man [ )
#============================================================

read -rp "Enter the string " str
if [ -z "$str" ]; then
    echo "the string is empty"
else
    echo "the string is not empty"
fi
threshold=125
read -rp "Enter the number " number
if [ "$number" -lt "$threshold" ]; then
    echo "the ${number} is less than ${threshold}"
elif [ "$number" -eq "$threshold" ]; then
    echo "the ${number} is equal than ${threshold}"
else
    echo "the ${number} is grater than ${threshold}"
fi
name="ali"
test "abdo" = "$name" && echo "true" || echo "false"
test 125 = 125 && echo "true" || echo "false" # 125 will compared as string

x=001
test $x = 1 && echo "true" || echo "false"   #false because 001 not equal to 1
test $x -eq 1 && echo "true" || echo "false" #true

test -f "1-HelloWorld.sh" && echo "File exists" || echo "File does not exist"
if [ -f "1-HelloWorld.sh" ]; then
    echo "File exists"
else
    echo "File does not exist"
fi

## multi condition
# 1
if [ 50 -lt 100 -a 50 -gt 20 ]; then
    echo "true"
else
    echo "false"
fi
#2
if [ 50 -lt 100 ] && [ 50 -gt 20 ]; then
    echo "true"
else
    echo "false"
fi
#3  prefared
if [[ 50 -lt 100 && 50 -gt 20 ]]; then
    echo "true"
else
    echo "false"
fi

#c style
if ((001 == 1)); then
    echo "true"
else
    echo "false"
fi

x=20
if ((++x)); then
    echo "$x"
fi

ls_val=$(ls)
for i in ${ls_val}; do
    if [ -d "$i" ]; then
        echo "the ${i} is directory "
    elif [ -h "$i" ]; then
        echo "the ${i} is symbolic link "
    elif [ -f "$i" ]; then
        echo "the ${i} is file "
    else
        echo "the ${i} is not directory , file or symbolic link "
    fi
done
