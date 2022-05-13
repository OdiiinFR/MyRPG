/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Structures for collisions handling.
*/

#ifndef COLLISIONS_STRUCTS_H_
    #define COLLISIONS_STRUCTS_H_

    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/VertexArray.h>
    #define LOADTEX(str, area) sfTexture_createFromFile(str, area)

typedef struct tmp {
    struct tmp *bef;
    struct tmp *next;
    sfText *text;
    char *copy;
} tmp_t;

typedef struct interactions {
    int *id_max;
    sfTexture ***tx;
    sfSprite ***sprites;
    char ****text;
} interact_t;

typedef struct collisions_env {
    sfTexture **tx_col;
    sfSprite **sp_col;
    sfVertexArray ***array;
    int ***type;
    sfFloatRect ***transitions;
    int ***positions;
    struct interactions *inter;
} col_t;

#endif /* !COLLISIONS_HEADER_H_ */
