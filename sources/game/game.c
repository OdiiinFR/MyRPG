/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** game
*/

#include "animations.h"
#include "player_structs.h"
#include "collisions_structs.h"
#include "collisions_header.h"
#include "main.h"

static void do_inv2(main_t *main, inventory_t *inv)
{
    sfText_setString(inv->stats[0].print, my_itoa(main->inv->stats[0].stat));
    sfText_setString(inv->stats[1].print, my_itoa(main->inv->stats[1].stat));
    sfText_setString(inv->stats[2].print, my_itoa(main->inv->stats[2].stat));
    sfRenderWindow_drawText(main->wind.window,
    main->inv->stats[0].print, NULL);
    sfRenderWindow_drawText(main->wind.window,
    main->inv->stats[1].print, NULL);
    sfRenderWindow_drawText(main->wind.window,
    main->inv->stats[2].print, NULL);
}

void do_inv(main_t *main, inventory_t *inv)
{
    sfRenderWindow_drawSprite(main->wind.window, main->play->Sprit_back, NULL);
    sfRenderWindow_drawSprite(main->wind.window, main->inv->spr, NULL);
    sfRenderWindow_drawText(main->wind.window, main->inv->inv, NULL);
    sfRenderWindow_drawText(main->wind.window, main->inv->equip, NULL);
    sfRenderWindow_drawText(main->wind.window, main->inv->preview, NULL);
    sfRenderWindow_drawText(main->wind.window, main->inv->perso, NULL);
    sfRenderWindow_drawText(main->wind.window, main->inv->statistics, NULL);
    sfRenderWindow_drawSprite(main->wind.window,
    main->inv->stats[0].spr, NULL);
    sfRenderWindow_drawSprite(main->wind.window,
    main->inv->stats[1].spr, NULL);
    sfRenderWindow_drawSprite(main->wind.window,
    main->inv->stats[2].spr, NULL);
    do_inv2(main, inv);
    update_inv(main, main->inv, main->wind.window);
}

void do_quests(main_t *main)
{
    sfRenderWindow_drawSprite(main->wind.window, main->play->Sprit_back, NULL);
    sfRenderWindow_drawSprite(main->wind.window, main->quests->spr, NULL);
    sfRenderWindow_drawText(main->wind.window, main->quests->desc, NULL);
    sfRenderWindow_drawText(main->wind.window,
    main->quests->description, NULL);
    sfRenderWindow_drawText(main->wind.window, main->quests->done, NULL);
    sfRenderWindow_drawText(main->wind.window, main->quests->quest, NULL);
    sfRenderWindow_drawText(main->wind.window, main->quests->second, NULL);
    btn_action(main->quests->qst1, main);
    btn_action(main->quests->qst2, main);
    btn_action(main->quests->qst3, main);
    btn_action(main->quests->qst4, main);
    btn_action(main->quests->qst5, main);
}

void do_game(main_t *main, col_t *col, player_t *player)
{
    if (main->wind.is_in_htp == 1)
        main->wind.is_in_htp = 0;
    do_train(main , col);
    view_follow(main->view, player, main->wind.window);
    sfRenderWindow_drawSprite(main->wind.window, col->sp_col[player->zone],
        NULL);
    sfRenderWindow_drawSprite(main->wind.window, player->sp_player, NULL);
    /*for (int i = 0; col->array[player->zone][i]; ++i)
        sfRenderWindow_drawVertexArray(main->wind.window,
        col->array[player->zone][i], NULL);*/
    if (player->zone == 0) {
        for (int i = 0; col->inter->sprites[player->zone][i] != NULL; ++i)
            sfRenderWindow_drawSprite(main->wind.window,
            col->inter->sprites[player->zone][i], NULL);
    }
    if (main->hud == 0)
        print_hud1(main, main->view);
    if (main->hud == 1)
        print_hud2(main);
    if (player->zone == 1 && main->train == 1)
        sfRenderWindow_drawSprite(main->wind.window, main->spr_train, NULL);
    if (player->zone > 2 && player->zone < 6) {
        do_rain(main);
        do_fog(main);
    }
}
