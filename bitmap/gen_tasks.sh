#!/bin/bash
out="output.txt";

echo > "$out";
while IFS='' read -r line || [[ -n "$line" ]]; do
    echo "$line получил эту задачу:" >> "$out";
    make "$line" | sed -e "s/usage: make <name> <surname>/Всё плохо.../" -e "/^$/d" >> "$out";
    echo >> "$out";
done < "students.txt";