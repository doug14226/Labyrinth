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
#include <nlohmann/json.hpp>
#include <filesystem>
using json = nlohmann::json;
#include <cmath>
extern "C" {
    #include <cairo/cairo.h>
    #include <cairo/cairo-svg.h>
}
using namespace std;
const int north = 0;
const int east = 1;
const int south = 2;
const int west = 3;


class cell {
    friend class lucca;

    friend class labyrinth;
protected:
    int row;
    int column;
    cell * nearby[4];
    cell * links[4];
    void unlink(cell * cellToUnlink);
    int  countLinks();
    int  countNearby();
    cell * getNextCell(cell * last);
public:
    void link(cell * cellToLink);
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
    ~labyrinth();                           // destructor
    void seed();                            // seed labyrinth with simple Hamilton Path
    void setCurrent(int,int);               
    void step(int, int);                    //  step drow then dcol from current
    cell * getCell(int r, int c);                  
    void backBite();
    int  complete();
    void writeJsonFile(string  name);
    int hamiltonPathQ();                    //  should be private
    void reflection(labyrinth*);
    void mirror(labyrinth*);
    void paste(labyrinth*, int, int);       // past smaller labyrinthnat delta r and delta c
    void setRandSeed(std::string);
    void setBackBites(int);
    void drawGraph(string name);

};

int sign(int x);
bool fexists(const char *filename);

labyrinth* fromJsonFile(string  name);

#endif /* labyrinth_hpp */
