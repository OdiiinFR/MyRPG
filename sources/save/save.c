/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** save
*/

#include "main.h"

void do_do(main_t *main, int fd)
{
    reset_stats(main);
    do_create2(main, fd);
    create_a_save(main, (fd - 1));
}

int find_new(button_t *btn)
{
    if (btn->position.x == 450)
        return 0;
    else if (btn->position.x == 850)
        return 1;
    else
        return 2;
}

void print_save(button_t *btn, main_t *main)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx) {
        if (btn->function == 50)
            main->event = 0;
        create_a_save(main, main->in_save);
    }
    return;
}
