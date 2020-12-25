#include <status.h>
#include <block.h>
#include <flake.h>
#include <stdlib.h>

int init_status_w(status_w_t * statusW, int width, int height, int x, int y){
    int ret = 0;
    if(statusW == NULL){
        fprintf(stderr, "Can't access status window.\n");
        ret = 1;
    } else {
        statusW->window = init_window("Etat", width, height, x, y);
    }
    return ret;
}

void destroy_status_w(status_w_t * s){
    if(s == NULL){
        fprintf(stderr, "Error accessing status window.\n");
        exit(EXIT_FAILURE);
    }
    destroy_window(s->window);
}

void print_status(status_w_t * s, int nb_flakes){
    if(s == NULL){
        fprintf(stderr, "Error accessing status window.\n");
        exit(EXIT_FAILURE);
    }
    wclear(s->window->sub_window);
    wprintw(s->window->sub_window, "Flocons: %d\n\n", nb_flakes);
    waddch(s->window->sub_window, BLOCK);
    wprintw(s->window->sub_window, " Obstacle\n");
    waddch(s->window->sub_window, FLAKE);
    wprintw(s->window->sub_window, " Flocons\n");
    refresh_content(s->window);
}
