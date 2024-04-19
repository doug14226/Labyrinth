//
//  labyrinth.cpp
//  labyrinth
//
//  Created by Douglas Lange on 11/26/19.
//  Copyright © 2019 Douglas Lange. All rights reserved.
//

#include "labyrinth.hpp"
#




// "cell operatorson
// link
// unlink

void cell::link(cell * cellToLink) {
    int r1,r2,c1,c2;
    r1 = row;
    r2 = cellToLink -> row;
    c1 = column;
    c2 = cellToLink -> column;
    if (r1+1 == r2 && c1 == c2) {
        links[south] = cellToLink;
        cellToLink -> links[north] = this;
        return;
    }
    if (r1 == r2+1 && c1 == c2) {
        links[north] = cellToLink;
        cellToLink -> links[south] = this;
        return;
    }
    if (r1 == r2 && c1+1 == c2) {
        links[east] = cellToLink;
        cellToLink -> links[west] = this;
        return;
    }
    if (r1 == r2 && c1 == c2+1) {
        links[west] = cellToLink;
        cellToLink -> links[east] = this;
        return ;
    }
    throw 100;
    return;

}

void cell::unlink( cell * cellToUnlink) {
    int i;
    for (i=0; i<4; i++) {
        if (links[i] == cellToUnlink) {
            links[i] = 0;
        }
        if (cellToUnlink -> links[i] == this) {
            cellToUnlink -> links[i] = 0;
        }
    }
    
}

int cell::countLinks() {
    int i, n = 0;
    for (i=0; i<4; i++) {
        if (this -> links[i])  {
            n++;
        }
    }
    return n;
}

int cell::countNearby() {
    int i, n = 0;
    for (i=0; i<4; i++) {
        if (this -> nearby[i])  {
            n++;
        }
    }
    return n;
}

cell * cell::getNextCell(cell * last) {
    int i;
    cell * ncell;
    for (i=0; i<4; i++) {
        ncell = this -> links[i];
        if (ncell != 0 && ncell != last) {
            return ncell;
        }
    }
    return 0;
}


  labyrinth::labyrinth(int nr, int nc) {
    int  r,c,i;
    rows = nr;
    columns = nc;
    randseed = "3912191E";
    grid = (cell *) malloc(nr*nc*sizeof(cell));
    for (c=0;c<nc;c++){
        for (r=0;r<rows;r++){
            grid[r*nc + c].row =  r;
            grid[r*nc + c].column = c;
            for (i=0;i<4;i++){
                grid[r*nc + c].nearby[i] = 0;
                grid[r*nc + c].links[i] = 0;
            }
        }
    }
    for (c=0;c<columns;c++){
        for (r=0;r<rows;r++){
            if (r>0){
                grid[r*nc + c].nearby[north] = &grid[(r-1)*nc + c];
            }
            if (c>0){
                grid[r*nc + c].nearby[west] = &grid[r*nc + c - 1];
            }
            if (r<rows-1){
                grid[r*nc + c].nearby[south] =  &grid[(r+1)*nc + c];
            }
            if (c<columns-1){
                grid[r*nc + c].nearby[east] = &grid[r*nc + c + 1];
            }
            
        }
    }
    current = grid;
}

labyrinth::~labyrinth() {
    free(grid);
}

int labyrinth::complete() {

    int start, finish;
    start = 0;
    finish = 0;
    cell * scell, * fcell;
    scell = &grid[0];
    fcell = &grid[rows*columns - 1];
    if ((scell -> countLinks() != 1) or (fcell -> countLinks() != 1)) {
        return 0;
    }
    return 1;
    
}


void labyrinth::seed(){
    int r,c;
    int direction;
    cell * cell1;
    cell * cell2;
    direction = east;
    for (r=0;r<rows;r++) {
        for (c=0;c<columns;c++) {
            cell1 = &grid[r*columns + c];
            if (cell1 -> nearby[direction]) {
                cell2 = cell1 -> nearby[direction];
                cell1 -> link(cell2);
            } else if (cell1 -> nearby[south]) {
                cell2 = cell1 -> nearby[south];
                cell1 -> link(cell2);
            }
            
        }
        if (direction == east) {
            direction = west;
        } else {
            direction = east;
        }
    }
}

void labyrinth::setCurrent(int r,int c) {
    current = &grid[r*columns+c];
}

void labyrinth::step(int drow, int dcol){
    int cr, cc, i, ir, ic;
    cell * next;
    cr = current -> row;
    cc = current -> column;
    ir = cr;
    ic =cc;
    for (i=0; i<abs(drow); i++) {
        ir = (cr + (sign(drow)*(i+1))) % rows;
        next = &grid[ir*columns+ic];
        current -> link(next);
        current = next;
    }
    for (i=0; i<abs(dcol); i++) {
        ic = (cc + (sign(dcol)*(i+1))) % columns;
        next = &grid[ir*columns+ic];
        current -> link(next);
        current = next;
    }
}

