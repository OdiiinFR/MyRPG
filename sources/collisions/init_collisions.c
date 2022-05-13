/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Initializes the collisions in the chosen tiles.
*/

#include "json_structs.h"
#include "json_parser.h"
#include "collisions_structs.h"
#include "collisions_header.h"
#include <stdlib.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>

static void init_texture(col_t *col)
{
    col->tx_col[0] = LOADTEX("./res/spr/maps/debug.png", NULL);
    col->tx_col[1] = LOADTEX("./res/spr/maps/begin.png", NULL);
    col->tx_col[2] = LOADTEX("./res/spr/maps/train_int.png", NULL);
    col->tx_col[3] = LOADTEX("./res/spr/maps/outside.png", NULL);
    col->tx_col[4] = LOADTEX("./res/spr/maps/town.png", NULL);
    col->tx_col[5] = LOADTEX("./res/spr/maps/mountain.png", NULL);
    col->tx_col[6] = LOADTEX("./res/spr/maps/tunnel.png", NULL);
    col->tx_col[7] = LOADTEX("./res/spr/maps/house1.png", NULL);
    col->tx_col[8] = LOADTEX("./res/spr/maps/house2.png", NULL);
    col->tx_col[9] = LOADTEX("./res/spr/maps/funeral_gate.png", NULL);
    col->tx_col[10] = LOADTEX("./res/spr/maps/crematorium.png", NULL);
    col->tx_col[11] = LOADTEX("./res/spr/maps/funeral_ash.png", NULL);
}

static void load_texture_in_memory(col_t *col)
{
    int i;

    if (!(col->tx_col = malloc(sizeof(sfTexture *) * (12 + 1))))
        return;
    init_texture(col);
    if (!(col->sp_col = malloc(sizeof(sfSprite *) * (12 + 1))))
        return;
    for (i = 0; i < 12; ++i) {
        col->sp_col[i] = sfSprite_create();
        sfSprite_setTexture(col->sp_col[i], col->tx_col[i], sfFalse);
    }
    col->tx_col[i] = NULL;
    col->sp_col[i] = NULL;
}

col_t *init_col(void)
{
    col_t *col = malloc(sizeof(col_t));

    load_texture_in_memory(col);
    if (!(col->array = malloc(sizeof(sfVertexArray **) * (12 + 1))))
        return (NULL);
    if (!(col->type = malloc(sizeof(int **) * (12 + 1))))
        return (NULL);
    for (int i = 0; i < 12 + 1; ++i) {
        col->array[i] = NULL;
        col->type[i] = NULL;
    }
    init_zone(col);
    init_transitions(col);
    init_interactions(col);
    return (col);
}
