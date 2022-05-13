/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** btn_action
*/

#include "main.h"

void check_frame3(button_t *btn, button_t *btn2, button_t *btn3, main_t *main)
{
    sfVector2f new = btn->position;
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn
        && w.y < ymx) {
        sfRenderWindow_setFramerateLimit(main->wind.window, 30);
        btn->in_fonction = 1;
        update_frame(btn2, btn3, main);
    }
    if (btn->in_fonction == 1) {
        new.y += 30;
        new.x += 5;
        sfText_setPosition(btn->texte, new);
        sfSprite_setTexture(btn->Sprite, btn->Texture_clicked, sfFalse);
    }
}

void check_frame2(button_t *btn, button_t *btn2, button_t *btn3, main_t *main)
{
    sfVector2f new = btn->position;
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn
        && w.y < ymx) {
        sfRenderWindow_setFramerateLimit(main->wind.window, 60);
        btn->in_fonction = 1;
        update_frame(btn2, btn3, main);
    }
    if (btn->in_fonction == 1) {
        new.y += 30;
        new.x += 5;
        sfText_setPosition(btn->texte, new);
        sfSprite_setTexture(btn->Sprite, btn->Texture_clicked, sfFalse);
    }
}

void check_frame(button_t *btn, button_t *btn2, button_t *btn3, main_t *main)
{
    sfVector2f new = btn->position;
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn
        && w.y < ymx) {
        sfRenderWindow_setFramerateLimit(main->wind.window, 144);
        btn->in_fonction = 1;
        update_frame(btn2, btn3, main);
    }
    if (btn->in_fonction == 1) {
        new.y += 30;
        new.x += 5;
        sfText_setPosition(btn->texte, new);
        sfSprite_setTexture(btn->Sprite, btn->Texture_clicked, sfFalse);
    }
}

void find_function(button_t *new, int type, char *text)
{
    if (type == 0) {
        new->Texture_idle = sfTexture_createFromFile(BTN_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(BTN_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(BTN_THR, NULL);
        new->function = 0;
    }
    if (type == 1) {
        new->Texture_idle = sfTexture_createFromFile(BTN_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(BTN_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(BTN_THR, NULL);
        new->function = 1;
    }
    create_frame(new, type);
    create_reso(new, type, text);
    do_delete(new, type);
    return;
}

int btn_quit(button_t *btn, main_t *main)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1) {
        if (w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx)
            return 84;
    }
    return 0;
}
