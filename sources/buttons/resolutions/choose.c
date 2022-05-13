/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** choose
*/

#include "main.h"

void create_reso2(button_t *new, int type, char *name)
{
    if (type == 19) {
        new->Texture_idle = sfTexture_createFromFile(RND_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(RND_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(RND_THR, NULL);
        new->function = 0;
        new->scale.x = 0.8;
        new->height = 130;
        new->lenght = 130;
    }
    if (type == 20) {
        new->Texture_idle = sfTexture_createFromFile(BTN2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(BTN2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(BTN2_THR, NULL);
        new->function = type;
        new->in_fonction = find_save(name);
        new->height = 140;
        new->lenght = 310;
    }
    return find_delete(new, type);
}

void do_reso(button_t *btn, main_t *main)
{
    if (btn->function == 7)
        find_reso(btn, main);
    if (btn->function == 8)
        find_reso(btn, main);
    if (btn->function == 9)
        find_reso(btn, main);
    if (btn->function == 10)
        find_reso(btn, main);
    if (btn->function == 11)
        find_reso(btn, main);
    if (btn->function == 12)
        find_reso(btn, main);
    if (btn->function == 13)
        find_reso(btn, main);
    if (btn->function == 14)
        find_reso(btn, main);
    if (btn->function == 15)
        find_reso(btn, main);
    if (btn->function == 16)
        find_reso(btn, main);
}

void apply_reso(button_t *btn, main_t *main, unsigned int c, unsigned int b)
{
    sfVector2u res = {c, b};
    sfVector2u test = sfRenderWindow_getSize(main->wind.window);
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx) {
        sfRenderWindow_setSize(main->wind.window, res);
        main->event = 0;
    }
    if (test.x == res.x && test.y == res.y) {
        sfSprite_setTexture(btn->Sprite, btn->Texture_clicked, sfFalse);
        text_up_pos(btn, 0);
    } else
        text_up_pos(btn, 1);
}

void find_reso2(button_t *btn, main_t *main)
{
    switch (btn->function) {
        case 15:
            return apply_reso(btn, main, 2048, 1536);
        case 16:
            return apply_reso(btn, main, 4096, 2160);
        default:
            return;
    }
}

void find_reso(button_t *btn, main_t *main)
{
    switch (btn->function) {
        case 7:
            return apply_reso(btn, main, 1280, 720);
        case 8:
            return apply_reso(btn, main, 1920, 1080);
        case 9:
            return apply_reso(btn, main, 2560, 1440);
        case 10:
            return apply_reso(btn, main, 1280, 800);
        case 11:
            return apply_reso(btn, main, 1920, 1200);
        case 12:
            return apply_reso(btn, main, 2560, 1600);
        case 13:
            return apply_reso(btn, main, 1024, 768);
        case 14:
            return apply_reso(btn, main, 1400, 1050);
        default:
            return find_reso2(btn, main);
    }
}