cell * labyrinth::getTargetCell(cell * head) {
    int i, n;
    n = rand() % (head -> countNearby() - 1);
    for (i=0; i<4; i++){
        if ((head -> nearby[i]) && !(head -> links[i])) {
            if (!n) {
                return (head -> nearby[i]);
            }
            n--;
        }
    }
    return 0;
}

cell * labyrinth::getCell(int r, int c) {
    return &grid[r*columns+c];
}

cell * labyrinth::getHead() {
    int n, i;
    cell * ccell;
    n = rand() % 2;
    for (i=0; i<rows*columns; i++) {
        ccell = &grid[i];
        if (ccell -> countLinks() == 1) {
            if (!n) {
                return ccell;
            } else {
                n--;
            }
        }
    }
    return 0;
}


void labyrinth::backBite(){
    int  i, n;
    cell * head, * target;
    cell * removeLinkQ[4] = {0,0,0,0};
    head = getHead();
    target = getTargetCell(head);
    n = 0;
    for (i=0; i<4; i++){
        if (target -> links[i]) {
            removeLinkQ[n] = target -> links[i];
            n++;
        }
    }
    head -> link(target);
    target -> unlink(removeLinkQ[0]);
//    if (removeLinkQ[1]==0) {
//        temp = removeLinkQ[1];
//        return;
//    }
    if (hamiltonPathQ()) {
        return;
    }
    target -> link(removeLinkQ[0]);
    target -> unlink(removeLinkQ[1]);
}



int labyrinth::hamiltonPathQ() {
    int i;
    int ncells;
    cell * ccell;
    cell * ncell;
    cell * lcell;
    ncells = 0;
    ncell = 0;
    lcell = 0;
    for (i=0; i<rows*columns; i++) {
        ccell = &grid[i];
        if (ccell -> countLinks() == 1) {
            ncell = ccell -> getNextCell(lcell);
            ncells = 1;
            while ( ncell -> countLinks() == 2 ) {
                ncells++;
                if (ncells > rows * columns) {
                    return 0;
                }
                lcell = ccell;
                ccell = ncell;
                ncell = ccell -> getNextCell(lcell);
                lcell = ccell;
            }
            ncells++;
            if (ncells  != rows * columns) {
                return 0;
            }
            return 1;
        }
    }
    return 0;
}

void labyrinth::drawGraph(string name){

    const int pointsPerCell = 18;
    const double pi = 3.14159265358979323846;
    const int WIDTH = columns*pointsPerCell;
    const int HEIGHT = rows*pointsPerCell;
    int i, j, k;
    double x, y;
    int ncells;
    cell * ccell;
    cell * ecell;
    cell * scell;

    cairo_surface_t *surface;
    cairo_t *ctx;

    surface = cairo_svg_surface_create(name.c_str(), WIDTH, HEIGHT);
    ctx = cairo_create(surface);

    cairo_set_line_join(ctx, CAIRO_LINE_JOIN_MITER);
    cairo_stroke(ctx);
    cairo_set_source_rgb(ctx, 0, 0, 0);
    cairo_set_line_width(ctx, 0.15 * pointsPerCell);

    for (j=0; j<rows*columns; j++) {
        ccell = &grid[j];
        ecell = ccell -> links[1];  //link to the east
        scell = ccell -> links[2];  //;ink to the south
        if (ecell) {
            x = ccell -> column * pointsPerCell + pointsPerCell/2; 
            y = ccell -> row * pointsPerCell + pointsPerCell/2; 
            cairo_move_to(ctx, x, y);
            x = ecell -> column * pointsPerCell + pointsPerCell/2; 
            y = ecell -> row * pointsPerCell + pointsPerCell/2; 
            cairo_line_to(ctx, x, y);
            cairo_stroke(ctx);
        }
        if (scell) {
            x = ccell -> column * pointsPerCell + pointsPerCell/2; 
            y = ccell -> row * pointsPerCell + pointsPerCell/2; 
            cairo_move_to(ctx, x, y);
            x = scell -> column * pointsPerCell + pointsPerCell/2; 
            y = scell -> row * pointsPerCell + pointsPerCell/2; 
            cairo_line_to(ctx, x, y);
            cairo_stroke(ctx);
        }
    }

    for (j=0; j<rows*columns; j++) {
        ccell = &grid[j];
        x = ccell -> column * pointsPerCell + pointsPerCell/2;
        y = ccell -> row * pointsPerCell + pointsPerCell /2;        
        cairo_arc(ctx, x, y, 0.20 * pointsPerCell, 0, 2*pi);
        cairo_fill(ctx);

    }
    unsigned int rc;
    rc = cairo_get_reference_count(ctx);
    cairo_destroy(ctx);
    rc = cairo_surface_get_reference_count(surface);
    cairo_surface_destroy (surface);
 }

