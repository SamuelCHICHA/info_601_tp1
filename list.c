#include "list.h"

#include <stdlib.h>
#include <stdio.h>

void init_list(list_t * list){
    if(list == NULL){
        fprintf(stderr, "Can't access list.\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
}

void insert_list(list_t * list, flake_t * flake){
    cell_t * new_cell = NULL;
    if(list == NULL){
        fprintf(stderr, "Can't access list.\n");
        exit(EXIT_FAILURE);
    }
    new_cell = alloc_cell();
    new_cell->flake.x = flake->x;
    new_cell->flake.y = flake->y;
    if(list->head != NULL)
        list->head->prev = new_cell;
    new_cell->next = list->head;
    list->head = new_cell;
    new_cell->prev = NULL;
}

void print_list(list_t * list){
    cell_t * parse_cell = NULL;
    int i;
    if(list == NULL){
        fprintf(stderr, "List is NULL.\n");
        exit(EXIT_FAILURE);
    }
    for(parse_cell = list->head, i = 0; parse_cell != NULL; parse_cell = parse_cell->next, i++)
        printf("Flake %d: {%d, %d}", i, parse_cell->flake.x, parse_cell->flake.y);
    printf("\n");
}

void delete_list(list_t * list, cell_t * cell){
    if(list == NULL){
        fprintf(stderr, "List is NULL.\n");
        exit(EXIT_FAILURE);
    }
    if(cell == NULL){
        fprintf(stderr, "Cell is NULL.\n");
    } else {
        if(cell->prev != NULL)
            cell->prev->next = cell->next;
        else
            list->head = cell->next;
        if(cell->next != NULL)
            cell->next->prev = cell->prev;
        free(cell);
    }
}

void empty_list(list_t * list){
    if(list == NULL){
        fprintf(stderr, "List is NULL.\n");
        exit(EXIT_FAILURE);
    }
    while(list->head != NULL)
        delete_list(list, list->head);
}

int list_count(list_t * list){
    cell_t * parse_cell = NULL;
    int i;
    if(list == NULL){
        fprintf(stderr, "List is NULL.\n");
        exit(EXIT_FAILURE);
    }
    for(parse_cell = list->head, i = 0; parse_cell != NULL; parse_cell = parse_cell->next, i++){}
    return i;
}
