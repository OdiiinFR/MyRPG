/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** create_rain
*/

#include "main.h"

static drop_t **create_list(void)
{
    drop_t **new = malloc(sizeof(drop_t *) * 12001);
    sfVector2f scale = {0.5, 0.5};

    for (int i = 0; i < 12000; i += 1) {
        new[i] = malloc(sizeof(drop_t));
        new[i]->drp = sfSprite_create();
        new[i]->drop = sfTexture_createFromFile(DROP, NULL);
        sfSprite_setTexture(new[i]->drp, new[i]->drop, sfFalse);
        sfSprite_setScale(new[i]->drp, scale);
    }
    new[12000] = malloc(sizeof(drop_t));
    new[12000] = NULL;
    return new;
}

static void draw_rain(drop_t *drop)
{
    sfVector2f pos;
    void *new = malloc(8);
    unsigned long a = (unsigned long)new;
    srand(a);
    pos.x = rand() % 12000 - 6000;
    pos.y = rand() % 12000 - 6000;
    drop->pos = pos;
    drop->speed = rand() % 10 + 5;
    sfSprite_setPosition(drop->drp, pos);
}

rain_t *create_rain(void)
{
    rain_t *new = malloc(sizeof(rain_t));

    new->drop = create_list();
    for (int i = 0; i < 12000; i++)
        draw_rain(new->drop[i]);
    return new;
}
