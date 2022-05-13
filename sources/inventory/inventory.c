/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** inventory
*/

#include "main.h"

sfVector2f set_y(int j)
{
    sfVector2f res = {340, 420};

    if (j == 1) {
        res.x = 490;
        res.y = 550;
    }
    if (j == 2) {
        res.x = 630;
        res.y = 690;
    }
    if (j == 3) {
        res.x = 755;
        res.y = 822;
    }
    if (j == 4) {
        res.x = 900;
        res.y = 960;
    }
    return res;
}

void set_pos(object_t **new, int i, int j)
{
    sfVector2f pos_spr = {990, 340};
    sfVector2f pos_txt1 = {868, 420};
    sfVector2f pos_txt2 = {1130, 420};
    sfVector2f tmp;

    if (i == 1) {
        pos_spr.x = 1320;
        pos_txt1.x = 1181;
        pos_txt2.x = 1480;
    }
    tmp = set_y(j);
    pos_spr.y = tmp.x;
    pos_txt1.y = tmp.y;
    pos_txt2.y = pos_txt1.y;
    new[i][j].pos_spr = pos_spr;
    new[i][j].pos_txt1 = pos_txt1;
    new[i][j].pos_txt2 = pos_txt2;
    return;
}

object_t **create_list(void)
{
    object_t **new = malloc(sizeof(object_t *) * 3);

    for (int i = 0; i < 2; i += 1) {
        new[i] = malloc(sizeof(object_t) * 5);
        for (int j = 0; j < 5; j += 1) {
            new[i][j].name = NULL;
            new[i][j].type = NULL;
            new[i][j].nb = 0;
            new[i][j].reference = 0;
            new[i][j].spr = sfSprite_create();
            set_pos(new, i, j);
        }
    }
    new[2] = NULL;
    return new;
}

object_t **create_equipment(void)
{
    object_t **new = malloc(sizeof(object_t *) * 2);

    new[0] = malloc(sizeof(object_t) * 4);
    for (int j = 0; j < 4; j += 1) {
        new[0][j].name = NULL;
        new[0][j].type = NULL;
        new[0][j].nb = 0;
        new[0][j].reference = 100;
        new[0][j].mod = 0;
    }
    new[1] = NULL;
    return new;
}

inventory_t *creation(void)
{
    inventory_t *new = malloc(sizeof(*new));
    sfVector2f pos = {190, -205};
    sfVector2f scale = {1, 1};

    new->stats = set_up_stat();
    new->list = create_list();
    new->equiped = create_equipment();
    new->spr = sfSprite_create();
    new->texture = sfTexture_createFromFile(INV, NULL);
    new->pos = pos;
    new->sort = set_status();
    new->inv = btn_text("Inventory\0", 900, 30, scale);
    new->equip = btn_text("Equipped\0", 470, 780, scale);
    new->preview = btn_text("Preview\0", 480, 300, scale);
    new->perso = btn_text("Char\0", 410, 30, scale);
    new->statistics = btn_text("Stats\0", 680, 90, scale);
    new->all = set_inv();
    sfSprite_setTexture(new->spr, new->texture, sfFalse);
    sfSprite_setPosition(new->spr, new->pos);
    return creation2(new);
}
