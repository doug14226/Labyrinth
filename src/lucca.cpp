//
//  lucca.cpp
//  labyrinth
//
//  Created by Douglas Lange on 12/1/19.
//  Copyright © 2019 Douglas Lange. All rights reserved.
//

#include "lucca.hpp"

 lucca::lucca(int nr, int nc): labyrinth::labyrinth(nr,nc) {
   
 };

int lucca::complete() {
    cell * scell, * fcell;
    scell = &grid[0];
    fcell = &grid[rows*columns - 1];
    if ((scell -> countLinks() != 1) or (fcell -> countLinks() != 1)) {
        return 0;
    }
//    do not allow entrance turn 
    if ((scell -> links[2] == 0) or (fcell -> links[0] == 0)) {
        return 0;
    }
    return 1;
}

int lucca::completeM() {
    cell * scell, * fcell;
    scell = &grid[columns - 1];
    fcell = &grid[(rows-1)*columns];
    if ((scell -> countLinks() != 1) or (fcell -> countLinks() != 1)) {
        return 0;
    }
//    do not allow entrance or exit turns turn 
    if ((scell -> links[2] == 0) or (fcell -> links[0] == 0)) {
        return 0;
    }
    return 1;   
}

int lucca::symmetricalQ() {
    int r1,c1,r2,c2;
    cell* ccell1;
    cell* ccell2;
    for (r1=0; r1<rows-5; r1++) {
        r2 = 10 - r1;
        for (c1=1; c1<(columns-1); c1++) {
            c2 = 5 - c1;
            ccell1 = &grid[r1*columns+c1];
            ccell2 = &grid[r2*columns+c2];
            if ((ccell1 -> links[0] == NULL) and(ccell2 -> links[2] != NULL)) return 0;
            if ((ccell1 -> links[0] != NULL) and(ccell2 -> links[2] == NULL)) return 0;
            if ((ccell1 -> links[1] == NULL) and(ccell2 -> links[3] != NULL)) return 0;
            if ((ccell1 -> links[1] != NULL) and(ccell2 -> links[3] == NULL)) return 0;
            if ((ccell1 -> links[2] == NULL) and(ccell2 -> links[0] != NULL)) return 0;
            if ((ccell1 -> links[2] != NULL) and(ccell2 -> links[0] == NULL)) return 0;
            if ((ccell1 -> links[3] == NULL) and(ccell2 -> links[1] != NULL)) return 0;
            if ((ccell1 -> links[3] != NULL) and(ccell2 -> links[1] == NULL)) return 0;    
        }
    }
    return 1;
} 


string lucca::lName() {
    char name[23];
    int r,c,i, ii;
    cell* ccell1;
    cell* ccell2;
    i = 0;
    char lookup[37] = "abcdefgh]ijklmnopqrstuvwxyz012345789";
    for (r=0; r<rows; r++) {
        for (c=1; c<(columns-1); c+=2) {
            ccell1 = &grid[r*columns+c];
            ccell2 = &grid[r*columns+c+1];
            ii = 6 * luccaIdx(ccell1) +luccaIdx(ccell2);
            name[i] = lookup[ii];
            i++;
        }
    }
    name[22] = '\0';
    return string(name);
}

