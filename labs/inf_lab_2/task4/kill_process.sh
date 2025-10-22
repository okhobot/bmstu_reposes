#!/bin/bash
pname=$*
if [ $# -lt 1 ]; then
 echo "Ошибка: необходимо имя процесса"
 exit 1
fi
pkill $pname
