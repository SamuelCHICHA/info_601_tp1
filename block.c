#include <block.h>
#include <stdio.h>

int init_block(block_t  * block, int x, int y){
    int ret = 0;
    if(block == NULL){
        fprintf(stderr, "Block is NULL.\n");
        ret = 1;
    }
    block->x = x;
    block->y = y;
    return ret;
}