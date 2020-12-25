#include <simu.h>
#include <stdlib.h>

/**
 * Initialize a simulation window
 * @param width: int
 * @param height: int
 * @param x: int
 * @param y: int
 * @return 0 if all good or 1 if access error.
 */
int init_simu_w(simu_w_t * simuW, int width, int height, int x, int y){
    int ret = 0;
    if(simuW == NULL){
        fprintf(stderr, "Can't access simulation window.\n");
        ret = 1;
    } else {
        simuW->width = width;
        simuW->height = height;
        simuW->window = init_window("Simulation", width, height, x, y);
    }
    return ret;
}

/**
 * Free the memory for a simulation window
 * @param s: simu_w_t *
 */
void destroy_simu_w(simu_w_t * s){
    if(s == NULL){
        fprintf(stderr, "Error accessing simulation window.\n");
        exit(EXIT_FAILURE);
    }
    destroy_window(s->window);
}

/**
 * Handle the flake's fall.
 * @param s the window.
 * @param f the flake.
 * @param b the blocks.
 * @param nb_blocks the number of blocks.
 * @return true if the flake has "died"
 */
bool fall(simu_w_t * s, flake_t * f, block_t * b, int nb_blocks){
    bool is_out = false;
    if(s == NULL){
        fprintf(stderr, "Error accessing simulation window.\n");
        exit(EXIT_FAILURE);
    }
    if(f == NULL){
        fprintf(stderr, "Error accessing the flake.\n");
        exit(EXIT_FAILURE);
    }
    if(b == NULL){
        fprintf(stderr, "Error accessing the blocks.\n");
        exit(EXIT_FAILURE);
    }
    if(f->y + 1 >= s->height){
        /* The flake is falling below */
        is_out = true;
    } else {
        if(!is_blocked(b, nb_blocks, f->x, f->y + 1))
            f->y++;
        else {
            /* WARNING: window size 0->n-1 or 1->n */
            if(f->x - 1 > 0 && !is_blocked(b, nb_blocks, f->x - 1, f->y + 1)) {
                f->y++;
                f->x--; 
            } else if(f->x + 1 < s->width && !is_blocked(b, nb_blocks, f->x + 1, f->y + 1)){
                f->y++;
                f->x++;
            }
        }
    }
    return is_out;
}

/**
 * Check if there is a block at the position indicated.
 * @param b the blocks.
 * @param nb_blocks the number of blocks.
 * @param x the position's x.
 * @param y the position's y.
 * @return true if there is a block at the position {x,y}, false otherwise.
 */
bool is_blocked(block_t * b, int nb_blocks, int x, int y){
    int i = 0;
    bool is_blocked = true;
    if(b == NULL){
        fprintf(stderr, "Error accessing the blocks.\n");
        exit(EXIT_FAILURE);
    }
    while(i < nb_blocks && (b[i].x != x || b[i].y != y)){
        i++;
    }
    if(i >= nb_blocks) is_blocked = false;
    return is_blocked;
}


void display_flakes(simu_w_t * s, list_t * f){
    cell_t * parse = NULL;
    if(s == NULL){
        fprintf(stderr, "Error accessing simulation window.\n");
        exit(EXIT_FAILURE);
    }
    if(f == NULL){
        fprintf(stderr, "Error accessing the flakes.\n");
        exit(EXIT_FAILURE);
    }
    for(parse = f->head; parse != NULL; parse = parse->next){
        wmove(s->window->sub_window, parse->flake.y, parse->flake.x);
        waddch(s->window->sub_window, FLAKE);
    }
}

void display_blocks(simu_w_t * s, block_t * b, int nb_blocks){
    int i;
    if(b == NULL){
        fprintf(stderr, "Error accessing the blocks.\n");
        exit(EXIT_FAILURE);
    }
    if(s == NULL){
        fprintf(stderr, "Error accessing simulation window.\n");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i< nb_blocks; i++){
        wmove(s->window->sub_window, b[i].y, b[i].x);
        waddch(s->window->sub_window, BLOCK);
    }
}

void display(simu_w_t * s, block_t * b, list_t * f, int nb_blocks){
    if(s == NULL){
        fprintf(stderr, "Error accessing simulation window.\n");
        exit(EXIT_FAILURE);
    }
    if(f == NULL){
        fprintf(stderr, "Error accessing the flake.\n");
        exit(EXIT_FAILURE);
    }
    if(b == NULL){
        fprintf(stderr, "Error accessing the blocks.\n");
        exit(EXIT_FAILURE);
    }
    wclear(s->window->sub_window);
    display_blocks(s, b, nb_blocks);
    display_flakes(s, f);
    refresh_content(s->window);
}

void flakes_fall(simu_w_t * s, list_t * f, block_t * b, int nb_blocks) {
    cell_t * parse = NULL;
    if(s == NULL){
        fprintf(stderr, "Error accessing simulation window.\n");
        exit(EXIT_FAILURE);
    }
    if(f == NULL){
        fprintf(stderr, "Error accessing the flakes.\n");
        exit(EXIT_FAILURE);
    }
    if(b == NULL){
        fprintf(stderr, "Error accessing the blocks.\n");
        exit(EXIT_FAILURE);
    }
    for(parse = f->head; parse != NULL; parse = parse->next){
        if(fall(s, &parse->flake, b, nb_blocks))
            delete_list(f, parse);
        display(s, b, f, nb_blocks);
    }
}
