/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Applies mathematics to patterns.
*/

#include "defense_struct.h"
#include <math.h>
#include <stdlib.h>

float fetch_vector_norm(sfVector2f pos, sfVector2f center)
{
    int x = center.x - pos.x;
    int y = center.y - pos.y;

    return (sqrt(x * x + y * y) - 1);
}

float do_concentric_spiral(float time, pattern_t *pattern, sfVector2f center)
{
    sfVector2f pos = sfSprite_getPosition(pattern->arrow);
    float radius = fetch_vector_norm(pos, center);

    pos.x = center.x + radius * cos(pattern->speed * (time / 180) * M_PI);
    pos.y = center.y + radius * sin(pattern->speed * (time / 180) * M_PI);
    sfSprite_setPosition(pattern->arrow, pos);
    return (1);
}

float do_pendulum(float time, pattern_t *pattern, sfVector2f center)
{
    sfVector2f pos = sfSprite_getPosition(pattern->arrow);
    float angle;
    float radius = fetch_vector_norm(pos, center);

    if (pattern->nb == 0)
        angle = 45 * -sin(pattern->speed * (time / 180.0) * M_PI);
    if (pattern->nb == 1)
        angle = 45 * -sin(pattern->speed * (time / 180.0) * M_PI) + 90;
    if (pattern->nb == 2)
        angle = 45 * sin(pattern->speed * (time / 180.0) * M_PI) + 180;
    if (pattern->nb == 3)
        angle = 45 * sin(pattern->speed * (time / 180.0) * M_PI) - 90;
    pos.x = center.x + radius * cos((angle / 180) * M_PI - M_PI / 2);
    pos.y = center.y + radius * sin((angle / 180) * M_PI - M_PI / 2);
    sfSprite_setPosition(pattern->arrow, pos);
    return (1);
}

void do_straight_line(pattern_t *pattern)
{
    sfVector2f move = {0, 0};

    if (pattern->nb == 0)
        move.y = (move.y + 1) * 2 * pattern->speed;
    if (pattern->nb == 1)
        move.x = (move.x - 1) * 2 * pattern->speed;
    if (pattern->nb == 2)
        move.y = (move.y - 1) * 2 * pattern->speed;
    if (pattern->nb == 3)
        move.x = (move.x + 1) * 2 * pattern->speed;
    sfSprite_move(pattern->arrow, move);
}
