#!/bin/bash

make

echo "\e[1;36m./convert 0\e[0m"
./convert 0
echo

echo "\e[1;36m./convert nan\e[0m"
./convert nan
echo

echo "\e[1;36m./convert 42.0f\e[0m"
./convert 42.0f
echo

echo "\e[1;36m./convert 42\e[0m"
./convert 42
echo

echo "\e[1;36m./convert 42.0\e[0m"
./convert 42.0
echo

echo "\e[1;36m./convert a\e[0m"
./convert a
echo
