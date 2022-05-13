/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** do_cutscene
*/

#include "main.h"

void do_train(main_t *main, col_t *col)
{
    sfFloatRect tmp = sfSprite_getGlobalBounds(main->player->sp_player);
    sfFloatRect tmp2 = sfSprite_getGlobalBounds(main->spr_train);
    sfVector2f pos = {0, 450};
    sfFloatRect center = sfSprite_getGlobalBounds(col->sp_col[main->player->zone]);

    if (main->player->zone == 1 && main->train == 0 && tmp.top > 170) {
        sfView_setCenter(main->view, (sfVector2f){tmp2.left + tmp2.width / 2, tmp2.top + tmp2.height / 2});
        while (main->train != 1 && sfRenderWindow_isOpen(main->wind.window)) {
            tmp2 = sfSprite_getGlobalBounds(main->spr_train);
            pos.x = tmp2.left + tmp2.width / 2;
            if (pos.x >= center.width / 2) {
                main->train = 1;
                break;
            }
            sfSprite_move(main->spr_train, (sfVector2f){7, 0});
            sfView_setCenter(main->view, (sfVector2f){tmp2.left + tmp2.width / 2, tmp2.top + tmp2.height / 2});
            sfRenderWindow_clear(main->wind.window, sfBlack);
            sfRenderWindow_drawSprite(main->wind.window, col->sp_col[main->player->zone], NULL);
            sfRenderWindow_drawSprite(main->wind.window, main->spr_train, NULL);
            sfRenderWindow_drawSprite(main->wind.window, main->player->sp_player, NULL);
            sfRenderWindow_setView(main->wind.window, main->view);
            sfRenderWindow_display(main->wind.window);
        }
    }
}
