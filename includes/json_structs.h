/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Manages structures used to parse the JSON.
*/

#ifndef JSON_STRUCTS_H_
    #define JSON_STRUCTS_H_
    #include <stdio.h>

typedef struct json {
    int type;
    int ind;
    void **value;
} json_t;

typedef struct infos {
    char *ptr;
    char *line;
    FILE *srm;
    short in_obj;
} infos_t;

#endif /* !JSON_STRUCTS_H_ */
