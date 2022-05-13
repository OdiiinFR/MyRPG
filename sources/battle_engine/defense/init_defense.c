/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Creates attack patterns for enemies.
*/

#include "defense_struct.h"
#include "main.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Clock.h>
#include <stddef.h>
#include <stdlib.h>

static void init_defense_array(defense_t *defense)
{
    defense->arrows_tx = malloc(sizeof(sfTexture *) * 2);
    defense->arrows = malloc(sizeof(sfSprite *) * 4);
}

static void init_defense_tx(defense_t *defense)
{
    defense->arrows_tx[0] = sfTexture_createFromFile(
        "./res/spr/defense/arrow.png",
        NULL);
    defense->arrows_tx[1] = sfTexture_createFromFile(
        "./res/spr/defense/arrow_clicked.png",
        NULL);
}

static void init_defense_arrows(defense_t *defense, sfVector2f ctr)
{
    float angle = 0;

    for (int i = 0; i < 4; ++i) {
        defense->arrows[i] = sfSprite_create();
        sfSprite_setTexture(defense->arrows[i],
            defense->arrows_tx[0],
            sfFalse);
        sfSprite_setScale(defense->arrows[i], (sfVector2f){0.1, 0.1});
        sfSprite_setRotation(defense->arrows[i], angle);
        sfSprite_setOrigin(defense->arrows[i], (sfVector2f){256, 256});
        angle += 90;
    }
    sfSprite_setPosition(defense->arrows[0], (sfVector2f){ctr.x, ctr.y - 50});
    sfSprite_setPosition(defense->arrows[1], (sfVector2f){ctr.x + 50, ctr.y});
    sfSprite_setPosition(defense->arrows[2], (sfVector2f){ctr.x, ctr.y + 50});
    sfSprite_setPosition(defense->arrows[3], (sfVector2f){ctr.x - 50, ctr.y});
}

void init_pattern(defense_t *defense)
{
    defense->pattern = malloc(sizeof(pattern_t));
    defense->pattern->arrow = NULL;
    defense->pattern->nb = 0;
    defense->pattern->speed = 0;
    defense->pattern->next = NULL;
    defense->pattern->bef = NULL;
    defense->pattern->move = 0;
    defense->pattern->killed = 0;
}

defense_t *init_defense(main_t *main)
{
    defense_t *defense;
    sfVector2f ctr = sfView_getCenter(main->view);

    if (!(defense = malloc(sizeof(defense_t))))
        return (NULL);
    defense->arrows = NULL;
    defense->arrows_tx = NULL;
    defense->pattern = NULL;
    init_defense_array(defense);
    init_defense_tx(defense);
    init_defense_arrows(defense, ctr);
    init_pattern(defense);
    defense->clock = sfClock_create();
    defense->clock_seconds = sfClock_create();
    defense->size = (sfVector2f){0, 0};
    defense->center = (sfVector2f){0, 0};
    return (defense);
}
