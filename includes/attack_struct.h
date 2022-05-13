/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Contains attack structures.
*/

#ifndef ATTACK_STRUCT_H_
    #define ATTACK_STRUCT_H_

    #include <SFML/Graphics/Sprite.h>

typedef struct attack_struct {
    sfSprite **arrow_init;
    sfTexture *arrow_tx;
    sfSprite **arrow;
    int *type;
    sfRectangleShape **lines;
    sfRectangleShape *box;
    sfRectangleShape *cursor;
    int random;
} attack_t;

#endif /* !ATTACK_STRUCT_H_ */
