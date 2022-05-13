/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Does the battle routine.
*/

#include "main.h"
#include "collisions_header.h"
#include "battle_struct.h"
#include "attack_header.h"
#include "defense_header.h"
#include "defense_struct.h"
#include <SFML/Graphics/RenderWindow.h>

static void draw_assets_battle(battle_t *battle, \
sfSprite *enemy, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, enemy, NULL);
    for (int i = 0; i < 5; ++i)
        sfRenderWindow_drawSprite(window, battle->ui[i], NULL);
    for (int i = 0; i < 4; ++i)
        sfRenderWindow_drawText(window, battle->text[i], NULL);
    sfRenderWindow_display(window);
}

static void choose_inventory(main_t *main)
{
    int end = 0;

    while (end == 0) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            end = 1;
        sfRenderWindow_clear(main->wind.window, sfBlack);
        do_inv(main, main->inv);
        sfRenderWindow_display(main->wind.window);
    }
}

static int do_run()
{
    int random = rand() % 100;

    if (random < 75)
        return (1);
    else
        return (0);
}

static int do_command(int *defend, enemy_t *enemy, int choice, main_t *main)
{
    int end = 0;
    int atk = main->inv->stats[1].stat;

    if (choice == 1)
        enemy->health -= (atk * do_attack(main->battle->attack, \
        main->player->clock, main) - enemy->def);
    if (choice == 2)
        *defend = main->inv->stats[2].stat + 5;
    if (choice == 3)
        choose_inventory(main);
    if (choice == 4)
        end = do_run();
    return (end);
}

static int change_choice(int choice, battle_t *battle, \
main_t *main)
{
    player_t *player = main->player;

    if ((choice > 1) && sfKeyboard_isKeyPressed(player->left)) {
        sfSprite_setTextureRect(battle->ui[choice], (sfIntRect){0, 26, 31, 26});
        --choice;
        sfSprite_setTextureRect(battle->ui[choice], (sfIntRect){0, 0, 31, 26});
    }
    if ((choice < 4) && sfKeyboard_isKeyPressed(player->right)) {
        sfSprite_setTextureRect(battle->ui[choice], (sfIntRect){0, 26, 31, 26});
        ++choice;
        sfSprite_setTextureRect(battle->ui[choice], (sfIntRect){0, 0, 31, 26});
    }
    return (choice);
}

void do_battle_engine(battle_t *battle, main_t *main)
{
    short end = 0;
    short choice = 1;
    int defend = 0;
    sfEvent event;
    int *health = &main->inv->stats[0].stat;
    int zone = main->player->zone;
    enemy_t *enemy =  main->battle->enemies[zone];
    int health_e = enemy->health;

    battle->defense->size = sfView_getSize(main->view);
    change_center(main->view, main, main->player);
    battle->defense->center = sfView_getCenter(main->view);
    sfSprite_setPosition(enemy->enemy, (sfVector2f){battle->defense->center.x, battle->defense->center.y - 300});
    sfRenderWindow_setView(main->wind.window, main->view);
    while (end == 0 && *health > 0 && enemy->health > 0 &&
    sfRenderWindow_isOpen(main->wind.window)) {
        while (sfRenderWindow_pollEvent(main->wind.window, &event)) {
            choice = change_choice(choice, main->battle, main);
            if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
                end = do_command(&defend, enemy, choice, main);
                if (!end) {
                    *health -= enemy->atk * do_defense_loop(main->wind.window, \
                    main->battle->defense, main);
                }
            }
        }
        draw_assets_battle(battle, enemy->enemy, main->wind.window);
    }
    enemy->health = health_e;
}
