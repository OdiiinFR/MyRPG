/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Does animations with clocks.
*/

#include "player_structs.h"
#include "main.h"
#include <SFML/System/Clock.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

static void update_rect(player_t *player, sfEvent *event)
{
    int code = (*event).key.code;

    if ((player->up != code) && (player->down != code) &&
    (player->right != code) && (player->left != code))
        return;
    player->rect.left = 32;
    if (player->up == code)
        player->rect.top = 96;
    if (player->down == code)
        player->rect.top = 0;
    if (player->right == code)
        player->rect.top = 64;
    if (player->left == code)
        player->rect.top = 32;
    sfSprite_setTextureRect(player->sp_player, player->rect);
    sfClock_restart(player->clock);
}

static void fetch_last(player_t *player, unsigned char key)
{
    player->last = key;
    sfSprite_setTextureRect(player->sp_player, player->rect);
    player->rect.left += 32;
    if (player->rect.left > 64)
        player->rect.left = 0;
}

static void return_normal(player_t *player)
{
    player->rect.left = 32;
    if (player->up == player->last)
        player->rect.top = 96;
    if (player->down == player->last)
        player->rect.top = 0;
    if (player->right == player->last)
        player->rect.top = 64;
    if (player->left == player->last)
        player->rect.top = 32;
    sfSprite_setTextureRect(player->sp_player, player->rect);
    sfClock_restart(player->clock);
}

void do_animation(player_t *player, sfEvent *event, main_t *main)
{
    sfTime time = sfClock_getElapsedTime(player->clock);
    float seconds = sfTime_asMicroseconds(time) / 1000000.0;

    if ((seconds > 0.075) && (key_is_pressed(player) ||
    (button_mvt_is_pressed(main) && main->flag == 1))) {
        if (player->last != (*event).key.code)
            update_rect(player, event);
        if (player->up == (*event).key.code)
            fetch_last(player, player->up);
        if (player->down == (*event).key.code)
            fetch_last(player, player->down);
        if (player->right == (*event).key.code)
            fetch_last(player, player->right);
        if (player->left == (*event).key.code)
            fetch_last(player, player->left);
    } else if ((*event).type == sfEvtKeyReleased ||
    (button_mvt_is_rea(main) && main->flag == 1))
        return_normal(player);
}
