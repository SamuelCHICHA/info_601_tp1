#ifndef STATUS_H
#define STATUS_H

#define NB_STATUS 2
#define STATUS_LENGTH 20

#include "window.h"

typedef struct status_window{
    window_t * window;
    char legendes[NB_STATUS][STATUS_LENGTH];
} status_w_t;

int init_status_w(status_w_t *, int width, int height, int x, int y);
void destroy_status_w(status_w_t * s);
void print_status(status_w_t * s, int nb_flakes);

#endif /* STATUS_H */