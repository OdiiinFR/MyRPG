/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** create_btn
*/

#include "sounds.h"
#include "main.h"

void btn_action(button_t *btn, main_t *main)
{
    btn_update(btn, main);
    if (btn->function == 0)
        menu_to_menu(btn->menu_dir, btn, main);
    if (btn->function == 1) {
        if (btn_quit(btn, main) == 84) {
            sfRenderWindow_close(main->wind.window);
            return;
        }
    }
    if (btn->function == 2)
        check_frame(btn, main->params->frame2, main->params->frame3, main);
    if (btn->function == 3)
        check_frame(btn, main->params->frame1, main->params->frame3, main);
    if (btn->function == 4)
        check_frame(btn, main->params->frame1, main->params->frame2, main);
    find_funct(btn, main);
    sfRenderWindow_drawSprite(main->wind.window, btn->Sprite, NULL);
    if (btn->function < 25 || (btn->function > 32 && btn->function < 36) ||
        btn->function >= 50)
        sfRenderWindow_drawText(main->wind.window, btn->texte, NULL);
}

void menu_to_menu(int new, button_t *btn, main_t *main)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1) {
        if (w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx) {
            main->event = 0;
            main->wind.menu = new;
        }
    }
    return;
}

void btn_update(button_t *btn, main_t *main)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx) {
        if (main->event == 1)
            sfSprite_setTexture(btn->Sprite, btn->Texture_clicked, sfFalse);
        else
            sfSprite_setTexture(btn->Sprite, btn->Texture_on_mouse, sfFalse);
    } else {
        sfSprite_setTexture(btn->Sprite, btn->Texture_idle, sfFalse);
    }
    return;
}

sfText *btn_text(char *str, float x, float y, sfVector2f mod)
{
    sfText *game = sfText_create();
    sfFont *font = sfFont_createFromFile(FONT);
    sfVector2f pos = {(x + 5), y + 20};
    sfVector2f scale = {2 * mod.x, 2 * mod.x};

    sfText_setColor(game, sfWhite);
    sfText_setPosition(game, pos);
    sfText_setString(game, str);
    sfText_setFont(game, font);
    sfText_setScale(game, scale);
    return game;
}

button_t *new_button(char *text, sfVector3f pos, int dir, int type)
{
    button_t *new = malloc(sizeof(button_t));
    sfVector2f position = {pos.x, pos.y};
    sfVector2f scale = {pos.z, pos.z};

    new->position = position;
    new->scale = scale;
    new->Sprite = sfSprite_create();
    new->lenght = 570;
    new->height = 140;
    new->menu_dir = dir;
    new->in_fonction = 0;
    find_function(new, type, text);
    new->texte = btn_text(text, pos.x, pos.y, new->scale);
    sfSprite_setTexture(new->Sprite, new->Texture_idle, sfFalse);
    sfSprite_setPosition(new->Sprite, new->position);
    if (type > 35 && type < 50)
        sfSprite_setScale(new->Sprite, new->scale);
    return new;
}
