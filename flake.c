#include <flake.h>
#include <stdlib.h>
#include <stdio.h>

int init_flake(flake_t  * flake, int x, int y){
    int ret = 0;
    if(flake == NULL) {
        fprintf(stderr, "Flake is NULL.\n");
        ret = 1;
    }
    flake->x = x;
    flake->y = y;
    return ret;
}

