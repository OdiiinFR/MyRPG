/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Checks for player_interactions.
*/

#include "collisions_structs.h"
#include "json_parser.h"
#include "json_structs.h"
#include "my.h"
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>

static void free_parsed(void **parsed)
{
    json_t **value = ((json_t **)(*(json_t **)parsed)->value);
    long size = (long)value[0];
    json_t *text;

    for (int i = 1; i < size + 1; ++i) {
        free(((json_t **)((json_t **)value)[i]->value)[1]);
        free(((json_t **)((json_t **)value)[i]->value)[2]);
        text = ((json_t **)((json_t **)value)[i]->value)[3];
        for (int j = 1; text->value[j] != NULL; ++j)
            free(text->value[j]);
        free(text);
        free(value[i]);
    }
}

static void set_up_sprites(interact_t **inter, json_t **value, \
int zone, int i)
{
    long x = (long)((json_t **)((json_t **)(value[i]->value))[2]->value)[1];
    long y = (long)((json_t **)((json_t **)(value[i]->value))[2]->value)[2];
    sfTexture *tx = LOADTEX((char *)((json_t **)value)[i]->value[1], NULL);
    sfSprite *sp = sfSprite_create();

    sfSprite_setTexture(sp, tx, sfFalse);
    sfSprite_setPosition(sp, (sfVector2f){x, y});
    sfSprite_setScale(sp, (sfVector2f){0.25, 0.25});
    (*inter)->tx[zone][i - 1] = tx;
    (*inter)->sprites[zone][i - 1] = sp;
}

static int fetch_texts(json_t **value, interact_t **inter, int zone, int i)
{
    json_t *texts = ((json_t **)((json_t **)value)[i]->value)[3];
    long size = (long)(texts->value)[0];
    int size_quote;
    char *copy;
    int k;

    if (!((*inter)->text[zone][i - 1] = malloc(sizeof(char *) * (size + 1))))
        return (84);
    for (int j = 1; j < size + 1; ++j) {
        size_quote = my_strlen((char *)texts->value[j]);
        if (!(copy = malloc(sizeof(char) * (size_quote + 1))))
            return (84);
        for (k = 0; ((char *)texts->value[j])[k] != '\0'; ++k)
            copy[k] = ((char *)texts->value[j])[k];
        copy[k] = '\0';
        (*inter)->text[zone][i - 1][j - 1] = copy;
    }
    (*inter)->text[zone][i - 1][size] = NULL;
    return (0);
}

int fetch_infos(void **parsed, interact_t **inter, int zone)
{
    long size = (long)((*(json_t **)parsed)->value)[0];
    json_t **value = (json_t **)((*(json_t **)parsed)->value);

    (*inter)->id_max[zone] = size;
    if (!((*inter)->tx[zone] = malloc(sizeof(sfTexture *) * (size + 1))))
        return (84);
    if (!((*inter)->sprites[zone] = malloc(sizeof(sfSprite *) * (size + 1))))
        return (84);
    if (!((*inter)->text[zone] = malloc(sizeof(char **) * (size + 1))))
        return (84);
    for (int i = 1; i < size + 1; ++i) {
        set_up_sprites(inter, value, zone, i);
        fetch_texts(value, inter, zone, i);
    }
    (*inter)->tx[zone][size] = NULL;
    (*inter)->sprites[zone][size] = NULL;
    free_parsed(parsed);
    return (0);
}
