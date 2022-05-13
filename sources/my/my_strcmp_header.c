/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** Compares two strings.
*/

#include <stdlib.h>

int my_strcmp_header(char *s1, char const *s2)
{
    int i = 0;
    char c1 = s1[0];
    char c2 = s2[0];

    if (c2 == 0 || c1 == 0) {
        free(s1);
        return (0);
    }
    while (c2 != '\0' && c1 != '\0') {
        if (c1 != c2) {
            free(s1);
            return (0);
        }
        ++i;
        c1 = s1[i];
        c2 = s2[i];
    }
    free(s1);
    return (1);
}
