/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Checks collisions between goal arrows and moving arrows.
*/

#include "defense_header.h"
#include "main.h"
#include <SFML/Window/Keyboard.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static void decide_if_pressed(pattern_t *pattern, int i, int key)
{
    if (i == 0 && key == sfKeyUp)
        pattern->killed = 2;
    if (i == 1 && key == sfKeyLeft)
        pattern->killed = 2;
    if (i == 2 && key == sfKeyDown)
        pattern->killed = 2;
    if (i == 3 && key == sfKeyRight)
        pattern->killed = 2;
}

static void check_collision_center(pattern_t *pattern, defense_t *defense, \
int key_code, main_t *main)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(pattern->arrow);
    sfVector2f pos;
    sfVector2f center = sfView_getCenter(main->view);

    for (int i = 0; i < 4; ++i) {
        pos = sfSprite_getPosition(defense->arrows[i]);
        if (pattern->nb == i && sfFloatRect_contains(&rect, pos.x, pos.y))
            decide_if_pressed(pattern, i, key_code);
    }
    if (sfFloatRect_contains(&rect, center.x, center.y)) {
        pattern->killed = 1;
    }
}

void check_collisions_defense(defense_t *defense, int key_code, main_t *main)
{
    pattern_t *tmp = defense->pattern->next;

    for (; tmp != NULL; tmp = tmp->next)
        check_collision_center(tmp, defense, key_code, main);
}
