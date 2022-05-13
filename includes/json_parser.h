/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** JSON Parsing: Header
*/

#ifndef JSON_PARSER_H_
    #define JSON_PARSER_H_
    #include "json_structs.h"
    #include <stdio.h>
    #include <dirent.h>

json_t *return_parsed_json(char *folderpath);
short check_good_formating_array(infos_t **infos, json_t **array);
short check_good_formating(infos_t **infos, json_t **array);
int parse_whitespace(infos_t *infos);
int parse_string(infos_t *infos, char **str);
short parse_number(char **nb, void **parsed_number);
short parse_object(infos_t **infos, json_t **array);
int parse_value(infos_t **infos, json_t **array);
int parse_array(infos_t **infos, json_t **array);
json_t *init_array(void);
infos_t *init_infos(void);

#endif /* !JSON_PARSER_H_ */
