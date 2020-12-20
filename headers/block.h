#ifndef BLOCK_H
#define BLOCK_H

#include <ncurses.h>

#define BLOCK (ACS_TTEE)

typedef struct block{
    int x,y;
}block_t;

int init_block(block_t *,int, int);

#endif /* BLOCK_H */