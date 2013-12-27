#!bin/bash 
clear 
echo enter range value 
read r 
i = 1 
while[$i-le $r]
do 
echo $i 
i = 'expr $i + 1'
done 
