/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** set_window
*/

#include "sounds.h"
#include "battle_header.h"
#include "animations.h"
#include "main.h"
#include "collisions_header.h"
#include "collisions_structs.h"
#include "player_structs.h"
#include <SFML/Audio.h>

void analyse_event2(sfEvent event, main_t *main, int menu)
{
    my_key_t **tmp = main->config->keys;
    if (menu == 2 && main->event == 2 && event.key.code == tmp[5]->key)
        main->wind.menu = 8;
    else if (menu == 8 && main->event == 2 && event.key.code == tmp[5]->key)
        main->wind.menu = 2;
    if ((menu == 2 || menu == 5 || menu == 4) && main->event == 2 &&
    event.key.code == tmp[6]->key)
        main->wind.menu = 9;
    else if (menu == 9 && main->event == 2 && event.key.code == tmp[6]->key)
        main->wind.menu = 2;
    if ((menu == 2 || menu == 5 || menu == 4) && main->event == 2 &&
    event.key.code == tmp[7]->key)
        main->wind.menu = 10;
    else if (menu == 10 && main->event == 2 && event.key.code == tmp[7]->key)
        main->wind.menu = 2;
    if ((menu == 2 || menu == 5 || menu == 4) && main->event == 2 &&
    event.key.code == tmp[4]->key)
        main->wind.menu = 11;
    else if (menu == 11 && main->event == 2 && event.key.code == tmp[4]->key)
        main->wind.menu = 2;
}

void analyse_event(sfEvent event, main_t *main, player_t *player, col_t *col)
{
    if (main->flag == 1)
        find_joy(main->joy, main, &event);
    if (main->wind.menu == 2 || main->wind.menu == 5 || main->wind.menu != 4)
        move_character(player, col, &event, main);
    if (event.type == sfEvtKeyPressed && main->last_event == sfEvtKeyPressed)
        return;
    if (event.type == sfEvtKeyReleased) {
        main->event = 0;
        main->last_event = sfEvtKeyReleased;
    }
    if (event.type == sfEvtMouseButtonReleased)
        main->event = 0;
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(main->wind.window);
    if (event.type == sfEvtMouseButtonPressed)
        main->event = 1;
    if (event.type == sfEvtKeyPressed) {
        main->last = event.key.code;
        main->event = 2;
        main->last_event = sfEvtKeyPressed;
    }
    if (event.type == sfEvtJoystickButtonReleased)
        main->flag = 0;
    if (event.type == sfEvtJoystickButtonPressed) {
        main->event = 2;
        main->flag = 1;
        find_joy(main->joy, main, &event);
    }
    return analyse_event2(event, main, main->wind.menu);
}

void show_menu2(main_t *main, col_t *col, player_t *player)
{
    if (main->wind.menu == 7) {
        do_config_key(main);
        init_keys(&player, main);
    }
    if (main->wind.menu == 2)
        do_game(main, col, player);
    if (main->wind.menu == 9)
        do_skilltree(main);
    if (main->wind.menu == 8)
        do_inv(main, main->inv);
    if (main->wind.menu == 10)
        do_quests(main);
    if (main->wind.menu == 11)
        do_pause(main);
    sfRenderWindow_display(main->wind.window);
}

void show_menu(main_t *mai, sfView *view, col_t *col, player_t *player)
{
    sfEvent event;

    mai->view = view;
    if (mai->joy->nb == -1)
        find_joys(mai->joy);
    while (sfRenderWindow_pollEvent(mai->wind.window, &event) || mai->flag == 1) {
        analyse_event(event, mai, player, col);
        if (mai->flag == 1)
            break;
    }
    if (mai->wind.menu != 2 && mai->wind.menu != 5 && mai->wind.menu != 4)
        change_center(view, mai, player);
    sfRenderWindow_clear(mai->wind.window, sfBlack);
    if (mai->wind.menu == 0)
        do_main(mai);
    if (mai->wind.menu == 5 || mai->wind.menu == 4)
        do_htp(mai, col);
    if (mai->wind.menu == 1 || mai->wind.menu == -1 || mai->wind.menu == -2)
        do_save(mai);
    if (mai->wind.menu == 3)
        do_settings(mai);
    if (mai->wind.menu == 6)
        do_resolution(mai);
    return show_menu2(mai, col, player);
}

int set_window(void)
{
    main_t main = fill_main();
    col_t *col = init_col();
    player_t *player = init_player(col, &main);
    sfView *view = init_view(main.wind.window);

    inv_add(&main, 0, main.inv);
    inv_add(&main, 2, main.inv);
    inv_add(&main, 3, main.inv);
    inv_add(&main, 4, main.inv);
    inv_add(&main, 5, main.inv);
    inv_add(&main, 6, main.inv);
    inv_add(&main, 7, main.inv);
    inv_add(&main, 8, main.inv);
    inv_add(&main, 9, main.inv);
    apply_volume(&main);
    sfMusic_play(main.sounds->menu);
    main.player = player;
    main.view = view;
    main.battle = init_battle(&main);
    while (sfRenderWindow_isOpen(main.wind.window))
        show_menu(&main, view, col, player);
    sfView_destroy(view);
    free_all(&main);
    return 0;
}
