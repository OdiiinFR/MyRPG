/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** create_fog
*/

#include "main.h"

static circle_t **create_list(void)
{
    circle_t **new = malloc(sizeof(circle_t *) * 4001);

    for (int i = 0; i < 4000; i += 1) {
        new[i] = malloc(sizeof(circle_t));
        new[i]->crc = sfCircleShape_create();
    }
    new[4000] = malloc(sizeof(circle_t));
    new[4000] = NULL;
    return new;
}

static void draw_circle(circle_t *circle)
{
    int radius;
    sfVector2f pos;
    sfColor color;
    void *new = malloc(8);
    unsigned long a = (unsigned long)new;
    color.a = 50;
    color.r = 200;
    color.g = 200;
    color.b = 200;
    srand(a);
    pos.x = rand() % 12000 - 6000;
    pos.y = rand() % 12000 - 6000;
    radius = (rand() % 80) + 20;
    circle->pos = pos;
    circle->radius = radius;
    sfCircleShape_setRadius(circle->crc, radius);
    sfCircleShape_setFillColor(circle->crc, color);
    sfCircleShape_setOutlineColor(circle->crc, color);
    sfCircleShape_setOutlineThickness(circle->crc, 5);
    sfCircleShape_setPosition(circle->crc, pos);
}

circles_t *create_fog(void)
{
    int radius = 6000;
    circles_t *new = malloc(sizeof(circles_t));
    sfVector2f pos = {-6000, -6000};
    sfCircleShape *circle = sfCircleShape_create();
    sfColor color;

    new->circle = create_list();
    color.a = 100;
    color.r = 220;
    color.g = 220;
    color.b = 220;
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setOutlineColor(circle, color);
    sfCircleShape_setOutlineThickness(circle, 5);
    sfCircleShape_setPosition(circle, pos);
    new->spr_circle = circle;
    for (int i = 0; i < 4000; i++)
        draw_circle(new->circle[i]);
    return new;
}
