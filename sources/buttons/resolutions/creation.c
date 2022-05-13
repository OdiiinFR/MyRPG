/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** creation
*/

#include "main.h"
#include "sounds.h"

void find_funct(button_t *btn, main_t *main)
{
    do_reso(btn, main);
    do_slider(btn, main);
    if (btn->function == 17 || btn->function == 18)
        do_lang(btn, main);
    if (btn->function == 20) {
        check_saves(btn, main);
        check_new(btn, main, -1);
    }
    if (btn->function == 23)
        do_cancel(btn, main);
    if (btn->function == 24)
        do_create(btn, main);
    if (btn->function == 21)
        check_new(btn, main, -2);
    for (int nb = 25, i = 0; i < 8; i += 1)
        if ((nb + i) == btn->function)
            do_binding(btn, main, main->config->keys[i]);
    if (btn->function == 33)
        set_keyboard(main, btn);
    if (btn->function == 34)
        set_controller(main, btn);
    if (btn->function == 35)
        set_dancepad(main, btn);
    return find_funct2(btn, main);
}

void create_frame2(button_t *new, int type)
{
    if (type == 4) {
        new->Texture_idle = sfTexture_createFromFile(RND2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(RND2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(RND2_THR, NULL);
        new->function = 4;
        new->in_fonction = 0;
        new->height = 130;
        new->lenght = 130;
    }
    if (type == 5) {
        new->Texture_idle = sfTexture_createFromFile(RND2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(RND2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(RND2_THR, NULL);
        new->function = 5;
        new->height = 130;
        new->lenght = 130;
    }
    return create_frameplus(new, type);
}

void create_frame(button_t *new, int type)
{
    if (type == 2) {
        new->Texture_idle = sfTexture_createFromFile(RND2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(RND2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(RND2_THR, NULL);
        new->function = 2;
        new->in_fonction = 0;
        new->height = 130;
        new->lenght = 130;
    }
    if (type == 3) {
        new->Texture_idle = sfTexture_createFromFile(RND2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(RND2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(RND2_THR, NULL);
        new->function = 3;
        new->in_fonction = 1;
        new->height = 130;
        new->lenght = 130;
    }
    return create_frame2(new, type);
}

void do_slider(button_t *btn, main_t *main)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (btn->function == 5 || btn->function == 6) {
        if (main->event == 1 && w.x > 160 && w.x < 1615 && w.y > ymn
            && w.y < ymx) {
            btn->position.x = w.x - 55;
            main->sounds->vol_music = (((w.x - 160) * 100) / 1560);
            sfSprite_setPosition(btn->Sprite, btn->position);
            apply_volume(main);
        }
        if (main->event == 1 && w.y < 540 && w.y > 500)
            main->event = 0;
    }
    return;
}

void create_reso(button_t *new, int type, char *name)
{
    if (type == 7 || type == 8 || type == 9 || type == 10 ||
    type == 11 || type == 12 || type == 13 || type == 14 ||
    type == 15 || type == 16) {
        new->Texture_idle = sfTexture_createFromFile(BTN2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(BTN2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(BTN2_THR, NULL);
        new->function = type;
        new->in_fonction = 0;
        new->height = 140;
        new->lenght = 310;
    }
    if (type == 17 || type == 18) {
        new->Texture_idle = sfTexture_createFromFile(BTN2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(BTN2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(BTN2_THR, NULL);
        new->function = type;
        new->height = 140;
        new->lenght = 310;
    }
    return create_reso2(new, type, name);
}
