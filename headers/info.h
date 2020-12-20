#ifndef INFO_H
#define INFO_H

#define NB_INFOS 5
#define MAX_LENGTH_INFO 100

#include "window.h"

typedef struct info_window{
    window_t * window;
    int width, height;
    char infos[NB_INFOS][MAX_LENGTH_INFO];
} info_w_t;

int init_info_w(info_w_t *, int width, int height, int x, int y);
void destroy_info_w(info_w_t * i);
void add_infos(info_w_t * i, char * infos);
void display_infos(info_w_t * i);

#endif /* INFO_H */