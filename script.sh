#!/bin/bash
echo -e "enter file path to run"
read src
clear
g++ $src
./a
read
echo  -e "
...execution complete"
rm a
