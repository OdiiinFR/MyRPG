/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Does the attack sequence.
*/

#include "attack_struct.h"
#include "attack_header.h"
#include "main.h"
#include <SFML/System/Clock.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Window/Keyboard.h>

static void hold_on_display(sfRenderWindow *window, sfClock *clock)
{
    sfTime time;
    float time_f = 0;

    sfClock_restart(clock);
    while (time_f < 0.005 && (sfRenderWindow_isOpen(window))) {
        time = sfClock_getElapsedTime(clock);
        time_f = (float)sfTime_asMicroseconds(time) / 1000000.0;
    }
}

static int poll_attack_events(main_t *main, \
sfFloatRect *cursor, attack_t *attack, int nb)
{
    sfFloatRect rect;
    sfSprite **arrow = attack->arrow;
    int *type = attack->type;

    for (int i = 0; i < 10; ++i) {
        rect = sfSprite_getGlobalBounds(arrow[i]);
        if ((sfKeyboard_isKeyPressed(main->player->left) && (type[i] == 0) &&
        sfFloatRect_intersects(cursor, &rect, NULL)) ||
        (sfKeyboard_isKeyPressed(main->player->down) && (type[i] == 1) &&
        sfFloatRect_intersects(cursor, &rect, NULL)) ||
        (sfKeyboard_isKeyPressed(main->player->up) && (type[i] == 2) &&
        sfFloatRect_intersects(cursor, &rect, NULL)) ||
        (sfKeyboard_isKeyPressed(main->player->right) && (type[i] == 3) &&
        sfFloatRect_intersects(cursor, &rect, NULL))) {
            ++nb;
            type[i] = -1;
        }
    }
    return (nb);
}

static void draw_assets_attack(main_t *main, attack_t *attack)
{
    sfRenderWindow *window = main->wind.window;

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawRectangleShape(window, attack->box, NULL);
    for (int i = 0; attack->arrow[i] != NULL; ++i) {
        if (attack->type[i] != -1) {
            sfRenderWindow_drawRectangleShape(window, attack->lines[i], NULL);
            sfRenderWindow_drawSprite(window, attack->arrow[i], NULL);
        }
    }
    sfRenderWindow_drawRectangleShape(window, attack->cursor, NULL);
    sfRenderWindow_display(window);
}

int do_attack(attack_t *attack, sfClock *clock, main_t *main)
{
    sfFloatRect box = sfRectangleShape_getGlobalBounds(attack->box);
    sfFloatRect cursor = sfRectangleShape_getGlobalBounds(attack->cursor);
    int nb = 0;

    chooses_arrows(attack);
    for (; sfRenderWindow_isOpen(main->wind.window) &&
    sfFloatRect_intersects(&box, &cursor, NULL);) {
        hold_on_display(main->wind.window, clock);
        nb = poll_attack_events(main, &cursor, attack, nb);
        draw_assets_attack(main, attack);
        sfRectangleShape_move(attack->cursor, (sfVector2f){10, 0});
        cursor = sfRectangleShape_getGlobalBounds(attack->cursor);
        box = sfRectangleShape_getGlobalBounds(attack->box);
        sfClock_restart(main->player->clock);
    }
    for (int i = 0; i < 10; ++i)
        sfSprite_destroy(attack->arrow[i]);
    sfRectangleShape_setPosition(attack->cursor, (sfVector2f){0, cursor.top});
    return (nb);
}
