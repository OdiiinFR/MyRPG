/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Contains the battle structure.
*/

#ifndef BATTLE_STRUCT_H_
    #define BATTLE_STRUCT_H_

    #include "attack_struct.h"
    #include "defense_struct.h"
    #include "enemy_struct.h"
    #include <SFML/Graphics/Sprite.h>

typedef struct battle {
    attack_t *attack;
    defense_t *defense;
    enemy_t **enemies;
    sfSprite **ui;
    sfTexture **texture;
    sfText **text;
} battle_t;

#endif /* !BATTLE_STRUCT_H_ */