//
//  lucca.hpp
//  labyrinth
//
//  Created by Douglas Lange on 12/1/19.
//  Copyright © 2019 Douglas Lange. All rights reserved.
//

#ifndef lucca_hpp
#define lucca_hpp

#include "labyrinth.hpp"

class lucca  :  public labyrinth {
    int luccaIdx(cell*);
public:
    lucca(int, int);
    int luccaQ();
    int  complete();
    int  completeM();
    string lName();
    void drawLucca(string name);
    int symmetricalQ();
};

lucca* luccaFromGridJsonFile(string  name);

#endif /* lucca_hpp */

