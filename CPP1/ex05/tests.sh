#!/bin/bash

make

echo -e "\e[1;36mTest 0: DEBUG\e[0m"
./main DEBUG
echo

echo -e "\e[1;36mTest 2: INFO\e[0m"
./main INFO
echo

echo -e "\e[1;36mTest 3: WARNING\e[0m"
./main WARNING
echo

echo -e "\e[1;36mTest 4: ERROR\e[0m"
./main ERROR
echo

echo -e "\e[1;36mTest 4: Invalid level\e[0m"
./main NOLEVEL
echo

echo -e "\e[1;36mTest 4: Invalid number of Args\e[0m"
./main ERROR INFO
echo

echo -e "\e[1;36mTest 4: No Args\e[0m"
./main
echo