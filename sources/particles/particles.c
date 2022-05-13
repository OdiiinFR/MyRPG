/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** particles
*/

#include "main.h"

void do_fog(main_t *main)
{
    float mvnt;

    sfRenderWindow_drawCircleShape(main->wind.window,
    main->circles->spr_circle, NULL);
    for (int i = 0; i < 4000; i++) {
        mvnt = rand() % main->circles->circle[i]->radius * 0.002;
        main->circles->circle[i]->pos.x += mvnt;
        main->circles->circle[i]->pos.x >= 6000 ?
            main->circles->circle[i]->pos.x = -6000 : 0;
        sfCircleShape_setPosition(main->circles->circle[i]->crc,
            main->circles->circle[i]->pos);
        sfRenderWindow_drawCircleShape(main->wind.window,
            main->circles->circle[i]->crc, NULL);
    }
}

void do_rain(main_t *main)
{
    float mvnt;
    void *new = malloc(8);
    unsigned long a = (unsigned long)new;

    srand(a);
    for (int i = 0; i < 12000; i++) {
        mvnt = main->rain->drop[i]->speed;
        main->rain->drop[i]->pos.y += mvnt;
        main->rain->drop[i]->pos.y >= 6000 ?
            main->rain->drop[i]->pos.y = -6000 : 0;
        sfSprite_setPosition(main->rain->drop[i]->drp,
            main->rain->drop[i]->pos);
        sfRenderWindow_drawSprite(main->wind.window,
            main->rain->drop[i]->drp, NULL);

    }
}
