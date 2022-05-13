/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Fetches patterns from JSON Files.
*/

#include "main.h"
#include "defense_header.h"
#include "battle_header.h"
#include "enemy_struct.h"
#include "json_parser.h"
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>

static enemy_t *fetch_pattern(enemy_t *enemy, json_t **patterns, int size)
{
    long size_patt;

    if (!(enemy->type = malloc(sizeof(int *) * (size + 1))))
        return (NULL);
    if (!(enemy->speed = malloc(sizeof(int *) * (size + 1))))
        return (NULL);
    if (!(enemy->move = malloc(sizeof(int *) * (size + 1))))
        return (NULL);
    for (int i = 0; i < size; ++i) {
        size_patt = (long)(json_t **)(patterns[i + 6]->value)[0];
        if (!(enemy->type[i] = malloc(sizeof(int) * (size_patt + 1))))
            return (NULL);
        if (!(enemy->speed[i] = malloc(sizeof(int) * (size_patt + 1))))
            return (NULL);
        if (!(enemy->move[i] = malloc(sizeof(int) * (size_patt + 1))))
            return (NULL);
        for (int j = 0; j < size_patt; ++j) {
            enemy->type[i][j] = (long)((json_t **)((json_t **)patterns[i + 6]->value)[j + 1]->value)[1];
            enemy->move[i][j] = (long)((json_t **)((json_t **)patterns[i + 6]->value)[j + 1]->value)[2];
            enemy->speed[i][j] = (long)((json_t **)((json_t **)patterns[i + 6]->value)[j + 1]->value)[3];
        }
        enemy->type[i][size_patt] = -1;
        enemy->speed[i][size_patt] = -1;
        enemy->move[i][size_patt] = -1;
    }
    enemy->type[size] = NULL;
    enemy->speed[size] = NULL;
    enemy->move[size] = NULL;
    return (enemy);
}

static enemy_t *fetch_parsed(json_t **value)
{
    enemy_t *enemy;
    long size = (long)value[0];

    if (!(enemy = malloc(sizeof(enemy_t))))
        return (NULL);
    enemy->tx = LOADTEX((char *)value[1], NULL);
    enemy->enemy = sfSprite_create();
    sfSprite_setTexture(enemy->enemy, enemy->tx, sfFalse);
    enemy->health = (long)value[2];
    enemy->atk = (long)value[3];
    enemy->def = (long)value[4];
    enemy->crit = (long)value[5];
    enemy->type = NULL;
    enemy->speed = NULL;
    enemy = fetch_pattern(enemy, value, size - 6);
    return (enemy);
}

enemy_t **fetch_enemies(void)
{
    json_t *parser;
    enemy_t **enemies;
    sfFloatRect size;

    if (!(enemies = malloc(sizeof(enemy_t) * 2)))
        return (NULL);
    parser = return_parsed_json("./res/defense/flower.json");
    enemies[0] = fetch_parsed((json_t **)parser->value);
    size = sfSprite_getGlobalBounds(enemies[0]->enemy);
    sfSprite_setOrigin(enemies[0]->enemy, (sfVector2f){size.left / 2, size.top / 2});
    sfSprite_setScale(enemies[0]->enemy, (sfVector2f){3, 3});
    return (enemies);
}
