#!/usr/local/bin/python3
import sys
import subprocess
process = subprocess.run(['realpath','../'], check=True, stdout=subprocess.PIPE, universal_newlines=True)
output = process.stdout
output

sys.path.append("/Users/douglaslange/Documents/Mazes Jupyter/")
#print(sys.path)
from InitMazes import initMazeFromJson

def main():
    test = initMazeFromJson(sys.argv[1])
    test.drawWhiteLucca(sys.argv[2])

if __name__ == "__main__":
    main()

