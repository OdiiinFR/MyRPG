/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** JSON Parsing: String
*/

#include "json_parser.h"
#include "json_structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int parse_string(infos_t *infos, char **str)
{
    char *parsed_string;
    unsigned int i;
    unsigned int j = 0;

    if (infos->ptr[0] != '\"')
        return (84);
    ++infos->ptr;
    for (i = 0; infos->ptr[i] != '\"' && infos->ptr[i] != '\0'; ++i);
    if (!(parsed_string = malloc(sizeof(char) * (i + 1))))
        return (84);
    for (; infos->ptr[0] != '\"' && infos->ptr[0] != '\0'; ++j, ++infos->ptr)
        parsed_string[j] = infos->ptr[0];
    parsed_string[i] = '\0';
    if (infos->ptr[0] != '\"')
        return (84);
    ++infos->ptr;
    *str = parsed_string;
    return (0);
}
