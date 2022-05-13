/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Checks collisions between the player and the walls;
*/

#include "player_structs.h"
#include "collisions_header.h"
#include <stdlib.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Window/Event.h>

static sfBool check_lines(sfVertex **vertex, \
int type, player_t *player, int *key)
{
    if (!(type != 0) && (*key == player->up || *key == player->down) &&
    check_horizontal(vertex, type, player, key)) {
        free(vertex);
        return (sfTrue);
    }
    if (!(type != 1) && (*key == player->left || *key == player->right) &&
    check_vertical(vertex, type, player, key)) {
        free(vertex);
        return (sfTrue);
    }
    if (!(type != 2) && check_diagonal(vertex, type, player, key)) {
        free(vertex);
        return (sfTrue);
    }
    return (sfFalse);
}

static sfBool check_shape(sfVertexArray *array, int *type, \
player_t *player, int *key)
{
    int count = sfVertexArray_getVertexCount(array);
    sfVertex **vertex;

    if (!(vertex = malloc(sizeof(sfVertex *) * 2)))
        return (sfFalse);
    for (int j = 0; count - 1 > j; ++j) {
        vertex[0] = sfVertexArray_getVertex(array, j);
        vertex[1] = sfVertexArray_getVertex(array, j + 1);
        if (check_lines(vertex, type[j], player, key) == sfTrue)
            return (sfTrue);
    }
    vertex[0] = sfVertexArray_getVertex(array, count - 1);
    vertex[1] = sfVertexArray_getVertex(array, 0);
    if (check_lines(vertex, type[count - 1], player, key))
        return (sfTrue);
    free(vertex);
    return (sfFalse);
}

sfBool intersects_vertex(sfVertexArray **array, \
int **type, player_t *player, int *key)
{
    player->bounds = sfSprite_getGlobalBounds(player->sp_player);
    recalculate_vectors(player);
    for (int i = 0; array[i]; ++i) {
        if (check_shape(array[i], type[i], player, key) == sfTrue)
            return (sfTrue);
    }
    return (sfFalse);
}
