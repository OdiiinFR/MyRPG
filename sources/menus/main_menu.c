/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** main_menu
*/

#include "main.h"
#include "collisions_header.h"
#include "debug.h"
#include "sounds.h"

htp_menu_t *create_htp(void)
{
    htp_menu_t *new = malloc(sizeof(htp_menu_t));
    sfVector3f back = {50, 50, 1};
    sfVector2f pos = {0, 0};

    new->back = new_button("\t Back\0", back, 0, 22);
    new->Sprit_back = sfSprite_create();
    new->Texture_back = sfTexture_createFromFile(BCK_PARMAS, NULL);
    sfSprite_setTexture(new->Sprit_back, new->Texture_back, sfFalse);
    sfSprite_setPosition(new->Sprit_back, pos);
    return new;
}

void do_htp(main_t *main, col_t *col)
{
    if (main->wind.is_in_htp == 0) {
        sfSprite_setPosition(main->player->sp_player, (sfVector2f){400, 350});
        main->wind.is_in_htp = 1;
    }
    draw_debug(main, col, main->player);
    return;
}

main_menu_t *create_main(void)
{
    main_menu_t *new = malloc(sizeof(main_menu_t));
    sfVector2f pos = {0, 0};
    sfVector3f play = {1230, 380, 1};
    sfVector3f score = {1230, 540, 1};
    sfVector3f params = {1230, 700, 1};
    sfVector3f quit = {1230, 860, 1};
    sfVector3f htp = {100, 900, 1};

    new->Sprit_back = sfSprite_create();
    new->Texture_back = sfTexture_createFromFile(BCK_MAIN, NULL);
    sfSprite_setTexture(new->Sprit_back, new->Texture_back, sfFalse);
    sfSprite_setPosition(new->Sprit_back, pos);
    new->play = new_button("\t\t\t Play\0", play, 1, 0);
    new->htp = new_button("HTP\0", htp, 5, 19);
    new->quit = new_button("\t\t\t Quit\0", quit, 0, 1);
    new->score = new_button("\t\t   Scores\0", params, 4, 0);
    new->settings = new_button("\t\t Settings\0", score, 3, 0);
    return new;
}

void do_main(main_t *main)
{
    main->params->back->menu_dir = 0;
    if (main->player->zone != 0) {
        stop_music(main, main->player->zone);
        sfMusic_play(main->sounds->menu);
        main->player->zone = 0;
    }
    sfRenderWindow_drawSprite(main->wind.window,
    main->start->Sprit_back, NULL);
    btn_action(main->start->play, main);
    btn_action(main->start->score, main);
    btn_action(main->start->settings, main);
    btn_action(main->start->htp, main);
    btn_action(main->start->quit, main);
    return;
}
