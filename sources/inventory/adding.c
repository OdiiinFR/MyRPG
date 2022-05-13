/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** adding
*/

#include "main.h"

void update_inv(main_t *main, inventory_t *inv, sfRenderWindow *wind)
{
    for (int j = 0; j < 5; j += 1) {
        if (inv->list[0][j].name != NULL) {
            sfRenderWindow_drawSprite(wind, inv->list[0][j].spr, NULL);
            sfRenderWindow_drawText(wind, inv->list[0][j].print_nb, NULL);
            sfRenderWindow_drawText(wind, inv->list[0][j].print_name, NULL);
        }
    }
    for (int j = 0; j < 5; j += 1) {
        if (inv->list[1][j].name != NULL) {
            sfRenderWindow_drawSprite(wind, inv->list[1][j].spr, NULL);
            sfRenderWindow_drawText(wind, inv->list[1][j].print_nb, NULL);
            sfRenderWindow_drawText(wind, inv->list[1][j].print_name, NULL);
        }
    }
    for (int j = 0; j < 4; j += 1) {
        if (inv->equiped[0][j].name != NULL)
            sfRenderWindow_drawSprite(wind, inv->equiped[0][j].spr, NULL);
    }
    drag_drop(main, inv);
    return;
}

object_t *add(char *path, char *name, char *type, int ref)
{
    object_t *new = malloc(sizeof(object_t));
    sfVector2f pos = {0, 0};
    sfVector2f scale = {0.8, 0.8};

    new->name = name;
    new->nb = 0;
    new->reference = ref;
    new->spr = sfSprite_create();
    new->type = type;
    new->mod = 10;
    new->print_name = btn_text(name, 0, 0, scale);
    new->print_nb = btn_text(my_itoa(new->nb), 0, 0, scale);
    new->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setPosition(new->spr, pos);
    sfSprite_setTexture(new->spr, new->texture, sfFalse);
    if (strcompare(type, "type\0") == 0)
        new->equip = sfFalse;
    else
        new->equip = sfTrue;
    return new;
}

object_t **set_inv(void)
{
    object_t **new = malloc(sizeof(object_t *) * 12);

    new[0] = add(PHONE, "Phone\0", "type\0", 0);
    new[1] = add(CHOCO, "Choco bar\0", "type\0", 1);
    new[2] = add(BIBLE, "Bible\0", "Attack\0", 2);
    new[3] = add(CLOVER, "Clover\0", "Defence\0", 3);
    new[4] = add(FLOWER, "Flower\0", "Healing\0", 4);
    new[5] = add(HAIR, "Hairpin\0", "Defence\0", 5);
    new[6] = add(HAND, "Hand\0", "type\0", 6);
    new[7] = add(LUCK, "Lucky Coin\0", "type\0", 7);
    new[8] = add(BIRD, "Bird\0", "type\0", 8);
    new[9] = add(DUCK, "Duck\0", "type\0", 9);
    new[10] = add(POP, "Pop Corn\0", "Healing\0", 10);
    new[11] = NULL;
    return new;
}

my_stat_t *set_up_stat2(my_stat_t *new)
{
    sfVector2f pos1 = {710, 200};
    sfVector2f pos2 = {960, 220};
    sfVector2f pos3 = {1210, 220};
    sfVector2f scale = {1, 1};

    sfSprite_setPosition(new[0].spr, pos1);
    new[0].pos = pos1;
    new[0].print = btn_text(my_itoa(new[0].stat), 800, 185, scale);
    sfSprite_setPosition(new[1].spr, pos2);
    new[1].pos = pos2;
    new[1].print = btn_text(my_itoa(new[1].stat), 1040, 185, scale);
    sfSprite_setPosition(new[2].spr, pos3);
    new[2].pos = pos3;
    new[2].print = btn_text(my_itoa(new[2].stat), 1300, 185, scale);
    return new;
}

my_stat_t *set_up_stat(void)
{
    my_stat_t *new = malloc(sizeof(my_stat_t) * 3);

    new[0].name = "Life\0";
    new[0].stat = 100;
    new[0].texture = sfTexture_createFromFile(HEART, NULL);
    new[0].spr = sfSprite_create();
    sfSprite_setTexture(new[0].spr, new[0].texture, sfFalse);
    new[1].name = "Attack\0";
    new[1].stat = 10;
    new[1].texture = sfTexture_createFromFile(SWORD, NULL);
    new[1].spr = sfSprite_create();
    sfSprite_setTexture(new[1].spr, new[1].texture, sfFalse);
    new[2].name = "Denfence\0";
    new[2].stat = 10;
    new[2].texture = sfTexture_createFromFile(SHIELD, NULL);
    new[2].spr = sfSprite_create();
    sfSprite_setTexture(new[2].spr, new[2].texture, sfFalse);
    return set_up_stat2(new);
}
