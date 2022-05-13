/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** funct2
*/

#include "main.h"

void chek_a_save(main_t *main, button_t *btn, sfVector2f w, int *tmp)
{
    int xmn = tmp[0];
    int xmx = tmp[1];
    int ymn = tmp[2];
    int ymx = tmp[3];

    if (w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx) {
        main->event = 0;
        main->wind.menu = 1;
        find_btn(btn, main);
        delation(main);
    }
}

void save_save(main_t *main)
{
    main->wind.menu = 1;
    main->event = 0;
    if (main->creating == 1)
        do_do(main, 1);
    if (main->creating == 2)
        do_do(main, 2);
    if (main->creating != 1 && main->creating != 2)
        do_do(main, 3);
    reset_entry(main);
}
