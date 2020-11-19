#!/bin/zsh
#draw graph for new .json files
fpath="$(realpath ./)/"
FILES="$(ls *.json)"
for file in $FILES
do
    base="$(echo L$file | cut -d'.' -f 1)"
    svg="${base}.svg"
    echo $svg
    if [ ! -f "$svg" ]; then
        pushd /Users/douglaslange/ProjectsPy/apps/drawGraph
        echo  /Users/douglaslange/ProjectsPy/apps/drawGraph/drawGraph.py $fpath$file $fpath$svg
        echo $PWD
        /Users/douglaslange/ProjectsPy/apps/drawGraph/drawGraph.py $fpath$file $fpath$svg
        popd
    fi
done
exit