int lucca::luccaQ() {
    int r, c, k, n, nm;
    int enterw, entere;
    enterw = 0;
    entere = 0;
    cell * ccell;
    for (c=1; c<(columns-1); c++) {
        n=0;
        for (r=0; r<rows; r++) {
            ccell = &grid[r*columns+c];
            if ((ccell -> links[1]) != 0 and (ccell -> links[3]) != 0) {
                n = 0;
            } else if ((ccell -> links[0]) != 0 and (ccell -> links[2]) != 0) {
                n++;
            } else if ((ccell -> links[3]) != 0 and (ccell -> links[2]) != 0) {
                n = 0;
                enterw = 1;
                entere =0 ;
            } else if ((ccell -> links[1]) != 0 and (ccell -> links[2]) != 0) {
                n = 0;
                enterw = 0;
                entere = 1;
            } else if ((ccell -> links[0]) != 0 and (ccell -> links[1]) != 0) {
                n++;
                nm = n % 2;
                if ((nm == 1 and enterw )) return 0;
                if ((nm == 0 and entere )) return 0;
            } else if ((ccell -> links[0]) != 0 and (ccell -> links[3]) != 0) {
                n++;
                nm = n % 2;
                if ((nm == 0 and enterw )) return 0;
                if ((nm == 1 and entere )) return 0;
            }
        }
    }
    
    // allow only two line with 3 cols and no 4 col
    
    k = 0;
    for (r=0; r<rows; r++) {
        n=0;
        for (c=1; c<(columns-2); c++) {
            ccell = &grid[r*columns+c];
            if ((ccell -> links[1]) != 0 ) {
                n++;
                if (n == 3) return 0;
                if (n == 2) k++;
            } else n=0;
        }
    }
//    if (k > 2) return 0;
    if (k > 0) return 0;
    
    // force at least one and no more than two diversions
    // from entery and exit columns
    
    for (c=0; c<columns; c=c+5) {
        n=0;
        for (r=0; r<(rows-1); r++) {
            ccell = &grid[r*columns+c];
            if ((ccell -> links[2]) != 0 ) {
                n++;
            }
        }
        if (n == 10) return 0;
        if (n<8) return 0;
    }
    return 1;
}
        
int lucca::luccaIdx(cell* C) {
    int i = 0;
    int ndx[13] = {0 ,0, 0, 0, 1 ,1, 2, 3, 3, 3, 4 ,5, 5};
//                 0  1  2  3  4  5  6  7  8  9 10 11 12
    if (C -> links[0]) i+=8;
    if (C -> links[1]) i+=4;
    if (C -> links[2]) i+=2;
    if (C -> links[3]) i+=1;
    return ndx[i];
}

