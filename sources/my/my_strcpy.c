/*
** EPITECH PROJECT, 2021
** my_str_cpy
** File description:
** copy a str
*/

#include "main.h"

char *my_strcat(char *dest, char *src)
{
    int len1 = my_strlen(dest);
    int len2 = my_strlen(src);
    char *str = malloc(sizeof(char) * (len1 + len2 + 1));
    int ctr = 0;
    int ctr2 = 0;

    while (dest[ctr] != '\0') {
        str[ctr] = dest[ctr];
        ctr = ctr + 1;
    }
    while (src[ctr2] != '\0') {
        str[ctr + ctr2] = src[ctr2];
        ctr2 = ctr2 + 1;
    }
    str[len1 + len2] = '\0';
    return str;
}

char *my_strcpy(char *dest, char const *src)
{
    int ctr = 0;

    while (src[ctr] != '\0') {
        dest[ctr] = src[ctr];
        ctr = ctr + 1;
    }
    dest[ctr] = '\0';
    return (dest);
}

char *mystrdup(char *str)
{
    int len = my_strlen(str);
    char *dup = malloc(sizeof(char) * (len + 1));

    dup = my_strcpy(dup, str);
    return dup;
}

char *my_itoa(int nb)
{
    char *new;
    int cpy = nb;
    int lock = 0;
    int tmp = 0;

    for (lock = 0; cpy > 0; lock += 1)
        cpy = cpy / 10;
    if (nb == 0)
        lock = 1;
    new = malloc(sizeof(char) * (lock + 1));
    new[lock] = '\0';
    for (int i = (lock - 1); i >= 0; i -= 1) {
        tmp = nb % 10;
        nb = nb / 10;
        new[i] = (tmp + 48);
    }
    return new;
}

int my_atoi(char *str)
{
    int i = 0;
    int result = 0;

    while (str[i]) {
        if (str[i] > 47 && str[i] < 58)
            result = result * 10 + (str[i] - 48);
        i++;
    }
    return (result);
}
