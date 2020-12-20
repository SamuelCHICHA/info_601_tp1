#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

typedef struct window{
    WINDOW * sub_window;
    WINDOW * frame;
    char title[20];
} window_t;

window_t * init_window(char * title, int width, int height, int x, int y);
void refresh_content(window_t * w);
void refresh_window(window_t * w);
void destroy_window(window_t * w);

#endif /* WINDOW_H */