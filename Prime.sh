#!/bin/bash
read n
prime=1
for ((i=2; i*i<=n; i++))
do
    if [ $((n%i)) -eq 0 ]
    then
        prime=0
        break
    fi
done
if [ $n -le 1 ]
then
    echo "Not Prime"
elif [ $prime -eq 1 ]
then
    echo "Prime"
else
    echo "Not Prime"
fi
