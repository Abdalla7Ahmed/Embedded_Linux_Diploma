#!/bin/bash
################### build.sh #####################

path="/home/abdallah/Documents/Github/Embedded_Linux_Diploma/2-ModernCPlusPlus/projects/pc_control"
g++ ${path}/PcControl.cpp ${path}/SocketHandler.cpp ${path}/parse_json.cpp ${path}/Commands.cpp ${path}/execute.cpp -o ${path}/PCCONTROL
systemctl daemon-reload
systemctl restart pc-control.service
