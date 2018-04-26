#!/bin/bash
out="output.txt";

[ -f "./task" ] || make;

echo > "$out";
iconv -c -f WINDOWS-1251 -t UTF-8 "students.txt" > "students_utf8.txt";
while IFS='' read -r line || [[ -n "$line" ]]; do
    echo "$line получил эту задачу:" >> "$out";
    echo "$line" | ./task | sed -e "s/U kidin mi!/Всё плохо.../" -e "/Введите имя и фамилию/d" -e "/^$/d" >> "$out";
    echo >> "$out";
done < "students_utf8.txt";