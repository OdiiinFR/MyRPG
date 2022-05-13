/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** delete
*/

#include "main.h"

void do_bind3(button_t *new, int type)
{
    if (type == 39) {
        new->Texture_idle = sfTexture_createFromFile(FANTOM, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(FANTOM, NULL);
        new->Texture_clicked = sfTexture_createFromFile(FANTOM, NULL);
        new->function = type;
        new->height = 49;
        new->lenght = 50;
        new->in_fonction = 0;
    }
    if (type == 40) {
        new->Texture_idle = sfTexture_createFromFile(KEY, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(KEY, NULL);
        new->Texture_clicked = sfTexture_createFromFile(KEY, NULL);
        new->function = type;
        new->height = 65;
        new->lenght = 50;
        new->in_fonction = 0;
    }
    return do_bind4(new, type);
}

void do_bind2(button_t *new, int type)
{
    if (type == 37) {
        new->Texture_idle = sfTexture_createFromFile(NUAGE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(NUAGE, NULL);
        new->Texture_clicked = sfTexture_createFromFile(NUAGE, NULL);
        new->function = type;
        new->height = 21;
        new->lenght = 50;
        new->in_fonction = 0;
    }
    if (type == 38) {
        new->Texture_idle = sfTexture_createFromFile(ZARB, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(ZARB, NULL);
        new->Texture_clicked = sfTexture_createFromFile(ZARB, NULL);
        new->function = type;
        new->height = 49;
        new->lenght = 50;
        new->in_fonction = 0;
    }
    return do_bind3(new, type);
}

void do_bind(button_t *new, int type)
{
    if (type == 25 || type == 26 || type == 27 || type == 28 || type == 29 ||
        type == 30 || type == 31 || type == 32) {
        new->Texture_idle = sfTexture_createFromFile(BTN2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(BTN2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(BTN2_THR, NULL);
        new->function = type;
        new->height = 140;
        new->lenght = 310;
        new->in_fonction = 0;
    }
    if (type == 36) {
        new->Texture_idle = sfTexture_createFromFile(HOUSE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(HOUSE, NULL);
        new->Texture_clicked = sfTexture_createFromFile(HOUSE, NULL);
        new->function = type;
        new->height = 50;
        new->lenght = 50;
        new->in_fonction = 0;
    }
    return do_bind2(new, type);
}

void do_delete(button_t *new, int type)
{
    if (type == 21 || type == 33 || type == 34 || type == 35) {
        new->Texture_idle = sfTexture_createFromFile(BTN2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(BTN2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(BTN2_THR, NULL);
        new->function = type;
        new->height = 140;
        new->lenght = 310;
    }
    if (type == 22) {
        new->Texture_idle = sfTexture_createFromFile(BTN2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(BTN2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(BTN2_THR, NULL);
        new->function = 0;
        new->height = 140;
        new->lenght = 310;
    }
    return do_bind(new, type);
}
