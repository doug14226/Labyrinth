#!/bin/zsh
dirLabyrinth="$(cat ~/.Labyrinth)"
pushd $dirLabyrinth
randH="$(hexdump -n 8 -e '2/4 "%08X" 1 "\n"' /dev/random)"
/Users/douglaslange/ProjectsC++/Labyrinth/build/smyth $randH
popd
exit
