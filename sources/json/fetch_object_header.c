/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** JSON Parser: Object Header Handling.
*/

#include "my.h"
#include "json_structs.h"
#include "json_parser.h"

static int choose_fetched(infos_t **infos, int choice, void **to_fetch)
{
    if (choice == 0) {
        if (!parse_number(&(*infos)->ptr, to_fetch))
            return (84);
    } else {
        if (parse_array(infos, (json_t **)to_fetch))
            return (84);
    }
    if ((*infos)->ptr[0] != ',')
        return (84);
    ++(*infos)->ptr;
    return (0);
}

static int fetch_infos_header(infos_t **infos, \
char const *fieldname, short choice, void **to_fetch)
{
    char *str = NULL;

    if (parse_whitespace(*infos))
        return (84);
    if (parse_string(*infos, &str))
        return (84);
    if (!my_strcmp_header(str, fieldname))
        return (84);
    if (parse_whitespace(*infos))
        return (84);
    if ((*infos)->ptr[0] != ':')
        return (84);
    ++(*infos)->ptr;
    if (parse_whitespace(*infos))
        return (84);
    if (choose_fetched(infos, choice, to_fetch))
        return (84);
    return (0);
}

short check_good_formating(infos_t **infos, json_t **array)
{
    void *size = NULL;

    if (!(*array)) {
        if (!((*array) = init_array()))
            return (84);
    }
    if (fetch_infos_header(infos, "size", 0, &size))
        return (84);
    if (!((*array)->value = malloc(sizeof(void *) * ((long)size + 3))))
        return (84);
    for (int i = 0; i < (long)size + 3; ++i)
        (*array)->value[i] = NULL;
    (*array)->value[0] = size;
    ++(*array)->ind;
    return (0);
}

static int force_init(json_t **array)
{
    if (array == NULL)
        return (84);
    if (!(*array)) {
        if (!((*array) = init_array()))
            return (84);
    }
    return (0);
}

short check_good_formating_array(infos_t **infos, json_t **array)
{
    void *size = NULL;

    if (force_init(array))
        return (84);
    if (parse_whitespace(*infos))
        return (84);
    parse_number(&(*infos)->ptr, &size);
    if ((*infos)->ptr[0] != ',')
        return (84);
    ++(*infos)->ptr;
    if (parse_whitespace(*infos))
        return (84);
    if (!((*array)->value = malloc(sizeof(void *) * ((long)size + 3))))
        return (84);
    for (int i = 0; i < (long)size + 3; ++i)
        (*array)->value[i] = NULL;
    (*array)->value[0] = size;
    ++(*array)->ind;
    return (0);
}
