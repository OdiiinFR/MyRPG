/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** JSON Parsing: Number
*/

#include <stdlib.h>
#include "my.h"

static int fetch_size(char **nb)
{
    int s = 0;
    char c = (*nb)[0];

    while (c != ',' && c != '\n' && c != ']' && c != '}') {
        ++s;
        c = (*nb)[s];
    }
    return (s);
}

static int fetch_int(char **nb)
{
    int s = fetch_size(nb);
    int res = 0;
    int neg = 1;
    int ten_pow = 1;
    int i;

    for (; ((*nb)[0] == '-' || (*nb)[0] == '+'); ++(*nb)) {
        if ((*nb)[0] == '-')
            neg *= -1;
    }
    for (i = 0; (*nb)[0] >= '0' && (*nb)[0] <= '9'; ++(*nb), ++i) {
        for (int j = 0; s - 1 - i > j; ++j)
            ten_pow *= 10;
        res += ((*nb)[0] - 48) * ten_pow;
        ten_pow = 1;
    }
    return (res * neg);
}

static unsigned short fetch_type(char *nb)
{
    unsigned int s;
    short frac = 0;

    for (s = 0; nb[s] != ',' && nb[s] != '\n' && nb[s] != '\0'; ++s) {
        if (nb[s] == '.')
            frac = 1;
        if (nb[s] == 'E' || nb[s] == 'e')
            frac = 2;
    }
    if (frac == 2)
        return (3);
    if (frac == 1)
        return (2);
    return (1);
}

short parse_number(char **nb, void **parsed_number)
{
    short type = 1;

    switch (fetch_type(*nb)) {
        case (1): *(long *)parsed_number = fetch_int(nb);
            break;
    }
    return (type);
}
