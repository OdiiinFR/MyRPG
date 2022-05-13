/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Moves the player back.
*/

#include "player_structs.h"
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

static int choose_correct_key(int *key, player_t *player)
{
    if (*key == player->up)
        return (0);
    if (*key == player->down)
        return (1);
    if (*key == player->left)
        return (2);
    if (*key == player->right)
        return (3);
    return (84);
}

static void move_diagonal(player_t *player, int *key)
{
    switch (choose_correct_key(key, player)) {
        case (0): sfSprite_move(player->sp_player, (sfVector2f){0, 10});
            break;
        case (1): sfSprite_move(player->sp_player, (sfVector2f){0, -10});
            break;
        case (2): sfSprite_move(player->sp_player, (sfVector2f){10, 0});
            break;
        case (3): sfSprite_move(player->sp_player, (sfVector2f){-10, 0});
            break;
    }
}

static void move_vertical(player_t *player, int *key)
{
    if (player->left == *key) {
            sfSprite_move(player->sp_player, (sfVector2f){10, 0});
    } else {
            sfSprite_move(player->sp_player, (sfVector2f){-10, 0});
    }
}

static void move_horizontal(player_t *player, int *key)
{
    if (player->up == *key) {
            sfSprite_move(player->sp_player, (sfVector2f){0, 10});
    } else {
            sfSprite_move(player->sp_player, (sfVector2f){0, -10});
    }
}

void move_back(player_t *player, int type, int *key)
{
    if (type == 0) {
        move_horizontal(player, key);
        return;
    }
    if (type == 1) {
        move_vertical(player, key);
        return;
    }
    if (type == 2)
        move_diagonal(player, key);
}
