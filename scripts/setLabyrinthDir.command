#!/bin/zsh
#set directory for new Labyrinth .json and .svg files
dirLabyrinth="$(cat ~/.Labyrinth)"
pushd $dirLabyrinth
selectedDir="$(/usr/local/bin/python3 /Users/douglaslange/ProjectsC++/Labyrinth/scripts/getDirectory.py)"
echo $selectedDir | cat > ~/.Labyrinth
