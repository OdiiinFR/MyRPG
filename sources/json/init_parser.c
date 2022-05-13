/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** JSON Parsing: Initialisation.
*/

#include <dirent.h>
#include <stdlib.h>
#include "json_parser.h"
#include "json_structs.h"

infos_t *init_infos(void)
{
    infos_t *infos;

    if (!(infos = malloc(sizeof(infos_t))))
        return (NULL);
    infos->line = NULL;
    infos->ptr = NULL;
    infos->srm = NULL;
    infos->in_obj = 1;
    return (infos);
}

json_t *init_array(void)
{
    json_t *array;

    if (!(array = malloc(sizeof(json_t))))
        return (NULL);
    array->type = -1;
    array->ind = 0;
    array->value = NULL;
    return (array);
}
