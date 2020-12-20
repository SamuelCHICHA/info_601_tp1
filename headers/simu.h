#ifndef SIMU_H
#define SIMU_H

#include <window.h>
#include <list.h>
#include <block.h>

typedef struct simulation_window{
    window_t * window;
    int width, height;
} simu_w_t;

int init_simu_w(simu_w_t *, int width, int height, int x, int y);
void destroy_simu_w(simu_w_t * s);
void flakes_fall(simu_w_t * s, list_t * f, block_t * b, int nb_blocks);
bool fall(simu_w_t * s, flake_t * f, block_t * b, int nb_blocks);
bool is_blocked(block_t * b, int nb_blocks, int x, int y);
void display_flakes(simu_w_t * s, list_t * f);
void display_blocks(simu_w_t * s, block_t * b, int nb_blocks);
void display(simu_w_t * s, block_t * b, list_t * f, int nb_blocks);
#endif /* SIMU_H */
