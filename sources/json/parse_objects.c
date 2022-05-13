/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** JSON Parser: Objects
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "json_structs.h"
#include "json_parser.h"

static int ignore_string(infos_t *infos)
{
    if (infos->ptr[0] != '\"')
        return (84);
    ++infos->ptr;
    for (; infos->ptr[0] != '\"'; ++infos->ptr);
    if (infos->ptr[0] != '\"')
        return (84);
    ++infos->ptr;
    return (0);
}

short parse_object(infos_t **infos, json_t **array)
{
    ++(*infos)->in_obj;
    parse_whitespace(*infos);
    ignore_string(*infos);
    parse_whitespace(*infos);
    if ((*infos)->ptr[0] != ':')
        return (84);
    ++((*infos)->ptr);
    parse_value(infos, (json_t **)&((*array)->value[(*array)->ind]));
    parse_whitespace(*infos);
    if ((*infos)->ptr[0] == ',') {
        ++(*infos)->ptr;
        ++(*array)->ind;
        parse_object(infos, array);
    } else if ((*infos)->ptr[0] == '}') {
        ++(*infos)->ptr;
        --(*infos)->in_obj;
    } else
        return (84);
    return (0);
}
