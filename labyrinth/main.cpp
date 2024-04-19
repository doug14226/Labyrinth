//
//  main.cpp
//  labyrinth
//
//  Created by Douglas Lange on 11/26/19.
//  Copyright © 2019 Douglas Lange. All rights reserved.
//


#include "labyrinth.hpp"
#include  <ctime>
using namespace std;
using namespace __fs;
int main(int argc, const char * argv[]) {
 // arguments: rows cols seed
    int  i, r, c, h;
    uint seed;
    std::string rs, cs;
    std::string randseed, fileName, gflileName;
    char jsonFname[28];
    std::cout << argc << " arguments:";
    for (int i = 0; i < argc; ++i) std::cout << argv[i] << "\n";
    r = 31;
    c = 30;
    randseed = "3912191E";
    seed = std::stoul( "3912191E", NULL, 16 );
    srand(seed );
    if (argc>=2) {
        r = atoi(argv[1]);
    }
    if (argc>=3) {
        c = atoi(argv[2]);
    }
    if (argc>=4) {
        randseed = std::string(argv[3]);
        seed = std::stoul( randseed, NULL, 16 );
        srand(seed);
    }
    cout << r << "  " << c << " " +randseed + "\n";
    rs = to_string(r);
    cs = to_string(c);
    fileName = rs + "_" + cs + "_" + randseed + ".json";
    gflileName = rs + "_" + cs + "_" + randseed + ".G.svg";
    labyrinth * L = new labyrinth(r,c);
    L -> setRandSeed(randseed);
    L -> seed();
    h = L -> hamiltonPathQ();
    if (!h) {
        std::cout << "Hamilton path failure\n";
        return 4;
    }
    h = L -> complete();
    if (!h) {
        std::cout << "path cannot complete, rows even?\n";
        return 4;
    }
    clock_t c_start = clock();
    for (i=0;i<900;i++) {
        L -> backBite();
       
    }
    while((L-> complete() == 0)){
        L -> backBite();
    }

    clock_t c_end = clock();
    double time_elapsed = 1000*(c_end-c_start) / CLOCKS_PER_SEC;
cout << "CPU time used: " << time_elapsed << " ms\n";


    if (!filesystem::exists( gflileName.c_str() )) L -> drawGraph(gflileName);
    if (!filesystem::exists( fileName.c_str() )) L -> writeJsonFile(fileName);
    
    return 0;
}
