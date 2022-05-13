/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Initializes the player.
*/

#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include "player_structs.h"
#include "collisions_structs.h"
#include "main.h"

void init_keys(player_t **player, main_t *main)
{
    (*player)->up = (*main).config->keys[0]->key;
    (*player)->right = (*main).config->keys[1]->key;
    (*player)->down = (*main).config->keys[2]->key;
    (*player)->left = (*main).config->keys[3]->key;
}

static void init_texture_sprite(col_t *col, player_t *p)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(col->sp_col[0]);
    sfVector2f pos = {(rect.width / 2) + 335, 300};
    sfVector2f scale = {1.1, 1.1};
    sfIntRect tx = {32, 0, 20, 31};

    p->tx_player = sfTexture_createFromFile("./res/spr/char/mari.png", NULL);
    p->sp_player = sfSprite_create();
    sfSprite_setTexture(p->sp_player, p->tx_player, sfFalse);
    sfSprite_setTextureRect(p->sp_player, tx);
    sfSprite_setPosition(p->sp_player, pos);
    sfSprite_setScale(p->sp_player, scale);
    p->bounds = sfSprite_getLocalBounds(p->sp_player);
    p->rect = tx;
}

player_t *init_player(col_t *col, main_t *main)
{
    player_t *p = malloc(sizeof(player_t));

    p->zoom = 0;
    if (!(p->vertex = malloc(sizeof(sfVertex) * 4)))
        return (NULL);
    for (int i = 0; i < 4; ++i)
        p->vertex[i] = (sfVector2f){0, 0};
    p->zone = 0;
    p->clock = sfClock_create();
    init_texture_sprite(col, p);
    init_keys(&p, main);
    p->last = p->down;
    p->move = (sfVector2i){0, 0};
    return (p);
}
