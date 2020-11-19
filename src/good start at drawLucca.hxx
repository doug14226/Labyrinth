void labyrinth::drawGraph(const char  name[]){

    const int pointsPerCell = 18;
    const int WIDTH = columns*pointsPerCell;
    const int HEIGHT = rows*pointsPerCell;
    int i, j, k;
    int ncells;
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
        return
    }

    surface = cairo_svg_surface_create(name, WIDTH, HEIGHT);
    ctx = cairo_create(surface);

    cairo_set_line_join(ctx, CAIRO_LINE_JOIN_MITER);
    cairo_stroke(ctx);
    cairo_set_source_rgb(ctx, 0, 0, 0);
    cairo_set_line_width(ctx, 0.15 * pointsPerCell);

    for (j=0; j<rows*columns; j++) {
            ccell = &grid[i];
        if (ccell -> countLinks() == 1) {
            ncell = ccell -> getNextCell(lcell);
            break;
        }
    }

// draw first line from ccell to ncell

    while ( ncell -> countLinks() == 2 ) {
        lcell = ccell;
        ccell = ncell;
        ncell = ccell -> getNextCell(lcell);
        lcell = ccell;
// draw first line from ccell to ncell   
    }

    for (j=0; j<rows*columns; j++) {
//  draw the nodes
    }
 }
