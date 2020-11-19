//
//  main.cpp
//  lucca
////
//  main.cpp
//  lucca
//
//  Created by Douglas Lange on 12/2/19.
//  Copyright © 2019 Douglas Lange. All rights reserved.
//


#include "lucca.hpp"

int main(int argc, const char * argv[]) {
    int h;
    string jsonFname;
    string GFname;
    string DFname;
    // insert code here...
    lucca * L = new lucca(11,6);
    lucca * R = new lucca(11,6);
    L -> step(4,1);
    L -> step(5-4,0-1);
    L -> step(10-5,2-0);
    L -> step(9-10,1-2);
    L -> step(6-9,2-1);
    L -> step(8-6,3-2);
    L -> step(10-8,4-3);
    L -> step(7-10,3-4);
    L -> step(5-7,2-3);
    L -> step(3-5,1-2);
    L -> step(0-3,2-1);
    L -> step(2-0,3-2);
    L -> step(4-2,4-3);
    L -> step(1-4,3-4);
    L -> step(0-1,5-3);
    L -> step(5-0,4-5);
    L -> step(6-5,5-4);
    L -> step(10-6,5-5);

    L -> drawLucca("test.svg");
    // note the calls to complete, symetricalQ and hamiltonPathQ serve no purpose 
    // other than testing those routines
    L -> complete();
    L -> luccaQ();
    jsonFname = (L -> lName());
    GFname = jsonFname + ".G.svg";
    DFname = jsonFname + ".L.svg";
    jsonFname = jsonFname + ".json";

    if (!filesystem::exists( jsonFname.c_str() )) L -> writeJsonFile(jsonFname);
    if (!filesystem::exists( GFname.c_str() )) L -> drawGraph(GFname);
    if (!filesystem::exists( DFname.c_str() )) L -> drawLucca(DFname);
    if (!(L -> symmetricalQ())) {
        return 4;
    }

    R -> reflection(L);
    if (!(R -> symmetricalQ())) {
        return 4;
    }

    
    h = L -> hamiltonPathQ();
std::cout << "Hello, World!\n";
    return 0;
} 
