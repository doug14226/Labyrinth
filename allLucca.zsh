#!/bin/zsh
cd ./dataAll/
for file in *.json
do
../build/playzzzz  $file
done