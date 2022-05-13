/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Checks for events in the collisions engine.
*/

#include "collisions_structs.h"
#include "player_structs.h"
#include "battle_header.h"
#include "battle_struct.h"
#include "collisions_header.h"
#include "animations.h"
#include "sounds.h"
#include "handle_text.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>

static sfVector2f move_up_down(sfVector2f move, player_t *player, int *key, main_t *main)
{
    if (*key == player->up && main->flag == 0)
        move.y -= 10;
    else if (*key == player->up && main->flag == 1)
        move.y -= 5;
    if (*key == player->down && main->flag == 0)
        move.y += 10;
    else if (*key == player->down && main->flag == 1)
        move.y += 5;
    return (move);
}

static sfVector2f move_left_right(sfVector2f move, player_t *player, int *key, main_t *main)
{
    if (*key == player->right && main->flag == 0)
        move.x += 10;
    else if (*key == player->right && main->flag == 1)
        move.x += 5;
    if (*key == player->left && main->flag == 0)
        move.x -= 10;
    else if (*key == player->left && main->flag == 1)
        move.x -= 5;
    return (move);
}

static void choose_diagonal_movement(player_t *player, sfEvent *event, main_t *main)
{
    if (((*event).type == sfEvtKeyPressed || (button_mvt_is_pressed(main) && main->flag)) && (player->move.x == 0))
        player->move.x = (*event).key.code;
    else if (((*event).type == sfEvtKeyReleased || button_mvt_is_rea(main)) && (player->move.x != 0))
        player->move.x = 0;
    if ((player->move.x != 0) && (player->move.x != player->up) &&
    (player->move.x != player->down) && (player->move.x != player->right) &&
    (player->move.x != player->left)) {
        player->move.x = 0;
    }
    if (((*event).type == sfEvtKeyPressed || (button_mvt_is_pressed(main) && main->flag)) &&
    ((*event).key.code != player->move.x) && (player->move.y == 0))
        player->move.y = (*event).key.code;
    else if (((*event).type == sfEvtKeyReleased || button_mvt_is_rea(main)) && (player->move.y != 0))
        player->move.y = 0;
    if ((player->move.y != 0) && (player->move.y != player->up) &&
    (player->move.y != player->down) && (player->move.y != player->right) &&
    (player->move.y != player->left)) {
        player->move.y = 0;
    }
}

static void set_player(player_t *player, main_t *main, col_t *col, int *key)
{
    sfVector2f move = {0, 0};
    int zone = player->zone;

    move = move_up_down(move, player, key, main);
    move = move_left_right(move, player, key, main);
    sfSprite_move(player->sp_player, move);
    update_zone(col, player, main);
    intersects_vertex(col->array[zone], col->type[zone], player, key);
}

void move_character(player_t *player, col_t *col, sfEvent *event, main_t *main)
{
    do_animation(player, event, main);
    choose_diagonal_movement(player, event, main);
    if ((*event).type == sfEvtKeyPressed ||
    (button_mvt_is_pressed(main) && main->flag)) {
        if (player->move.x)
            set_player(player, main, col, &player->move.x);
        if (player->move.y)
            set_player(player, main, col, &player->move.y);
        if (((rand() % 1000) > 900) && main->wind.is_in_htp)
            do_battle_engine(main->battle, main);
    }
    if (player->zone == 0)
        check_interactions(main, col);
}
