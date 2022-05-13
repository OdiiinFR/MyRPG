/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** JSON Parsing: Value
*/

#include <stdbool.h>
#include "json_structs.h"
#include "json_parser.h"
#include "my.h"

static void test_for_bool(infos_t **infos, json_t **array)
{
    if (my_strcmp_bool((*infos)->line, "true")) {
        *(short *)(*array) = 2;
        (*array)->type = 0;
        (*infos)->ptr += 4;
    }
    if (my_strcmp_bool((*infos)->line, "false")) {
        *(short *)(*array) = 1;
        (*array)->type = 0;
        (*infos)->ptr += 5;
    }
    if (my_strcmp_bool((*infos)->line, "null")) {
        (*array) = NULL;
        (*array)->type = 0;
        (*infos)->ptr += 4;
    }
}

static int fetch_recursively(infos_t **infos, json_t **array)
{
    if ((*infos)->ptr[0] == '[') {
        ++(*infos)->ptr;
        check_good_formating_array(infos, array);
        (*array)->type = 6;
        if (parse_array(infos, array))
            return (84);
    }
    if ((*infos)->ptr[0] == '{') {
        ++(*infos)->ptr;
        check_good_formating(infos, array);
        (*array)->type = 5;
        if (parse_object(infos, array))
            return (84);
    }
    return (0);
}

static int fetch_most_important(infos_t **infos, json_t **array)
{
    if (parse_whitespace(*infos))
        return (84);
    if (fetch_recursively(infos, array))
        return (84);
    if ((*infos)->ptr[0] == '\"') {
        if (parse_string(*infos, (char **)array))
            return (84);
    }
    if ((*infos)->ptr[0] >= '0' && (*infos)->ptr[0] <= '9')
        parse_number(&(*infos)->ptr, (void **)array);
    return (0);
}

int parse_value(infos_t **infos, json_t **array)
{
    if (fetch_most_important(infos, array))
        return (84);
    test_for_bool(infos, array);
    if (parse_whitespace(*infos))
        return (84);
    return (0);
}
