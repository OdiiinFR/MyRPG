/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** JSON Parser: Arrays
*/

#include "json_parser.h"
#include "json_structs.h"

int parse_array(infos_t **infos, json_t **array)
{
    ++(*infos)->in_obj;
    if (parse_whitespace(*infos))
        return (84);
    if (parse_value(infos, (json_t **)&(*array)->value[(*array)->ind]))
        return (84);
    if (parse_whitespace(*infos))
        return (84);
    if ((*infos)->ptr[0] == ',') {
        ++(*infos)->ptr;
        ++(*array)->ind;
        parse_array(infos, array);
    } else if ((*infos)->ptr[0] == ']') {
        ++(*infos)->ptr;
        --(*infos)->in_obj;
    } else
        return (84);
    return (0);
}
