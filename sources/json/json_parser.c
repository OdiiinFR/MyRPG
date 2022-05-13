/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Parses JSON files.
*/

#include <stddef.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include "json_structs.h"
#include "json_parser.h"
#include "my.h"

json_t *return_parsed_json(char *name)
{
    size_t n = 0;
    infos_t *infos;
    json_t *array;

    if (!(infos = init_infos()))
        return (NULL);
    if (!(array = init_array()))
        return (NULL);
    if (!(infos->srm = fopen(name, "r")))
        return (NULL);
    while (getline(&infos->line, &n, infos->srm) != -1) {
        infos->ptr = infos->line;
        if (parse_value(&infos, &array))
            return (NULL);
    }
    free(infos->line);
    if (fclose(infos->srm) == EOF)
        return (NULL);
    return (array);
}
