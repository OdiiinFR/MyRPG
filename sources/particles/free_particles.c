/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** free_particles
*/

#include "main.h"

void free_circles(main_t *main)
{
    sfCircleShape_destroy(main->circles->spr_circle);
    for (int i = 0; i < 4000; i++) {
        sfCircleShape_destroy(main->circles->circle[i]->crc);
        free(main->circles->circle[i]);
    }
    free(main->circles);
}

void free_rain(main_t *main)
{
    for (int i = 0; i < 12000; i++) {
        sfSprite_destroy(main->rain->drop[i]->drp);
        sfTexture_destroy(main->rain->drop[i]->drop);
        free(main->rain->drop[i]);
    }
    free(main->rain);
}
