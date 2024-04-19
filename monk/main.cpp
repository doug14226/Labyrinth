//
//  main.cpp
//  5x4
////
//  main.cpp
//  lucca
//
//  Created by Douglas Lange on 12/2/19.
//  Copyright © 2019 Douglas Lange. All rights reserved.
//


#include "lucca.hpp"
using namespace std;
using namespace __fs;
int main(int argc, const char * argv[]) {
    int h;
    string jsonFname;
    string GFname;
    string DFname;
    string jsonl;
    // insert code here...
    lucca * L = new lucca(11,6);
//    lucca * R = new lucca(11,6);
    L -> step(4,1);
    L -> step(5-4,0-1);
    L -> step(10-5,1-0);
    L -> setCurrent(10,5);
    L -> step(-4,-1);
    L -> step(-1,1);
    L -> step(-5,-1);
    L -> setCurrent(4,2);
    L -> step(1,1);
    L -> step(1,0);
    if (argc>=2) {
        jsonl = std::string(argv[1]);
    } else {
        cout << "must specify input file" << "\n";
        return(4);
    }
 
    labyrinth * J = fromJsonFile(jsonl);
    labyrinth * K = fromJsonFile(jsonl);
    L -> paste(J,6,1);
    J -> drawGraph("testJson.G.svg");
    K -> reflection(J);
    K -> drawGraph("rotateJson.G.svg");
    L -> paste(K,0,1);
    L -> drawGraph("test10C.G.svg");



    L -> drawLucca("test10C.L.svg");

    return 0;
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
  


} 
