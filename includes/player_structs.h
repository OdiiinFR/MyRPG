/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Contains the structures for the player/characters.
*/

#ifndef PLAYER_STRUCTS_H_
    #define PLAYER_STRUCTS_H_

    #include <SFML/Graphics/Sprite.h>
    #include <SFML/System/Clock.h>

typedef struct player {
    sfTexture *tx_player;
    sfSprite *sp_player;
    sfFloatRect bounds;
    sfVector2f *vertex;
    sfClock *clock;
    unsigned char up;
    unsigned char down;
    unsigned char left;
    unsigned char right;
    unsigned char zone;
    unsigned char diff;
    unsigned char zoom;
    unsigned char last;
    sfVector2i move;
    sfIntRect rect;
} player_t;

#endif /* !PLAYER_STRUCTS_H_ */
