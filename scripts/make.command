#!/bin/zsh
thisDir=`dirname $0`
pushd $thisDir


app="$(realpath ../build/smyth)"
cat > genSMyth.command << EOS
#!/bin/zsh
dirLabyrinth="\$(cat ~/.Labyrinth)"
pushd \$dirLabyrinth
randH="\$(hexdump -n 8 -e '2/4 "%08X" 1 "\n"' /dev/random)"
$app \$randH
popd
exit
EOS
chmod 755 genSMyth.command

app="$(realpath ../build/myth)"
cat > genMyth.command << EOS
#!/bin/zsh
dirLabyrinth="\$(cat ~/.Labyrinth)"
pushd \$dirLabyrinth
randH="\$(hexdump -n 8 -e '2/4 "%08X" 1 "\n"' /dev/random)"
$app \$randH
popd
exit
EOS
chmod 755 genMyth.command

pyPath="$(realpath getDirectory.py)"
cat > setLabyrinthDir.command << EOS
#!/bin/zsh
#set directory for new Labyrinth .json and .svg files
dirLabyrinth="\$(cat ~/.Labyrinth)"
pushd \$dirLabyrinth
selectedDir="\$(/usr/local/bin/python3 $pyPath)"
echo \$selectedDir | cat > ~/.Labyrinth
EOS
chmod 755 setLabyrinthDir.command

app="$(realpath ../build/labyrinth)"
pyPath="$(realpath graphSize.py)"
cat > genLabyrinth.command << EOS
#!/bin/zsh
dirLabyrinth="\$(cat ~/.Labyrinth)"
pushd \$dirLabyrinth
rc="\$(/usr/local/bin/python3 $pyPath)"
r=\$(echo \$rc | cut -d' ' -f1)
c=\$(echo \$rc | cut -d' ' -f2)
s=\$(hexdump -n 8 -e '2/4 "%08X" 1 "\n"' /dev/urandom)
$app \$r \$c \$s
exit    # return condition code from Labyrinth
EOS
chmod 755 genLabyrinth.command


popd
exit