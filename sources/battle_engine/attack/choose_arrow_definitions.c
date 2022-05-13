/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Chooses arrows placements.
*/

#include "attack_struct.h"
#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RectangleShape.h>

static void arrow_init(attack_t *attack, \
sfVector2f *pos, int i, int j)
{
    int random = (rand() % 236) + 32;

    pos->x = (rand() % attack->random) + 32;
    attack->arrow[i] = sfSprite_copy(attack->arrow_init[j]);
    attack->type[i] = j;
    sfRectangleShape_setPosition(attack->lines[i], *pos);
    sfSprite_setPosition(attack->arrow[i],
    (sfVector2f){(*pos).x - 32, (*pos).y + random});
    srand(rand());
}

void chooses_arrows(attack_t *attack)
{
    sfVector2f pos;
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(attack->box);
    void *random = malloc(sizeof(0));

    pos.y = rect.top;
    attack->random = rect.width - 64;
    srand((long)random);
    for (int i = 0; i < 10; ++i) {
        switch (rand() % 4) {
            case (0): arrow_init(attack, &pos, i, 0);
                break;
            case (1): arrow_init(attack, &pos, i, 1);
                break;
            case (2): arrow_init(attack, &pos, i, 2);
                break;
            case (3): arrow_init(attack, &pos, i, 3);
                break;
        }
    }
}
