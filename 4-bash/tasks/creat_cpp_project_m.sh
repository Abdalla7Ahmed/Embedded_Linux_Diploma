#!/bin/bash
################### creat_cpp_project_m.sh #####################

if [ -z $1 ]; then
    echo "usage is ./create_cpp_project_m.sh <project name>"
    exit
fi

project_name="$1"

mkdir "$project_name" || exit
cd "$project_name" || exit
mkdir "build" || exit
iostream="#include <iostream>"
cpp_content="
int main(void) 
{
    std::cout<<\"hello world\"<<std::endl;
    return 0;
}
"
answer="y"
while [[ "$answer" = "y" || "$answer" = "Y" ]]; do
    read -rp "Enter the name of cpp file : " name
    touch "$name.cpp"
    read -rp "Do you want to add header file ? (Y/N) : " a
    if [[ $a = "y" || $a = "Y" ]]; then
        touch "$name.hpp"
        echo "#pragma once" >"$name".hpp
        echo "$iostream" >>"$name".hpp
        echo "#inclue \"$name.hpp\"" >>"$name.cpp"
    else
        echo "$iostream" >"$name".cpp
    fi
    echo "$cpp_content" >>"$name.cpp"
    read -rp "Do you want to add another file ? (Y\N) " answer
done

# Create CMakeLists.txt file
cat <<EOL >CMakeLists.txt
cmake_minimum_required (VERSION 3.10)
project($project_name)
set (CMAKE_CXX_STANDARD 17)
add_executable($project_name main.cpp)
EOL

echo "C++ project '$project_name' has been created." echo "To build the project, run the following commands:"
echo "cd $project_name/build"
echo "cmake .."
echo "make"
