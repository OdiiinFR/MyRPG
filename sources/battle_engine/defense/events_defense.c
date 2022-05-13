/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Polls defense events.
*/

#include "defense_header.h"
#include <SFML/Window/Event.h>
#include <SFML/Graphics/RenderWindow.h>

static int change_texture_arrow_released(defense_t *defense)
{
    if (!sfKeyboard_isKeyPressed(sfKeyUp))
        sfSprite_setTexture(defense->arrows[0],
        defense->arrows_tx[0], sfFalse);
    if (!sfKeyboard_isKeyPressed(sfKeyRight))
        sfSprite_setTexture(defense->arrows[1],
        defense->arrows_tx[0], sfFalse);
    if (!sfKeyboard_isKeyPressed(sfKeyDown))
        sfSprite_setTexture(defense->arrows[2],
        defense->arrows_tx[0], sfFalse);
    if (!sfKeyboard_isKeyPressed(sfKeyLeft))
        sfSprite_setTexture(defense->arrows[3],
        defense->arrows_tx[0], sfFalse);
    return (0);
}

static void change_texture_arrow(defense_t *defense, int *key)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        sfSprite_setTexture(defense->arrows[0],
        defense->arrows_tx[1], sfFalse);
        (*key) = sfKeyUp;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        sfSprite_setTexture(defense->arrows[1],
        defense->arrows_tx[1], sfFalse);
        (*key) = sfKeyRight;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        sfSprite_setTexture(defense->arrows[2],
        defense->arrows_tx[1], sfFalse);
        (*key) = sfKeyDown;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        sfSprite_setTexture(defense->arrows[3],
        defense->arrows_tx[1], sfFalse);
        (*key) = sfKeyLeft;
    }
}

int check_events(sfRenderWindow *window, defense_t *defense)
{
    sfEvent event;
    int key = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed)
            change_texture_arrow(defense, &key);
        if (event.type == sfEvtKeyReleased)
            change_texture_arrow_released(defense);
    }
    return (key);
}
