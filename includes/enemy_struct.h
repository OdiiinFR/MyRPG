/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Contains the enemies structure.
*/

#ifndef ENEMY_STRUCT_H_
    #define ENEMY_STRUCT_H_

    #include <SFML/Graphics/Sprite.h>
    #include "defense_struct.h"

typedef struct enemy {
    long health;
    long atk;
    long def;
    long crit;
    sfSprite *enemy;
    sfTexture *tx;
    int **type;
    int **speed;
    int **move;
} enemy_t;

#endif /* !ENEMY_STRUCT_H_ */