void labyrinth::writeJsonFile(string  name) {
    const char * dir[4] ={"\"north\":", "\"east\":", "\"south\":", "\"west\":",};
    int i,j,k;
    cell * ccell;
    std::ofstream myfile;
    myfile.open(name);
    myfile << "[\"<class 'cpp.labyrinth'>\" , ["  <<  rows << "," <<  columns << "] , \""
            << randseed <<   "\", " <<  backBites <<    "]\n";
    for (j=0; j<rows*columns; j++) {
        ccell = &grid[j];
        myfile << "[[" << ccell -> row << "," << ccell -> column << "], {";
        k=0;
        for (i=0;i<4;i++) {
            if ((ccell -> links[i])) {
                if (k) {
                    myfile << ",";
                }
                k++;
                myfile << dir[i] << "[" <<  ccell -> links[i] -> row << "," << ccell -> links[i] -> column << "]";
                                         
            }
        }
        myfile << "}, {}]\n";

    }
    myfile.close();
}

void labyrinth::reflection(labyrinth *original) {
    int r, c, n, m, i, j;
    cell * ccell;
    cell * ocell;
    for (c=0; c<columns; c++) {
        for (r=0; r<rows; r++) {
            ccell = &grid[r*columns+c];
            n = rows - 1 - r;
            m = columns -1 - c;
            ocell = &original->grid[n*columns+m];
            for (i=0;i<4;i++){
                j = i+2;
                j = j % 4;
                if (ocell->links[i]) {
                    ccell->links[j] = ccell->nearby[j];
                } else {
                    ccell->links[j] = 0;
                }
            }
        }
    }
}

void labyrinth::mirror(labyrinth *original) {
    int r, c, n, m, i, j;
    cell * ccell;
    cell * ocell;
    for (c=0; c<columns; c++) {
        for (r=0; r<rows; r++) {
            ccell = &grid[r*columns+c];
            m = columns -1 - c;
            ocell = &original->grid[r*columns+m];
            for (i=1;i<4;i+=2){
                j = i+2;
                j = j % 4;
                if (ocell->links[i]) {
                    ccell->links[j] = ccell->nearby[j];
                } else {
                    ccell->links[j] = 0;
                }
            }
            for (i=0;i<4;i+=2){
                j = i+2;
                j = j % 4;
                if (ocell->links[i]) {
                    ccell->links[i] = ccell->nearby[i];
                } else {
                     ccell->links[i] = 0;
                }
            }
        }
    }
}

void labyrinth::paste(labyrinth *insert, int dr, int dc) {
    int r, c, i;
    cell * ccell;
    cell * icell;
    int icolumns = insert -> columns ;
    int irows= insert -> rows ;
    for (c=0; c<(icolumns); c++) {
        for (r=0; r<(insert -> rows); r++) {
            icell = &insert->grid[r*icolumns+c];
            ccell = &grid[(r+dr)*columns+c+dc];
            for (i=0;i<4;i++){
                if (icell->links[i]) {
                    ccell->links[i] = ccell->nearby[i];
                }
            }

        }
    }
}

void labyrinth::setRandSeed(std::string randomHex) {
    randseed = randomHex;
}


void labyrinth::setBackBites(int i) {
    backBites = i;
}


int sign(int x) {
    return (x > 0) - (x < 0);
}


bool fexists(const char *filename) {
  std::ifstream ifile(filename);
  return (bool)ifile;
}


void jsonError(json j) {
    cout << "json error: " << j.dump() << "\n"; 
}


labyrinth* fromJsonFile(string  name) {
    cell * mytarget;
    ifstream file(name);
    string str; 
    getline(file, str);
    json l = json::parse(str);
    if (!l.is_array()) jsonError(l) ; 
    auto s = l.at(1);
    if (!s.is_array()) jsonError(l) ; 
    auto rows  = s.at(0);
    if (!rows.is_number_unsigned()) jsonError(l) ; 
    auto cols  = s.at(1);
    if (!cols.is_number_unsigned()) jsonError(l) ; 
    labyrinth * L = new labyrinth(rows,cols);    
    while (getline(file, str)){
        json ex1 = json::parse(str);
        if (!ex1.is_array()) jsonError(ex1) ;  
        json ex2 = ex1.at(0);
        if (!ex2.is_array()) jsonError(ex1) ; 
        auto r = ex2.at(0) ;
        auto c = ex2.at(1) ;
        cout << r << " " << c << "\n"; 
        auto mycell = L ->  getCell(r,c) ;  
        json o = ex1.at(1);
        if (!o.is_object()) jsonError(ex1);
        for (json::iterator it = o.begin(); it != o.end(); ++it) {
            cout << it.key() << " : " << it.value() << "\n";
            json t = it.value();
            auto tr = t.at(0);
            auto tc = t.at(1);
            auto mytarget = L ->  getCell(tr,tc) ; 
            mycell -> link(mytarget);
            cout << "target " << tr << " " << tc <<"\n";
        }
    }
    return(L);
}


