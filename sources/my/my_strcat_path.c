/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat_path(char const *begin, char const *end)
{
    unsigned int i = 0;
    char *s;

    if (!(s = malloc(sizeof(char) * (my_strlen(begin) + my_strlen(end) + 2))))
        return (NULL);
    for (; begin[i] != '\0'; ++i)
        s[i] = begin[i];
    s[i] = '/';
    ++i;
    for (unsigned int j = 0; end[j] != '\0'; ++j) {
        s[i] = end[j];
        ++i;
    }
    s[i] = '\0';
    return (s);
}
