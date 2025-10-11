#!/bin/bash
fname=$*
if [ $# -lt 1 ]; then
 echo "Ошибка: необходимо имя файла"
 exit 1
fi
#ls -l $fname
#stat $fname
stat -c "Права: %A | Размер: %s байт | Дата: %y" $fname
