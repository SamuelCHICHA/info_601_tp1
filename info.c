#include <stdlib.h>
#include <string.h>

#include <info.h>

/**
 * Allocate a window with information.
 * @param width the window's width.
 * @param height the window's height.
 * @param x the window's position on the x-axe.
 * @param y the window's position on the y-axe.
 * @return 0 if all good, 1 if error when
 */
int init_info_w(info_w_t * infoW, int width, int height, int x, int y){
    int ret = 0;
    if(infoW == NULL){
        fprintf(stderr, "Can't access information window.\n");
        ret = 1;
    } else {
        infoW->window = init_window("Infos", width, height, x, y);
        infoW->width = width;
        infoW->height = height;
    }
    return ret;
}

/**
 * Free memory space.
 * @param i the information window.
 */
void destroy_info_w(info_w_t * i){
    if(i == NULL){
        fprintf(stderr, "Can't access info window.\n");
        exit(EXIT_FAILURE);
    }
    destroy_window(i->window);
}

/**
 * Add information to the information's window then display it.
 * @param i window
 * @param infos information
 */
void add_infos(info_w_t * i, char * infos){
    if(i == NULL){
        fprintf(stderr, "Error trying to access the information window.\n");
        exit(EXIT_FAILURE);
    }
    if(infos == NULL){
        fprintf(stderr, "Error trying to access the information.\n");
        exit(EXIT_FAILURE);
    }
    if(strlen(infos) > MAX_LENGTH_INFO){
        fprintf(stderr, "Information is too long.\n");
    } else {
        strncpy(i->infos[2], i->infos[1], MAX_LENGTH_INFO);
        strncpy(i->infos[1], i->infos[0], MAX_LENGTH_INFO);
        strncpy(i->infos[0], infos, MAX_LENGTH_INFO);
        display_infos(i);
    }
}

/**
 * Display information from the information's window.
 * @param i window
 */
void display_infos(info_w_t * i){
    int j;
    if(i == NULL){
        fprintf(stderr, "Error trying to access the information window.\n");
        exit(EXIT_FAILURE);
    }
    wclear(i->window->sub_window);
    for(j = 0; j < NB_INFOS; ++j)
        wprintw(i->window->sub_window, "%s\n", i->infos[j]);
    refresh_content(i->window);
}
