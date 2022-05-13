/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** lang
*/

#include "main.h"

void text_up_pos(button_t *btn, int flag)
{
    sfVector2f pos = btn->position;

    if (flag == 0) {
        pos.y += 30;
        pos.x += 5;
        sfText_setPosition(btn->texte, pos);
    } else {
        pos.y += 20;
        pos.x += 5;
        sfText_setPosition(btn->texte, pos);
    }
}

static void do_lang2(button_t *btn, main_t *main)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (btn->function == 18) {
        if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn
                && w.y < ymx) {
            main->lang = 1;
            main->event = 0;
            change_french(main);
        }
        if (main->lang == 1) {
            text_up_pos(btn, 0);
            sfSprite_setTexture(btn->Sprite, btn->Texture_clicked, sfFalse);
        } else
            text_up_pos(btn, 1);
    }
}

void do_lang(button_t *btn, main_t *main)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));
    if (btn->function == 17) {
        if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn
                && w.y < ymx) {
            main->lang = 0;
            main->event = 0;
            change_english(main);
        }
        if (main->lang == 0) {
            text_up_pos(btn, 0);
            sfSprite_setTexture(btn->Sprite, btn->Texture_clicked, sfFalse);
        } else
            text_up_pos(btn, 1);
    }
    return do_lang2(btn, main);
}
