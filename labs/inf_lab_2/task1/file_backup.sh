#!/bin/bash
input_file=important.txt
output_file=important_backup.txt
if [ ! -f "$input_file" ]; then
 echo "Ошибка: файл $input_file не существует."
 exit 1
fi
cp "$input_file" "$output_file"
echo "Резервная копия $input_file создана"
