clear
echo Enter the no
read n1
sum=0
while [ $n1 -ne 0 ]
    do
	sum=` expr $sum + $n1 `
	n1=` expr $n1 - 1 `
done
echo $sum

