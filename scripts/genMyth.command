#!/bin/zsh
dirLabyrinth="$(cat ~/.Labyrinth)"
pushd $dirLabyrinth
#gen smyth for new .json files
randH="$(hexdump -n 8 -e '2/4 "%08X" 1 "\n"' /dev/random)"
/Users/douglaslange/ProjectsCpp/Labyrinth/build/myth $randH
popd
exit
