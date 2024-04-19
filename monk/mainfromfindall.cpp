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

using namespace __fs;
int main(int argc, const char * argv[]) {
    int h;
    string jsonFname;
    string GFname;
    string DFname;
    string jsonl;
    if (argc>=2) {
        jsonl = std::string(argv[1]);
    } else {
        cout << "must specify input file" << "\n";
        return(4);
    }
    DFname = jsonl + ".L.svg";
    lucca * L = luccaFromGridJsonFile(jsonl);
    
    L -> drawLucca(DFname);

    return 0;
 
 


} 
