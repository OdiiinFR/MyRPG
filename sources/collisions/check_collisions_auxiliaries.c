/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Auxiliary routines needed to check collisions.
*/

#include "player_structs.h"
#include <SFML/Graphics/Vertex.h>

void recalculate_vectors(player_t *p)
{
    float top = p->bounds.top;
    float left = p->bounds.left;
    float height = (int)p->bounds.height >> 1;
    float width = p->bounds.width;

    p->vertex[0] = (sfVector2f){left, top};
    p->vertex[1] = (sfVector2f){left + width, top};
    p->vertex[2] = (sfVector2f){left, top + height};
    p->vertex[3] = (sfVector2f){left + width, top + height};
}

static void choose_values(void *vect, int var1, int var2, int is_vector)
{
    if (is_vector) {
        if (var1 < var2) {
            (*(sfVector2f *)vect).x = var1;
            (*(sfVector2f *)vect).y = var2;
        } else {
            (*(sfVector2f *)vect).x = var2;
            (*(sfVector2f *)vect).y = var1;
        }
        return;
    }
    if (var1 < var2)
        *(int *)vect = var1;
    else
        *(int *)vect = var2;
}

void choose_xy(sfVertex **vertex, int type, void *x, void *y)
{
    if (type == 2) {
        choose_values(x, vertex[0]->position.x, vertex[1]->position.x, 1);
        choose_values(y, vertex[0]->position.y, vertex[1]->position.y, 1);
        return;
    }
    if (type == 1) {
        choose_values(x, vertex[0]->position.x, vertex[1]->position.x, 0);
        choose_values(y, vertex[0]->position.y, vertex[1]->position.y, 1);
        return;
    }
    if (type == 0) {
        choose_values(x, vertex[0]->position.x, vertex[1]->position.x, 1);
        choose_values(y, vertex[0]->position.y, vertex[1]->position.y, 0);
        return;
    }
}
