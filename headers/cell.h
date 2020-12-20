#ifndef CELL_H
#define CELL_H

#include <flake.h>

typedef struct cell_t{
    struct cell_t * prev, * next;
    flake_t flake;
}cell_t;

cell_t * alloc_cell();

#endif //CELL_H