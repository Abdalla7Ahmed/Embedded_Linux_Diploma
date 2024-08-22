#!/bin/bash
################### 22-color.sh #####################
Black="\e[30m"
Red="\e[31m"
Green="\e[32m"
Yellow="\e[33m"
Blue="\e[34m"
Magenta="\e[35m"
Cyan="\e[36m"
White="\e[37m"
RESET="\e[0m"

BOLD="\e[1m"
ITALIC="\e[3m"
UNDERLINE="\e[4m"

echo -e "${Red}this text is Red ${RESET}"
echo -e "${Black}this text is Black ${RESET}"
echo -e "${Green}this text is Green ${RESET}"
echo -e "${Yellow}this text is Yello ${RESET}"
echo -e "${Blue}this text is Blue ${Blue}"
echo -e "${Magenta}this text is Magenta ${RESET}"
echo -e "${Cyan}this text is Cyan ${RESET}"
echo -e "${White}this text is White ${RESET}"

echo -e "${Red}${BOLD}this text is Red and BOLD ${RESET} "
echo -e "${Red}${ITALIC}this text is Red and ITALIC ${RESET} "
echo -e "${Red}${UNDERLINE}this text is Red and UNDERLINE ${RESET} "
