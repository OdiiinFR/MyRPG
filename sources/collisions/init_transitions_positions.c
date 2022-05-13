/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Inititialises transitions and positions arrays.
*/

#include "player_structs.h"
#include "json_structs.h"
#include "json_parser.h"
#include "collisions_structs.h"
#include <stdlib.h>

static sfFloatRect *fetch_rectangle(void **value)
{
    sfFloatRect *rect;
    json_t *array = (json_t *)value;

    if (!(rect = malloc(sizeof(sfFloatRect))))
        return (NULL);
    rect->left = (long)array->value[1];
    rect->top = (long)array->value[2];
    rect->width = (long)array->value[3];
    rect->height = (long)array->value[4];
    return (rect);
}

static int *fetch_positions(void **value)
{
    int *pos;
    json_t *array = (json_t *)value;

    if (!(pos = malloc(sizeof(int) * 4)))
        return (NULL);
    pos[0] = (long)array->value[1];
    pos[1] = (long)array->value[2];
    pos[2] = (long)array->value[3];
    pos[3] = (long)array->value[4];
    return (pos);
}

static void free_parsed(void **parsed)
{
    int size;

    for (int i = 1; parsed[i]; ++i) {
        size = (long)((json_t **)((json_t **)parsed)[i]->value)[0];
        for (int j = 1; j < size; ++j)
            free(((json_t **)((json_t **)parsed)[i]->value)[j]);
        free(parsed[i]);
    }
    free(parsed);
}

int init_positions(void **parsed, col_t *col, int zone)
{
    json_t *trans = (json_t *)parsed[1];
    json_t *pos = (json_t *)parsed[2];
    int s_ts = (long)trans->value[0];
    int s_p = (long)pos->value[0];

    if (!(col->positions[zone] = malloc(sizeof(int *) * (s_p + 1))))
        return (84);
    if (!(col->transitions[zone] = malloc(sizeof(sfFloatRect *) * (s_ts + 1))))
        return (84);
    for (int i = 1; trans->value[i] != NULL; ++i)
        col->transitions[zone][i - 1] = fetch_rectangle(trans->value[i]);
    for (int i = 1; pos->value[i] != NULL; ++i)
        col->positions[zone][i - 1] = fetch_positions(pos->value[i]);
    col->transitions[zone][s_ts] = NULL;
    col->positions[zone][s_p] = NULL;
    free_parsed(parsed);
    return (0);
}
