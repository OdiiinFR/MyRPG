/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Generates pattern 1.
*/

#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "defense_header.h"
#include "enemy_struct.h"
#include "defense_struct.h"

static float choose_angle(int i)
{
    float angle;

    if (i == 0)
        angle = 0;
    if (i == 1)
        angle = 90;
    if (i == 2)
        angle = 180;
    if (i == 3)
        angle = 270;
    return (angle);
}

static void generate_arrow(pattern_t *pattern, \
defense_t *defense, int i, int move)
{
    float angle = choose_angle(i);

    pattern->next = NULL;
    pattern->arrow = sfSprite_create();
    sfSprite_setTexture(pattern->arrow, defense->arrows_tx[0], sfFalse);
    sfSprite_setScale(pattern->arrow, (sfVector2f){0.1, 0.1});
    sfSprite_setRotation(pattern->arrow, angle);
    sfSprite_setOrigin(pattern->arrow, (sfVector2f){256, 256});
    pattern->nb = i;
    pattern->move = move;
    pattern->killed = 0;
    choose_pos(pattern->move, pattern, defense);
}

void generate_pattern(pattern_t *pattern, defense_t *defense, \
enemy_t *enemy, int zone)
{
    pattern_t *tmp = pattern;

    sfClock_restart(defense->clock);
    for (int i = 0; enemy->type[zone][i] != -1; ++i) {
        tmp->next = malloc(sizeof(pattern_t));
        tmp->next->speed = enemy->speed[zone][i];
        generate_arrow(tmp->next, defense, \
        enemy->type[zone][i], enemy->move[zone][i]);
        tmp = tmp->next;
    }
}
