/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** JSON Parsing: Whitespace
*/

#include "json_parser.h"
#include "json_structs.h"
#include <stdio.h>
#include <stdlib.h>

static int get_new_line(infos_t *infos)
{
    size_t nb = 0;

    if (infos->ptr[0] == '\0' && infos->in_obj > 0) {
        free(infos->line);
        if (getline(&infos->line, &nb, infos->srm) == -1)
            return (1);
        infos->ptr = infos->line;
    }
    return (0);
}

int parse_whitespace(infos_t *infos)
{
    char c = infos->ptr[0];

    while (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
        ++infos->ptr;
        if (get_new_line(infos))
            return (0);
        c = infos->ptr[0];
    }
    return (0);
}
