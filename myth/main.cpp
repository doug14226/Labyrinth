//
//  main.cpp
//  myth
//
//  Created by Douglas Lange on 12/10/19.
//  Copyright © 2019 Douglas Lange. All rights reserved.
//

#include "lucca.hpp"
#include <filesystem>
using namespace std; 
using namespace __fs;
int main(int argc, const char * argv[]) {
    int b, i;
    uint seed;
    string randseed;
    string arg1;
    string Fname;
    string sFnameJson, sFnameGraph, sFnameDraw;
    randseed = string("3912191E");
    seed = stoul( "3912191E", NULL, 16 );
    srand(seed );
    cout << argc << " arguments:";
    for (int i = 0; i < argc; ++i) std::cout << argv[i] << "\n";
    if (argc>=2) {
        randseed =  string(argv[1]);
        seed = stoul( randseed , NULL, 16 );
        srand(seed);
    }
    b=0;
    lucca * L = new lucca(11,6);
    lucca * R = new lucca(11,6);
    L -> setRandSeed(randseed);
    R -> setRandSeed(randseed);
    L -> seed();
    for (i=0;i<132;i++) {
        L -> backBite();
        b++;
    }
    while(((L-> complete() == 0) && (L-> completeM() == 0)  ) || (L-> luccaQ() == 0)) {
        L -> backBite();
        b++;
    }
    L -> setBackBites(b);
    R -> setBackBites(b);
    if (L-> completeM()) {
        R -> mirror(L);
        Fname = (R -> lName());
        sFnameJson = Fname + ".json";
        sFnameGraph = Fname + ".G.svg";
        sFnameDraw = Fname + ".L.svg";
        if (!filesystem::exists( sFnameJson.c_str() )) R -> writeJsonFile( sFnameJson);
        if (!filesystem::exists( sFnameGraph.c_str() )) R -> drawGraph( sFnameGraph);
        if (!filesystem::exists( sFnameDraw.c_str() )) R -> drawLucca( sFnameDraw);

    } else {
        Fname = (L -> lName());
        sFnameJson = Fname + ".json";
        sFnameGraph = Fname + ".G.svg";
        sFnameDraw = Fname + ".L.svg";
        if (!filesystem::exists( sFnameJson.c_str() )) L -> writeJsonFile( sFnameJson);
        if (!filesystem::exists( sFnameGraph.c_str() )) L -> drawGraph( sFnameGraph);
        if (!filesystem::exists( sFnameDraw.c_str() )) L -> drawLucca( sFnameDraw);
    }

std::cout << "Total, BackBites!\n";
        std::cout << b << "\n";

    return 0;
}
