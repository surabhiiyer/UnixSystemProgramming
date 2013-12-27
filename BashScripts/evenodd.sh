#!bin/bash
clear
echo enter an integer
read n
if [ `expr $n % 2` -eq 0 ]
then
echo even number
else
echo odd number
fi