void lucca::drawLucca(string name) {
    const int pointsPerCell = 18;
    const double pi = 3.14159265358979323846;
    const int WIDTH = 2*(rows+2)*pointsPerCell+11;
    const int HEIGHT = 2*(rows+2)*pointsPerCell+11;
    const int center = (rows+2)*pointsPerCell+5;
    int i, j, k, nn, n;
    int ncells;
    double la1, la2, r, a1, a2, ccw;
    cell * ccell;
    cell * ncell;
    cell * lcell;
    ncells = 0;
    ncell = 0;
    lcell = 0;

    cairo_surface_t *surface;
    cairo_t *ctx;

    if (!hamiltonPathQ()) {
        // if this is not a labyrinth avoid the infinite loop
        return;
    }

    surface = cairo_svg_surface_create(name.c_str(), WIDTH, HEIGHT);
    ctx = cairo_create(surface);

    cairo_set_line_join(ctx, CAIRO_LINE_JOIN_MITER);
    cairo_stroke(ctx);

    cairo_set_source_rgb(ctx, 1.0, 1.0, 1.0);
    cairo_set_line_width(ctx, 0.5 * pointsPerCell);   
    cairo_arc(ctx, center, center, (rows+3.5)*pointsPerCell, 0, 2*pi);
    cairo_fill(ctx);
    cairo_set_source_rgb(ctx, 0, 0, 0);
    cairo_arc(ctx, center, center, (rows+2.0)*pointsPerCell, 0, 2*pi);
    cairo_fill(ctx);
    cairo_set_source_rgb(ctx, 1.0, 1.0, 1.0);
    cairo_set_line_width(ctx, pointsPerCell/2);


    lcell = &grid[0];
    if (lcell -> countLinks() != 1) {
        // if eentry not at 0,0 exit
        return;
    }
    ccell = lcell -> getNextCell(lcell);
// draw first line from ccell to ncell
    cairo_move_to(ctx,center,center-.5*pointsPerCell);
    la1= asin((0.5*pointsPerCell)/(2*pointsPerCell));
    la2=la1;
   

    while ( ccell -> countLinks() == 2 ) {
        ncell = ccell -> getNextCell(lcell);
        r = ((ccell -> row) + 2) * pointsPerCell;
        if (ccell -> column == 0) {
            a2 = asin(0.5*pointsPerCell/r);
            a1 = a2;
        } else if ((ccell -> column) == 1) {
            a2 = pi/2 - asin(0.5*pointsPerCell/r);
            a1 = asin(1.5*pointsPerCell/r);
        } else if ((ccell -> column) == 2) {
            a2 = pi - asin(0.5*pointsPerCell/r);
            a1 = pi/2 + asin(0.5*pointsPerCell/r);
        } else if (ccell -> column == 3)  {
            a2 = 1.5*pi - asin(0.5*pointsPerCell/r);
            a1 = pi + asin(0.5*pointsPerCell/r);
        } else if ((ccell -> column) == 4) {
            a2 = 2*pi - asin(1.5*pointsPerCell/r);
            a1 = 3*pi/2 + asin(0.5*pointsPerCell/r);
        } else if ((ccell -> column) == 5) {
            a2 = 2*pi - asin(0.5*pointsPerCell/r);
            a1 = 2*pi + asin(0.5*pointsPerCell/r);
        }
        if ((lcell -> column) < (ccell -> column)) {
            cairo_arc_negative(ctx,center,center,r,-la2,-a2);
            nn = 0;
            ccw =1;
        } else if ((lcell -> column) > (ccell -> column)) { 
            cairo_arc(ctx,center,center,r,-la2,-a1);
            nn=0;
            ccw=0;
            a2=a1;
        } else if (((ccell -> column) > 0) && ((ccell -> column) < 5) && (lcell -> column == ccell -> column)) {
            nn+=1;
            n = nn % 2;
            if ((ccw and n) or (not ccw and not n)) {
                cairo_arc(ctx, center,center,r,-a2,-a1);
                a2 = a1;
            }  else {
                cairo_arc_negative(ctx, center,center,r,-a1,-a2);
            }
         }
        lcell = ccell;
        ccell = ncell;
        ncell = ccell -> getNextCell(lcell);
        la1=a1;
        la2=a2;  
    }
    if ((ccell -> column == 5) and (lcell -> column == 4)){
      r = (ccell -> row + 2) * pointsPerCell;
      a2 = 2*pi - asin(0.5*pointsPerCell/r);
      cairo_arc_negative(ctx, center,center,r,-la2,-a2);
    }
    cairo_line_to(ctx, 2*(rows+2)*pointsPerCell+5, center+.5*pointsPerCell);
    cairo_stroke(ctx);
    cairo_set_source_rgb(ctx, 1.0, 1.0, 1.0);
    cairo_arc(ctx,center,center,1.15*pointsPerCell,0,2*pi);
    cairo_fill(ctx);
    cairo_destroy(ctx);
    cairo_surface_destroy (surface);
}

lucca* luccaFromGridJsonFile(string  name) {
    
    std::ifstream f(name, std::ios::in | std::ios::binary);     // Open the jsonn stream 
    const auto sz = std::filesystem::file_size(name);                        // Obtain the size of the file.
    std::string j(sz, '\0');                                        // Create a buffer.

    // Read the whole file into the buffer.
    f.read(j.data(), sz);
    json jobject = json::parse(j);
    json jgraph = jobject["graph"];   //if not found then jgraph is null
    json jnodes = jgraph["nodes"];
    json jedges = jgraph["edges"];
    int rows = jgraph["metadata"]["rows"];
    int cols = jgraph["metadata"]["cols"];
    bool directedQ = jgraph["directed"];
    lucca * L = new lucca(rows,cols);
    int k = jedges.size();
    for (int i=0; i<k; i++) { 
        auto jedge = jedges.at(i) ;
        string ss = jedge["source"];
        string tt = jedge["target"];
        int srow = jnodes[ss]["metadata"]["row"];
        int scol = jnodes[ss]["metadata"]["col"];
        int trow = jnodes[tt]["metadata"]["row"];
        int tcol = jnodes[tt]["metadata"]["col"];
        auto target = L ->  getCell(trow,tcol) ;   //cell *
        auto source = L ->  getCell(srow,scol) ;
        source -> link(target);
        if (!directedQ) target -> link(source);
    }
    return L;
}
