#ifndef LIST_H
#define LIST_H

#include <cell.h>

typedef struct{
    cell_t * head;
}list_t;

void init_list(list_t *);
void insert_list(list_t *, flake_t *);
void print_list(list_t *);
void delete_list(list_t *, cell_t *);
void empty_list(list_t *);
int list_count(list_t *);

#endif //LIST_H
