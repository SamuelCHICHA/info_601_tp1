#include <stdio.h>
#include <info.h>
#include <simu.h>
#include <status.h>
#include <stdlib.h>
#include <ncurses_extra.h>
#include <list.h>
#include <time.h>
#include <unistd.h>


/**
 *
 * We could use an hash table for the flakes ?
 * O(log(n)) for the search
 * O(log(1)) for the insertion
 */


int main() {
    int i;
    char info[MAX_LENGTH_INFO];
    flake_t tmp;
    info_w_t infoW;
    simu_w_t simuW;
    status_w_t statusW;
    block_t * blocks = NULL;
    list_t flakes;
    ncurses_initialiser();
    ncurses_couleurs();
    init_list(&flakes);
    init_info_w(&infoW ,COLS, NB_INFOS, 0, 0);
    init_simu_w(&simuW, COLS * 3 / 4, LINES - NB_INFOS, 0, infoW.height);
    init_status_w(&statusW, COLS / 4, LINES - NB_INFOS, simuW.width, infoW.height);
    srand(getpid() * time(NULL));
    add_infos(&infoW, "Press F2 to quit.");
    blocks = (block_t *)malloc(simuW.height * sizeof(block_t));
    for(i = 0; i  < LINES - NB_INFOS; i++)
        init_block(&blocks[i], rand() % simuW.width, i);
    display_blocks(&simuW, blocks, simuW.height);
    refresh_window(simuW.window);
    print_status(&statusW, 0);
    timeout(1000);
    while (getch() != KEY_F(2)){
        flakes_fall(&simuW, &flakes, blocks, simuW.height);
        init_flake(&tmp, rand() % simuW.width, 0);
        snprintf(info, MAX_LENGTH_INFO,"Une boule de neige est apparu en {%d, %d}.", tmp.x, tmp.y);
        add_infos(&infoW, info);
        insert_list(&flakes, &tmp);
        print_status(&statusW, list_count(&flakes));
    }
    destroy_info_w(&infoW);
    destroy_simu_w(&simuW);
    destroy_status_w(&statusW);
    free(blocks);
    empty_list(&flakes);
    ncurses_stopper();
    return EXIT_SUCCESS;
}
