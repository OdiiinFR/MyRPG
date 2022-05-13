/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Checks collisions.
*/

#include <stdlib.h>
#include <SFML/Graphics/VertexArray.h>
#include <math.h>
#include <SFML/Window/Keyboard.h>
#include "player_structs.h"
#include "collisions_header.h"
#include "collisions_structs.h"

static sfVector2f init_check_diagonal(sfVertex **vertex, \
int type, void *x2, void *y2)
{
    sfVector2f vect;

    vect.x = vertex[1]->position.x - vertex[0]->position.x;
    vect.y = vertex[1]->position.y - vertex[0]->position.y;
    choose_xy(vertex, type, x2, y2);
    return (vect);
}

static int compute_cross_product(sfVertex *vertex1, \
sfVector2f vertex2, sfVector2f vect)
{
    sfVector2i new_vect;

    new_vect.x = vertex2.x - vertex1->position.x;
    new_vect.y = vertex2.y - vertex1->position.y;
    return (vect.x * new_vect.y - vect.y * new_vect.x);
}

int check_diagonal(sfVertex **vertex, \
int type, player_t *player, int *key)
{
    sfVector2f v;
    sfVector2f x2;
    sfVector2f y2;
    int cross_product;

    v = init_check_diagonal(vertex, type, &x2, &y2);
    for (int i = 0; i < 4; ++i) {
        cross_product = compute_cross_product(vertex[0], player->vertex[i], v);
        if (((cross_product <= 500) && (cross_product >= -500)) &&
        ((player->vertex[i].x >= x2.x) && (player->vertex[i].x <= x2.y)) &&
        ((player->vertex[i].y >= y2.x) && (player->vertex[i].y <= y2.y))) {
            move_back(player, type, key);
            return (1);
        }
    }
    return (0);
}

int check_vertical(sfVertex **vertex, \
int type, player_t *player, int *key)
{
    float top = player->bounds.top + ((int)player->bounds.height >> 1);
    float height = ((int)player->bounds.height >> 1);
    float width = player->bounds.width;
    float left = player->bounds.left;
    int x;
    sfVector2f y;

    choose_xy(vertex, type, (void *)&x, (void *)&y);
    if ((((x - left <= 5) && (x - left >= -5)) ||
    ((x - (left + width) <= 5) && (x - (left + width) >= -5))) &&
    ((((top >= y.x) && top <= y.y)) || (((top + height) >= y.x) &&
    ((top + height) <= y.y)))) {
        move_back(player, type, key);
        return (1);
    }
    return (0);
}

int check_horizontal(sfVertex **vertex, \
int type, player_t *player, int *key)
{
    float top = player->bounds.top + ((int)player->bounds.height >> 1);;
    float height = (int)player->bounds.height >> 2;
    float width = player->bounds.width;
    float left = player->bounds.left;
    sfVector2f x;
    int y;

    choose_xy(vertex, type, (void *)&x, (void *)&y);
    if ((((y - top <= 5) && (y - top >= -5)) ||
    ((y - (top + height) <= 5) && (y - (top + height) >= -5))) &&
    (((left >= x.x) && (left <= x.y)) ||
    (((left + width) >= x.x) && ((left + width) <= x.y)))) {
        move_back(player, type, key);
        return (1);
    }
    return (0);
}
