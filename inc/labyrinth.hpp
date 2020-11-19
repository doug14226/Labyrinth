//
//  labyrinth.hpp
//  labyrinth
//
//  Created by Douglas Lange on 11/26/19.
//  Copyright © 2019 Douglas Lange. All rights reserved.
//

#ifndef labyrinth_hpp
#define labyrinth_hpp
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
extern "C" {
    #include <cairo.h>
    #include <cairo-svg.h>
}
using namespace std;
const int north = 0;
const int east = 1;
const int south = 2;
const int west = 3;


class cell {
    friend class lucca;

    friend class labyrinth;
    int row;
    int column;
    cell * nearby[4];
    cell * links[4];
    void link(cell * cellToLink);
    void unlink(cell * cellToUnlink);
    int  countLinks();
    int  countNearby();
    cell * getNextCell(cell * last);
};


class labyrinth{
protected:
    int rows;
    int columns;
    std::string randseed;
    int backBites;
    cell * grid;
    cell * current;                         // currenty location for build with "walk"
    cell * getHead();
    cell * getTargetCell(cell * head);

public:
    labyrinth(int, int);                    // labyrinth constructor  
    void seed();                            // seed labyrinth with simple Hamilton Path
    void step(int, int);                    // seed by walk, step drow then dcol from current
    void backBite();
    int  complete();
    void writeJsonFile(string  name);
    int hamiltonPathQ();                    //  should be private
    void reflection(labyrinth*);
    void mirror(labyrinth*);
    void setRandSeed(std::string);
    void setBackBites(int);
    void drawGraph(string name);

};

int sign(int x);
bool fexists(const char *filename);
#endif /* labyrinth_hpp */
