/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Follows the player at all times.
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>
#include "player_structs.h"

void view_follow(sfView *view, player_t *player, sfRenderWindow *window)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(player->sp_player);
    sfVector2f pos = {rect.left + rect.width / 2, rect.top + rect.height / 2};

    sfView_setCenter(view, pos);
    if (player->zoom == 0) {
        sfView_zoom(view, 0.5);
        player->zoom = 1;
    }
    sfRenderWindow_setView(window, view);
}
