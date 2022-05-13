/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** status
*/

#include "main.h"

inventory_t *creation2(inventory_t *new)
{
    new->status = 0;
    return new;
}

void find_status(main_t *main)
{
    inventory_t *tmp = main->inv;

    if (main->inv->status == 0)
        sfSprite_setTexture(tmp->sort->spr, tmp->sort->neutral, sfFalse);
    if (main->inv->status == 1)
        sfSprite_setTexture(tmp->sort->spr, tmp->sort->texture1, sfFalse);
    if (main->inv->status == 2)
        sfSprite_setTexture(tmp->sort->spr, tmp->sort->texture2, sfFalse);
    if (main->inv->status == 3)
        sfSprite_setTexture(tmp->sort->spr, tmp->sort->texture3, sfFalse);
    if (main->inv->status == 4)
        sfSprite_setTexture(tmp->sort->spr, tmp->sort->texture4, sfFalse);
    return;
}

status_t *set_status(void)
{
    status_t *new = malloc(sizeof(*new));
    sfVector2f pos = {1330, 120};
    sfVector2f scale = {0.8, 0.8};
    sfVector2f scale2 = {1.3, 1.3};

    new->spr = sfSprite_create();
    new->status = btn_text("Status :", 1100, 100, scale);
    new->pos = pos;
    sfSprite_setPosition(new->spr, new->pos);
    new->neutral = sfTexture_createFromFile(NEU, NULL);
    sfSprite_setTexture(new->spr, new->neutral, sfFalse);
    new->texture1 = sfTexture_createFromFile(POI, NULL);
    new->texture2 = sfTexture_createFromFile(BUR, NULL);
    new->texture3 = sfTexture_createFromFile(GEL, NULL);
    new->texture4 = sfTexture_createFromFile(MAG, NULL);
    sfSprite_setScale(new->spr, scale2);
    return new;
}
