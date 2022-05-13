/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Debug room used as a tutorial.
*/

#include "main.h"
#include "collisions_structs.h"
#include "player_structs.h"
#include "collisions_header.h"

void draw_debug(main_t *main, col_t *col, player_t *player)
{
    view_follow(main->view, player, main->wind.window);
    sfRenderWindow_drawSprite(main->wind.window, col->sp_col[player->zone],
        NULL);
    sfRenderWindow_drawSprite(main->wind.window, player->sp_player, NULL);
    for (int i = 0; col->array[player->zone][i]; ++i)
        sfRenderWindow_drawVertexArray(main->wind.window,
            col->array[player->zone][i], NULL);
    for (int i = 0; col->inter->sprites[player->zone][i] != NULL; ++i)
        sfRenderWindow_drawSprite(main->wind.window,
        col->inter->sprites[player->zone][i], NULL);
    if (main->hud == 0)
        print_hud1(main, main->view);
    if (main->hud == 1)
        print_hud2(main);
}
