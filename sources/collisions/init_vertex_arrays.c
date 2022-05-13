/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Initializes the vertex arrays.
*/

#include "player_structs.h"
#include "json_structs.h"
#include "collisions_structs.h"
#include <stdlib.h>

static int fetch_type(sfVector2f position, void *next, void *first)
{
    sfVector2f position2;

    if (next != NULL) {
        position2.x = (long)((json_t *)next)->value[2];
        position2.y = (long)((json_t *)next)->value[1];
    } else {
        position2.x = (long)((json_t *)first)->value[2];
        position2.y = (long)((json_t *)first)->value[1];
    }
    if ((position.y - position2.y == 0) || (position2.y - position.y == 0))
        return (0);
    if ((position.x - position2.x == 0) || (position2.x - position.x == 0))
        return (1);
    return (2);
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

static int init_bounds(json_t *parsed, \
sfVertexArray **shapes, int ***type, int i)
{
    int size_array = (long)parsed->value[0];
    sfVector2f position;
    sfVertex vertex;
    void *next;
    void *first;

    if (!((*type)[i - 1] = malloc(sizeof(int) * (size_array + 1))))
        return (0);
    for (int j = 1; j <= size_array; ++j) {
        position.x = (long)((json_t **)parsed->value)[j]->value[2];
        position.y = (long)((json_t **)parsed->value)[j]->value[1];
        vertex.color = sfRed;
        vertex.position = position;
        vertex.texCoords = position;
        sfVertexArray_append(*shapes, vertex);
        next = ((json_t **)parsed->value)[j + 1];
        first = ((json_t **)parsed->value)[1];
        (*type)[i - 1][j - 1] = fetch_type(position, next, first);
    }
    return (size_array);
}

sfVertexArray **init_vertex_array(void **parsed, col_t *col, int zone)
{
    sfVertexArray **s;
    json_t **array = ((json_t **)parsed);
    int size = (long)parsed[0];
    int size_array;

    if (!(s = malloc(sizeof(sfVertexArray *) * (size + 1))))
        return (NULL);
    if (!(col->type[zone] = malloc(sizeof(int *) * (size + 1))))
        return (NULL);
    for (int j = 0; j < size; ++j)
        s[j] = sfVertexArray_create();
    for (int i = 1; array[i] != NULL; ++i) {
        size_array = init_bounds(array[i], &s[i - 1], &col->type[zone], i);
        sfVertexArray_setPrimitiveType(s[i - 1], sfLineStrip);
        col->type[zone][i - 1][size_array] = -1;
    }
    col->type[zone][size] = NULL;
    s[size] = NULL;
    free_parsed(parsed);
    return (s);
}
