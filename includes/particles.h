/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** particles
*/

#ifndef PARTICLES_H_
    #define PARTICLES_H_

    #define DROP "images/drop.png"

typedef struct circle {
    int radius;
    sfVector2f pos;
    sfCircleShape *crc;
} circle_t;

typedef struct circles {
    sfCircleShape *spr_circle;
    struct circle **circle;
} circles_t;

typedef struct drop {
    int speed;
    sfVector2f pos;
    sfSprite *drp;
    sfTexture *drop;
} drop_t;

typedef struct rain {
    struct drop **drop;
} rain_t;

circles_t *create_fog(void);
rain_t *create_rain(void);

#endif /* !PARTICLES_H_ */
