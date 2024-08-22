#!/bin/bash
################### 8-Argument.sh #####################

<<COMMENTS
$0 specifies the name of the script to be invoked.
$1-$9 stores the names of the first 9 arguments or can be used as the arguments' positions.
$# specifies the total number (count) of arguments passed to the script.
$* stores all the command line arguments by joining them together.
$@ stores the list of arguments as an array.
$$ specifies the process ID of the current script.
$? specifies the exit status of the last command or the most recent execution process.
COMMENTS

echo $$                      # pid of the script
echo "the script name is $0" # path of the script
echo "the first argument is $1"
echo "the second argument is $2"
echo "the third argument is $3"
echo $#               # the number of arguments which passed
echo $*               # the argument which passed as a single string
echo $@               # the arguments which passed as a list we can loop on it
echo $?               # if the last command succedded it will be zero else 127
if [ $? -eq 0 ]; then # last command if it executed successfully the value of $? will be 0
    echo "sucess"
else
    echo "failed to execute command"
    exit
fi
arg=$@
for i in ${arg}; do
    echo "${i}"
done

args=("$@")
echo "${args[0]}"
echo "${args[1]}"
echo "${args[2]}"

for i in "$@"; do
    echo "$i"
done
