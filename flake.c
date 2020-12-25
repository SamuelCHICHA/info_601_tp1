#include <flake.h>
#include <stdlib.h>
#include <stdio.h>

/**
 *
 * @param flake: flake_t *
 * @param x: int
 * @param y; int
 */
void init_flake(flake_t  * flake, int x, int y){
    if(flake == NULL) {
        fprintf(stderr, "Flake is NULL.\n");
        exit(EXIT_FAILURE);
    }
    flake->x = x;
    flake->y = y;
}

