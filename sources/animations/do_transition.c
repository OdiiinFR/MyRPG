/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Does animations with clocks.
*/

#include "main.h"

void do_open_curtain(main_t *main)
{
    sfTime time;
    float seconds;
    sfVector2f center = sfView_getCenter(main->view);
    sfVector2f size = sfView_getSize(main->view);

    sfSprite_setPosition(main->transition->sp_curtain, (sfVector2f){(center.x - (size.x / 1.6)), (center.y - (size.y / 1.6))});
    sfClock_restart(main->transition->clock);
    sfSprite_setScale(main->transition->sp_curtain, (sfVector2f){10, 10});
    while (1) {
        time = sfClock_getElapsedTime(main->transition->clock);
        seconds = sfTime_asMicroseconds(time) / 1000000.0;
        sfRenderWindow_clear(main->wind.window, sfBlack);
        if (seconds < 0.2) {
            main->transition->rect.left = 0;
            sfSprite_setTextureRect(main->transition->sp_curtain, main->transition->rect);
            sfRenderWindow_drawSprite(main->wind.window, main->transition->sp_curtain, NULL);
            sfRenderWindow_display(main->wind.window);
        }
        if (seconds >= 0.2 && seconds < 0.4) {
            main->transition->rect.left = 115;
            sfSprite_setTextureRect(main->transition->sp_curtain, main->transition->rect);
            sfRenderWindow_drawSprite(main->wind.window, main->transition->sp_curtain, NULL);
            sfRenderWindow_display(main->wind.window);
        }
        if (seconds >= 0.4 && seconds < 0.6) {
            main->transition->rect.left = 230;
            sfSprite_setTextureRect(main->transition->sp_curtain, main->transition->rect);
            sfRenderWindow_drawSprite(main->wind.window, main->transition->sp_curtain, NULL);
            sfRenderWindow_display(main->wind.window);
        }
        if (seconds >= 0.6 && seconds < 0.8) {
            main->transition->rect.left = 345;
            sfSprite_setTextureRect(main->transition->sp_curtain, main->transition->rect);
            sfRenderWindow_drawSprite(main->wind.window, main->transition->sp_curtain, NULL);
            sfRenderWindow_display(main->wind.window);
        }
        if (seconds >= 0.8 && seconds < 1.0) {
            main->transition->rect.left = 460;
            sfSprite_setTextureRect(main->transition->sp_curtain, main->transition->rect);
            sfRenderWindow_drawSprite(main->wind.window, main->transition->sp_curtain, NULL);
            sfRenderWindow_display(main->wind.window);
        }
        if (seconds > 1.0) {
            main->transition->rect.left = 575;
            sfSprite_setTextureRect(main->transition->sp_curtain, main->transition->rect);
            sfRenderWindow_drawSprite(main->wind.window, main->transition->sp_curtain, NULL);
            sfRenderWindow_display(main->wind.window);
            return;
        }
    }
}

void do_close_curtain(main_t *main)
{
    sfTime time;
    float seconds;
    sfVector2f center = sfView_getCenter(main->view);
    sfVector2f size = sfView_getSize(main->view);

    sfSprite_setPosition(main->transition->sp_curtain, (sfVector2f){(center.x - (size.x / 1.6)), (center.y - (size.y / 1.6))});
    sfClock_restart(main->transition->clock);
    sfSprite_setScale(main->transition->sp_curtain, (sfVector2f){10, 10});
    while (1) {
        time = sfClock_getElapsedTime(main->transition->clock);
        seconds = sfTime_asMicroseconds(time) / 1000000.0;
        if (seconds < 0.1) {
            main->transition->rect.left = 575;
            sfSprite_setTextureRect(main->transition->sp_curtain, main->transition->rect);
            sfRenderWindow_drawSprite(main->wind.window, main->transition->sp_curtain, NULL);
            sfRenderWindow_display(main->wind.window);
        }
        if (seconds >= 0.1 && seconds < 0.2) {
            main->transition->rect.left = 460;
            sfSprite_setTextureRect(main->transition->sp_curtain, main->transition->rect);
            sfRenderWindow_drawSprite(main->wind.window, main->transition->sp_curtain, NULL);
            sfRenderWindow_display(main->wind.window);
        }
        if (seconds >= 0.2 && seconds < 0.3) {
            main->transition->rect.left = 345;
            sfSprite_setTextureRect(main->transition->sp_curtain, main->transition->rect);
            sfRenderWindow_drawSprite(main->wind.window, main->transition->sp_curtain, NULL);
            sfRenderWindow_display(main->wind.window);
        }
        if (seconds >= 0.3 && seconds < 0.4) {
            main->transition->rect.left = 230;
            sfSprite_setTextureRect(main->transition->sp_curtain, main->transition->rect);
            sfRenderWindow_drawSprite(main->wind.window, main->transition->sp_curtain, NULL);
            sfRenderWindow_display(main->wind.window);
        }
        if (seconds >= 0.4 && seconds < 0.5) {
            main->transition->rect.left = 115;
            sfSprite_setTextureRect(main->transition->sp_curtain, main->transition->rect);
            sfRenderWindow_drawSprite(main->wind.window, main->transition->sp_curtain, NULL);
            sfRenderWindow_display(main->wind.window);
        }
        if (seconds > 0.5) {
            main->transition->rect.left = 0;
            sfSprite_setTextureRect(main->transition->sp_curtain, main->transition->rect);
            sfRenderWindow_drawSprite(main->wind.window, main->transition->sp_curtain, NULL);
            sfRenderWindow_display(main->wind.window);
            return;
        }
    }
}

transition_t *create_transition(void)
{
    transition_t *new = malloc(sizeof(transition_t));

    new->rect.height = 140;
    new->rect.width = 115;
    new->rect.top = 0;
    new->sp_curtain = sfSprite_create();
    new->tx_curtain = sfTexture_createFromFile(CURTAIN, NULL);
    sfSprite_setTexture(new->sp_curtain, new->tx_curtain, sfFalse);
    new->clock = sfClock_create();
    return new;
}
