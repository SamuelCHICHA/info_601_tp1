#include "cell.h"

#include <stdio.h>
#include <stdlib.h>

cell_t * alloc_cell(){
    cell_t * cell = NULL;
    if((cell = (cell_t *)malloc(sizeof(cell_t))) == NULL){
        fprintf(stderr, "Error allocating cell.\n");
        exit(EXIT_FAILURE);
    }
    cell->prev = NULL;
    cell->next = NULL;
    return cell;
}