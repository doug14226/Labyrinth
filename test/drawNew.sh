#!/bin/bash
#draw new .json files
FILES="$(ls *.json)"
for file in $FILES
do
    echo $file
    base="$(echo $file | cut -d'.' -f 1)"
    svg="${base}.svg"
    echo $svg
    if [ ! -f "$svg" ]; then
        ./drawLucca.py $file $base
    fi
done
