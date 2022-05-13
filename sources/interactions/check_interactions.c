/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Checks collisions with interactable objects.
*/

#include "player_structs.h"
#include "collisions_header.h"
#include "collisions_structs.h"
#include "handle_text.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/RenderWindow.h>

void free_loop(tmp_t *cells)
{
    sfText_destroy(cells->bef->text);
    free(cells->bef->copy);
    free(cells->bef);
    sfText_destroy(cells->text);
    free(cells->copy);
    free(cells);
}

static void check_for_text(char **text, \
main_t *main, player_t *player, col_t *col)
{
    sfVector2f move = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyEnter))
        do_text_loop(text, main, player, col);
    if (player->move.x > 0)
        move.x -= 8;
    else if (player->move.x < 0)
        move.x += 8;
    if (player->move.y > 0)
        move.y -= 8;
    else if (player->move.y < 0)
        move.y += 8;
    sfSprite_move(player->sp_player, move);
}

int check_interactions(main_t *main, col_t *col)
{
    int zone = main->player->zone;
    player_t *player = main->player;
    sfFloatRect rect_player = sfSprite_getGlobalBounds(player->sp_player);
    sfFloatRect rect;

    for (int i = 0; col->inter->sprites[zone][i] != NULL; ++i) {
        rect = sfSprite_getGlobalBounds(col->inter->sprites[zone][i]);
        if (sfFloatRect_intersects(&rect, &rect_player, NULL)) {
            check_for_text(col->inter->text[zone][i], main, player, col);
        }
    }
    return (0);
}
