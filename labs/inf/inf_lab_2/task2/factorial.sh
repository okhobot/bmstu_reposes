#!/bin/bash
num=$1
res=1
if [[ ! $num =~ ^[0-9]+$ ]]; then
 echo "Ошибка: неправильный формат аргумента"
 exit 1
fi

for (( i=1; i <= $num; i++ ))
do
res=$(($res * $i))
done
echo $res
