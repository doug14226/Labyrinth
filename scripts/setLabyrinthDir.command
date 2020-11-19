#!/bin/zsh
#set directory for new .json files
dirLabyrinth="$(cat ~/.Labyrinth)"
pushd $dirLabyrinth
selectedDir="$(/usr/local/bin/python3 /Users/douglaslange/ProjectsCpp/Labyrinth/scripts/getDirectory.py)"
echo $selectedDir | cat > ~/.Labyrinth
