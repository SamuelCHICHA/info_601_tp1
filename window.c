#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <window.h>

/**
 * Allocate and init a ncurses window.
 * @param x Window's width.
 * @param y Window's height.
 * @return window's newly allocated pointer or NULL.
 */
window_t * init_window(char * title, int width, int height, int x, int y){
    window_t * window = NULL;
    window = (window_t *)malloc(sizeof(window_t));
    strncpy(window->title, title, 19);
    window->frame = newwin(height, width, y, x);
    box(window->frame, 0, 0);
    window->sub_window = subwin(window->frame, height - 2, width - 2, y + 1, x + 1);
    wprintw(window->frame, "  %s  ", title);
    refresh_window(window);
    return window;
}

/**
 * Refresh the content of the window.
 * @param w window.
 */
void refresh_content(window_t * w){
    if(w == NULL){
        fprintf(stderr, "Error trying to access the window.\n");
        exit(EXIT_FAILURE);
    }
    wrefresh(w->sub_window);
}

/**
 * Refresh all the window.
 * @param w window
 */
void refresh_window(window_t * w){
    if(w == NULL){
        fprintf(stderr, "Error trying to access the window.\n");
        exit(EXIT_FAILURE);
    }
    wrefresh(w->sub_window);
    wrefresh(w->frame);
}

/**
 * Free memory space.
 * @param w mother window.
 */
void destroy_window(window_t * w){
    if(w == NULL){
        fprintf(stderr, "Error trying to access the window.\n");
        exit(EXIT_FAILURE);
    }
    delwin(w->sub_window);
    delwin(w->frame);
    free(w);
}