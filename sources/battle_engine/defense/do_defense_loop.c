/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Do the attack loop for the defense part of the battle engine.
*/

#include "defense_header.h"
#include "defense_struct.h"
#include "battle_struct.h"
#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>

static pattern_t *free_attack(pattern_t *pattern)
{
    pattern_t *tmp = pattern;

    while (pattern != NULL) {
        pattern = pattern->next;
        free(tmp);
        tmp = pattern;
    }
    return (NULL);
}

static int display_defense(sfRenderWindow *window, defense_t *defense)
{
    pattern_t *tmp = defense->pattern->next;

    for (int i = 0; i < 4; ++i)
        sfRenderWindow_drawSprite(window, defense->arrows[i], NULL);
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->killed > 0)
            continue;
        sfRenderWindow_drawSprite(window, tmp->arrow, NULL);
    }
    return (0);
}

static float move_enemy_attack(float time, pattern_t *pattern, \
sfVector2f center)
{
    pattern_t *tmp = pattern;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->killed > 0)
            continue;
        if (tmp->move == 0)
            do_straight_line(tmp);
        if (tmp->move == 1)
            do_concentric_spiral(time, tmp, center);
        if (tmp->move == 2)
            do_pendulum(time, tmp, center);
    }
    return (1);
}

static float update_clock(defense_t *defense, \
pattern_t *pattern, float *time_f, sfVector2f center)
{
    float attack_update = 0;
    sfTime seconds = sfClock_getElapsedTime(defense->clock);

    attack_update = (float)sfTime_asMicroseconds(seconds) / 1000000.0;
    if (attack_update > 0.003) {
        *time_f += move_enemy_attack(*time_f, pattern->next, center);
        sfClock_restart(defense->clock);
    }
    seconds = sfClock_getElapsedTime(defense->clock_seconds);
    return ((float)sfTime_asMicroseconds(seconds) / 1000000.0);
}

int do_defense_loop(sfRenderWindow *window, \
defense_t *defense, main_t *main)
{
    float seconds = 0;
    float time = 0;
    int key = 0;
    int nb = 1;
    pattern_t *tmp;

    generate_pattern(defense->pattern, defense, \
    main->battle->enemies[main->player->zone], main->player->zone);
    sfClock_restart(defense->clock);
    sfClock_restart(defense->clock_seconds);
    tmp = defense->pattern;
    while (seconds < 10) {
        sfRenderWindow_clear(window, sfBlack);
        key = check_events(window, defense);
        seconds = update_clock(defense, defense->pattern, &time, defense->center);
        display_defense(window, defense);
        check_collisions_defense(defense, key, main);
        sfRenderWindow_display(window);
    }
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->killed == 1)
            ++nb;
    }
    defense->pattern->next = free_attack(defense->pattern->next);
    return (nb);
}
