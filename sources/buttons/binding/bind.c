/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** bind
*/

#include "main.h"

int is_real_key(main_t *main)
{
    if (main->last == sfKeySpace || main->last == sfKeyEscape ||
        main->last == sfKeyUp || main->last == sfKeyDown ||
        main->last == sfKeyLeft || main->last == sfKeyRight)
        return 0;
    if (main->last > -1 && main->last < 26)
        return 0;
    if (main->last >= 81 && main->last <= 99)
        return 0;
    return 1;
}

void set_back(main_t *main)
{
    main->params->key_menu->config_up->in_fonction = 0;
    main->params->key_menu->config_right->in_fonction = 0;
    main->params->key_menu->config_down->in_fonction = 0;
    main->params->key_menu->config_left->in_fonction = 0;
    main->params->key_menu->config5->in_fonction = 0;
    main->params->key_menu->config6->in_fonction = 0;
    main->params->key_menu->config7->in_fonction = 0;
    main->params->key_menu->config8->in_fonction = 0;
}

int do_binding2(button_t *btn, main_t *main, my_key_t *key)
{
    main->event = 0;
    if (main->last == key->key) {
        btn->in_fonction = 0;
        return 1;
    }
    for (int i = 0; i < 8; i += 1) {
        if (main->config->keys[i]->key == main->last) {
            btn->in_fonction = 0;
            return 1;
        }
    }
    key->key = main->last;
    key_to_txt(key);
    btn->in_fonction = 0;
    return 0;
}

void set_to_bind(button_t *btn, main_t *main, int flag)
{
    if (flag == 0) {
        set_back(main);
        btn->in_fonction = 1;
        sfSprite_setTexture(btn->Sprite, btn->Texture_clicked, sfFalse);
        main->event = 0;
    } else if (flag == 1) {
        btn->in_fonction = 0;
        main->event = 0;
    }
    return;
}

void do_binding(button_t *btn, main_t *main, my_key_t *key)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn &&
        w.y < ymx && btn->in_fonction == 0)
        set_to_bind(btn, main, 0);
    else if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn &&
        w.y < ymx && btn->in_fonction == 1)
        set_to_bind(btn, main, 1);
    if (main->event == 2 && is_real_key(main) == 0 && btn->in_fonction == 1 &&
        w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx)
        if (do_binding2(btn, main, key) == 1)
            return;
    if (btn->in_fonction == 1)
        sfSprite_setTexture(btn->Sprite, btn->Texture_clicked, sfFalse);
    return;
}
