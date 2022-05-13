/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-anthony.faure
** File description:
** my_itoa
*/

#include <stdlib.h>

char *my_itoa(int nb)
{
    int len = 0;
    char *str;
    int tmp = nb;

    if (nb <= 0)
        return " 0\0";
    while (tmp > 0) {
        tmp = tmp / 10;
        len++;
    }
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = nb % 10 + '0';
        nb = nb / 10;
    }
    return (str);
}

int my_atoi(char *str)
{
    int i = 0;
    int result = 0;

    while (str[i]) {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    return (result);
}
