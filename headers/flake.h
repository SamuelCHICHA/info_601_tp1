#ifndef FLAKE_H
#define FLAKE_H

#include <ncurses.h>

#define FLAKE (ACS_DIAMOND)

typedef struct flake{
    int x, y;
}flake_t;

void init_flake(flake_t  *, int, int);

#endif /* FLAKE_H */