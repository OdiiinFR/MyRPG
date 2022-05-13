/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Inits battle routine.
*/

#include "battle_struct.h"
#include "attack_struct.h"
#include "attack_header.h"
#include "defense_struct.h"
#include "defense_header.h"
#include "enemy_header.h"
#include "enemy_struct.h"
#include <stdlib.h>

static battle_t *init_battle_struct(void)
{
    battle_t *battle;

    if (!(battle = malloc(sizeof(battle_t))))
        return (NULL);
    battle->attack = NULL;
    battle->defense = NULL;
    battle->text = NULL;
    battle->texture = NULL;
    battle->ui = NULL;
    return (battle);
}

static void init_sprites(battle_t *battle, main_t *main)
{
    sfVector2f size = sfView_getSize(main->view);
    int j = 1;

    sfSprite_setPosition(battle->ui[0], (sfVector2f){320, size.y - 260});
    for (int i = 0; i < 4; ++i, ++j)
        sfSprite_setPosition(battle->ui[j], \
        (sfVector2f){(i * 300) + 340, size.y - 200});
}

static void init_texture(battle_t *battle, main_t *main)
{
    sfIntRect rect = {0, 26, 31, 26};

    if (!(battle->ui = malloc(sizeof(sfSprite *) * 7)))
        return;
    if (!(battle->texture = malloc(sizeof(sfTexture *) * 7)))
        return;
    battle->texture[0] = LOADTEX("./res/spr/ui/main_ui.png", NULL);
    battle->texture[1] = LOADTEX("./res/spr/ui/fight.png", NULL);
    battle->texture[2] = LOADTEX("./res/spr/ui/defend.png", NULL);
    battle->texture[3] = LOADTEX("./res/spr/ui/inv.png", NULL);
    battle->texture[4] = LOADTEX("./res/spr/ui/back.png", NULL);
    battle->texture[5] = NULL;
    for (int i = 0; i < 5; ++i) {
        battle->ui[i] = sfSprite_create();
        sfSprite_setTexture(battle->ui[i], battle->texture[i], sfFalse);
    }
    for (int i = 1; i < 5; ++i)
            sfSprite_setTextureRect(battle->ui[i], rect);
    battle->ui[6] = NULL;
    init_sprites(battle, main);
}

static void init_text(battle_t *battle, main_t *main)
{
    sfVector2f size = sfView_getSize(main->view);

    if (!(battle->text = malloc(sizeof(sfText *) * 5)))
        return;
    for (int i = 0; i < 4; ++i) {
        battle->text[i] = sfText_create();
        sfText_setPosition(battle->text[i], (sfVector2f){(i * 300) + 382, size.y - 204});
        sfText_setFont(battle->text[i], main->font);
    }
    sfText_setString(battle->text[0], "Attack !");
    sfText_setString(battle->text[1], "Defend !");
    sfText_setString(battle->text[2], "Inventory !");
    sfText_setString(battle->text[3], "Run !");
    battle->text[4] = NULL;
}

battle_t *init_battle(main_t *main)
{
    battle_t *battle;

    if (!(battle = init_battle_struct()))
        return (NULL);
    if (!(battle->text = malloc(sizeof(sfText *) * 5)))
        return (NULL);
    init_texture(battle, main);
    init_text(battle, main);
    battle->attack = init_attack_struct(main);
    battle->defense = init_defense(main);
    battle->enemies = fetch_enemies();
    return (battle);
}
