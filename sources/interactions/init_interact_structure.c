/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Initialises interact_t.
*/

#include "collisions_structs.h"
#include "handle_text.h"
#include "json_parser.h"
#include "json_structs.h"

static interact_t *malloc_interactions(void)
{
    interact_t *inter;

    if (!(inter = malloc(sizeof(interact_t))))
        return (NULL);
    if (!(inter->id_max = malloc(sizeof(int) * (12 + 1))))
        return (NULL);
    if (!(inter->sprites = malloc(sizeof(sfSprite **) * (12 + 1))))
        return (NULL);
    if (!(inter->tx = malloc(sizeof(sfTexture **) * (12 + 1))))
        return (NULL);
    if (!(inter->text = malloc(sizeof(char ***) * (12 + 1))))
        return (NULL);
    for (int i = 0; i < 12 + 1; ++i) {
        inter->id_max[i] = -1;
        inter->sprites[i] = NULL;
        inter->tx[i] = NULL;
        inter->text[i] = NULL;
    }
    return (inter);
}

void init_interactions(col_t *col)
{
    json_t *parsed;

    col->inter = malloc_interactions();
    parsed = return_parsed_json("./res/inter/inter_debug.json");
    fetch_infos((void **)&parsed, &col->inter, 0);
}
