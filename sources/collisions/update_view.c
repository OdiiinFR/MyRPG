/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Update view.
*/

#include <SFML/Graphics/View.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/View.h>
#include "main.h"
#include "sounds.h"

void change_center(sfView *view, main_t *main, player_t *player)
{
    sfFloatRect p = sfSprite_getGlobalBounds(main->start->Sprit_back);
    sfVector2f center = {p.left + (p.width / 2), p.top + (p.height / 2)};

    sfView_setCenter(view, center);
    if (player->zoom == 1)
        sfView_zoom(view, 2);
    sfRenderWindow_setView(main->wind.window, view);
    player->zoom = 0;
}

static void fetch_true_entry(int zone, col_t *col, int *j, int *i)
{
    int **pos = col->positions[zone];

    for (*j = *i; pos[*j][3] != pos[*i][3]; ++(*j));
}

int update_zone(col_t *col, player_t *player, main_t *main)
{
    sfFloatRect rect_p = sfSprite_getGlobalBounds(player->sp_player);
    int zone = player->zone;
    sfVector2f pos;
    int j;
    int former_zone = player->zone;

    for (int i = 0; col->transitions[zone][i] != NULL; ++i) {
        if (sfFloatRect_intersects(col->transitions[zone][i], &rect_p, NULL)) {
            sfRenderWindow_clear(main->wind.window, sfBlack);
            do_close_curtain(main);
            player->zone = col->positions[zone][i][2];
            fetch_true_entry(zone, col, &j, &i);
            pos.x = col->positions[zone][j][0];
            pos.y = col->positions[zone][j][1];
            player->diff = col->positions[zone][i][3];
            sfSprite_setPosition(player->sp_player, pos);
            do_music(main, former_zone);
            do_open_curtain(main);
            return (0);
        }
    }
    return (84);
}
