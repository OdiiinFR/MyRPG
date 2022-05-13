/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** hud
*/

#include "main.h"

static hud_menu_t *set_hud5(hud_menu_t *new)
{
    new->pos_hud_stat[3] = (sfVector2f){640, 130};
    new->health = btn_text(my_itoa(100), 500, 30, (sfVector2f){0.5, 0.5});
    new->attack = btn_text(my_itoa(10), 0, 0, (sfVector2f){0.5, 0.5});
    new->defence = btn_text(my_itoa(10), 0, 0, (sfVector2f){0.5, 0.5});
    new->pos_hud[0] = (sfVector2f){175, 0};
    sfSprite_setTexture(new->hud[0], new->txt_hud[0], sfFalse);
    sfSprite_setPosition(new->hud[0], new->pos_hud[0]);
    return new;
}

static hud_menu_t *set_hud4(hud_menu_t *new)
{
    new->pos_hud_skt[0] = (sfVector2f){425, 30};
    new->pos_hud_skt[1] = (sfVector2f){425, 80};
    new->pos_hud_skt[2] = (sfVector2f){425, 130};
    new->pos_hud_skt[3] = (sfVector2f){200, 30};
    new->pos_hud_skt[4] = (sfVector2f){200, 130};
    new->pos_hud_skt[5] = (sfVector2f){275, 30};
    new->pos_hud_skt[6] = (sfVector2f){275, 130};
    new->pos_hud_skt[7] = (sfVector2f){350, 30};
    new->pos_hud_skt[8] = (sfVector2f){350, 130};
    for (int i = 0; i < 9; i += 1) {
        sfSprite_setPosition(new->hud_skt[i], new->pos_hud_skt[i]);
        sfSprite_setTexture(new->hud_skt[i], new->txt_hud_skt[9], sfFalse);
    }
    for (int i = 0; i < 4; i += 1) {
        sfSprite_setPosition(new->hud_stat[i], new->pos_hud_stat[i]);
        sfSprite_setTexture(new->hud_stat[i], new->txt_hud_stat[i], sfFalse);
    }
    return set_hud5(new);
}

static hud_menu_t *set_hud3(hud_menu_t *new)
{
    new->txt_hud_stat[7] = sfTexture_createFromFile(MAG, NULL);
    new->txt_hud_skt[0] = sfTexture_createFromFile(SP1, NULL);
    new->txt_hud_skt[1] = sfTexture_createFromFile(SP2, NULL);
    new->txt_hud_skt[2] = sfTexture_createFromFile(SP3, NULL);
    new->txt_hud_skt[3] = sfTexture_createFromFile(CR2, NULL);
    new->txt_hud_skt[4] = sfTexture_createFromFile(TCK, NULL);
    new->txt_hud_skt[5] = sfTexture_createFromFile(CBL, NULL);
    new->txt_hud_skt[6] = sfTexture_createFromFile(ATK, NULL);
    new->txt_hud_skt[7] = sfTexture_createFromFile(DEF, NULL);
    new->txt_hud_skt[8] = sfTexture_createFromFile(ITER, NULL);
    new->txt_hud_skt[9] = sfTexture_createFromFile(CROIX, NULL);
    for (int i = 1; i < 3; i += 1) {
        new->pos_hud[i] = (sfVector2f){0, 0};
        sfSprite_setTexture(new->hud[i], new->txt_hud[i], sfFalse);
        sfSprite_setPosition(new->hud[i], new->pos_hud[i]);
    }
    new->pos_hud_stat[0] = (sfVector2f){500, 20};
    new->pos_hud_stat[1] = (sfVector2f){640, 40};
    new->pos_hud_stat[2] = (sfVector2f){520, 130};
    return set_hud4(new);
}

static hud_menu_t *set_hud2(hud_menu_t *new)
{
    sfVector2f scale = {0.5, 0.5};
    sfVector2f *tmp1 = malloc(sizeof(sfVector2f) * 9);
    sfVector2f *tmp2 = malloc(sizeof(sfVector2f) * 4);
    sfVector2f *tmp3 = malloc(sizeof(sfVector2f) * 3);
    new->skill = btn_text("Skills obtained\0", 100, 100, scale);
    new->stats = btn_text("My Stats\0", 100, 100, scale);
    new->pos_hud = tmp3;
    new->pos_hud_skt = tmp1;
    new->pos_hud_stat = tmp2;
    new->txt_hud[0] = sfTexture_createFromFile(HUD1, NULL);
    new->txt_hud[1] = sfTexture_createFromFile(HUD2, NULL);
    new->txt_hud[2] = sfTexture_createFromFile(HUD3, NULL);
    new->txt_hud_stat[0] = sfTexture_createFromFile(HEART, NULL);
    new->txt_hud_stat[1] = sfTexture_createFromFile(SWORD, NULL);
    new->txt_hud_stat[2] = sfTexture_createFromFile(SHIELD, NULL);
    new->txt_hud_stat[3] = sfTexture_createFromFile(NEU, NULL);
    new->txt_hud_stat[4] = sfTexture_createFromFile(POI, NULL);
    new->txt_hud_stat[5] = sfTexture_createFromFile(BUR, NULL);
    new->txt_hud_stat[6] = sfTexture_createFromFile(GEL, NULL);
    return set_hud3(new);
}

hud_menu_t *set_hud(void)
{
    hud_menu_t *new = malloc(sizeof(*new));
    sfSprite **tmp1 = malloc(sizeof(sfSprite *) * 9);
    sfSprite **tmp2 = malloc(sizeof(sfSprite *) * 4);
    sfSprite **tmp3 = malloc(sizeof(sfSprite *) * 3);
    sfTexture **tmp11 = malloc(sizeof(sfTexture *) * 10);
    sfTexture **tmp12 = malloc(sizeof(sfTexture *) * 8);
    sfTexture **tmp13 = malloc(sizeof(sfTexture *) * 3);
    for (int i = 0; i < 9; i += 1)
        tmp1[i] = sfSprite_create();
    for (int i = 0; i < 4; i += 1)
        tmp2[i] = sfSprite_create();
    for (int i = 0; i < 3; i += 1)
        tmp3[i] = sfSprite_create();
    new->hud = tmp3;
    new->hud_skt = tmp1;
    new->hud_stat = tmp2;
    new->txt_hud = tmp13;
    new->txt_hud_skt = tmp11;
    new->txt_hud_stat = tmp12;
    return set_hud2(new);
}
