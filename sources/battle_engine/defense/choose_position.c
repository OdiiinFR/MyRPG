/*
** EPITECH PROJECT, 2022
** my_rph
** File description:
** Chooses the position of the objects.
*/

#include "defense_header.h"
#include <math.h>

static sfVector2f fetch_pos_center_arrow(pattern_t *pattern,
defense_t *defense)
{
    sfVector2f pos;

    if (pattern->nb == 0)
        pos = sfSprite_getPosition(defense->arrows[0]);
    if (pattern->nb == 1)
        pos = sfSprite_getPosition(defense->arrows[1]);
    if (pattern->nb == 2)
        pos = sfSprite_getPosition(defense->arrows[2]);
    if (pattern->nb == 3)
        pos = sfSprite_getPosition(defense->arrows[3]);
    return (pos);
}

static sfVector2f set_pos_line(defense_t *defense, \
pattern_t *pattern, sfVector2f pos)
{
    if (pattern->nb == 0)
        pos.y = defense->center.y - ((int)defense->size.y >> 1) - 300;
    if (pattern->nb == 1)
        pos.x = defense->center.x + ((int)defense->size.x >> 1) + 300;
    if (pattern->nb == 2)
        pos.y = defense->center.y + ((int)defense->size.y >> 1) + 300;
    if (pattern->nb == 3)
        pos.x = defense->center.x - ((int)defense->size.x >> 1) - 300;
    return (pos);
}

static sfVector2f set_pos_spiral(defense_t *defense, \
pattern_t *pattern, sfVector2f pos)
{
    if (pattern->nb == 0)
        pos.y = defense->center.y - ((int)defense->size.y >> 1) - 100;
    if (pattern->nb == 1)
        pos.x = defense->center.x + ((int)defense->size.x >> 1) + 100;
    if (pattern->nb == 2)
        pos.y = defense->center.y + ((int)defense->size.y >> 1) + 100;
    if (pattern->nb == 3)
        pos.x = defense->center.x - ((int)defense->size.x >> 1) - 100;
    return (pos);
}

static sfVector2f set_pos_pendulum(defense_t *defense, \
pattern_t *pattern, sfVector2f pos)
{
    if (pattern->nb == 0)
        pos.y = defense->center.y - ((int)defense->size.y >> 1) - 100;
    if (pattern->nb == 1)
        pos.x = defense->center.x + ((int)defense->size.x >> 1) + 100;
    if (pattern->nb == 2)
        pos.y = defense->center.y + ((int)defense->size.y >> 1) + 100;
    if (pattern->nb == 3)
        pos.x = defense->center.x - ((int)defense->size.x >> 1) - 100;
    return (pos);
}

void choose_pos(int move, pattern_t *pattern, defense_t *defense)
{
    sfVector2f pos;

    pos = fetch_pos_center_arrow(pattern, defense);
    if (move == 0)
        pos = set_pos_line(defense, pattern, pos);
    if (move == 1)
        pos = set_pos_spiral(defense, pattern, pos);
    if (move == 2)
        pos = set_pos_pendulum(defense, pattern, pos);
    sfSprite_setPosition(pattern->arrow, pos);
}
