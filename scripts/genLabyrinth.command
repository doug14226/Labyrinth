#!/bin/zsh
dirLabyrinth="$(cat ~/.Labyrinth)"
pushd $dirLabyrinth
rc="$(/usr/local/bin/python3 /Users/douglaslange/ProjectsC++/Labyrinth/scripts/graphSize.py)"
r=$(echo $rc | cut -d' ' -f1)
c=$(echo $rc | cut -d' ' -f2)
s=$(hexdump -n 8 -e '2/4 "%08X" 1 "\n"' /dev/urandom)
/Users/douglaslange/ProjectsC++/Labyrinth/build/labyrinth $r $c $s
exit    # return condition code from Labyrinth
