/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Contains the defense structure of the RPG.
*/

#ifndef DEFENSE_STRUCT_H_
    #define DEFENSE_STRUCT_H_

    #include <SFML/Graphics/Sprite.h>
    #include <SFML/System/Clock.h>

typedef struct pattern {
    struct pattern *next;
    struct pattern *bef;
    sfSprite *arrow;
    char speed;
    char nb;
    char move;
    char killed;
} pattern_t;

typedef struct defense {
    sfTexture **arrows_tx;
    sfSprite **arrows;
    struct pattern *pattern;
    sfClock *clock;
    sfClock *clock_seconds;
    sfVector2f center;
    sfVector2f size;
} defense_t;

#endif /* !DEFENSE_STRUCT_H_ */
