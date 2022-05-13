/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Does the attack_pattern.c
*/

#include "attack_struct.h"
#include "collisions_structs.h"
#include "main.h"
#include <stddef.h>
#include <SFML/Graphics/View.h>
#include <SFML/Graphics/RectangleShape.h>

static attack_t *init_structure(void)
{
    attack_t *attack;

    if (!(attack = malloc(sizeof(attack_t))))
        return (NULL);
    attack->arrow = NULL;
    attack->arrow_init = NULL;
    attack->arrow_tx = NULL;
    attack->box = NULL;
    attack->cursor = NULL;
    attack->lines = NULL;
    attack->type = NULL;
    return (attack);
}

static void init_arrows(attack_t *attack)
{
    int i = 0;

    if (!(attack->arrow_init = malloc(sizeof(sfSprite *) * 5)))
        return;
    attack->arrow_tx = LOADTEX("./res/spr/attack/arrows.png", NULL);
    for (i = 0; i < 4; ++i) {
        attack->arrow_init[i] = sfSprite_create();
        sfSprite_setTexture(attack->arrow_init[i], attack->arrow_tx, sfFalse);
        sfSprite_setScale(attack->arrow_init[i], (sfVector2f){4, 4});
    }
    sfSprite_setTextureRect(attack->arrow_init[0], (sfIntRect){0, 0, 17, 17});
    sfSprite_setTextureRect(attack->arrow_init[1], (sfIntRect){17, 0, 17, 17});
    sfSprite_setTextureRect(attack->arrow_init[2], (sfIntRect){34, 0, 17, 17});
    sfSprite_setTextureRect(attack->arrow_init[3], (sfIntRect){51, 0, 17, 17});
    attack->arrow_init[i] = NULL;
}

static void init_attack_arrays(attack_t *attack, sfVector2f pos)
{
    if (!(attack->type = malloc(sizeof(int *) * 11)))
        return;
    if (!(attack->arrow = malloc(sizeof(sfSprite *) * 11)))
        return;
    if (!(attack->lines = malloc(sizeof(sfRectangleShape *) * 11)))
        return;
    for (int i = 0; i < 11; ++i) {
        attack->lines[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(attack->lines[i], (sfVector2f){2, 300});
        sfRectangleShape_setPosition(attack->lines[i], pos);
        sfRectangleShape_setFillColor(attack->lines[i], sfBlue);
        sfRectangleShape_setOutlineThickness(attack->lines[i], 0);
        attack->arrow[i] = NULL;
        attack->type[i] = -1;
    }
}

attack_t *init_attack_struct(main_t *main)
{
    attack_t *attack = init_structure();
    sfVector2f center = sfView_getCenter(main->view);
    sfVector2f size = sfView_getSize(main->view);
    sfVector2f pos = {0, size.y - center.y - 150};

    attack->box = sfRectangleShape_create();
    attack->cursor = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(attack->box, 2);
    sfRectangleShape_setOutlineColor(attack->box, sfWhite);
    sfRectangleShape_setFillColor(attack->box, sfBlack);
    sfRectangleShape_setOutlineColor(attack->cursor, sfWhite);
    sfRectangleShape_setOutlineThickness(attack->cursor, 0);
    sfRectangleShape_setFillColor(attack->cursor, sfWhite);
    sfRectangleShape_setPosition(attack->box, pos);
    sfRectangleShape_setPosition(attack->cursor, pos);
    sfRectangleShape_setSize(attack->box, (sfVector2f){size.x, 300});
    sfRectangleShape_setSize(attack->cursor, (sfVector2f){2, 300});
    init_arrows(attack);
    init_attack_arrays(attack, pos);
    return (attack);
}
