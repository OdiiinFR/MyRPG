/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** Compares two strings.
*/

int my_strcmp_bool(char const *s1, char const *s2)
{
    int i = 0;
    char c1 = s1[0];
    char c2 = s2[0];

    if (c2 == 0 || c1 == 32 || c1 == 9 || c1 == 13 || c1 == 10 || c1 == 0)
        return (0);
    while (c2 != '\0' && c1 != ',' && c1 != '\n' && c1 != '\0') {
        if (c1 != c2)
            return (0);
        ++i;
        c1 = s1[i];
        c2 = s2[i];
    }
    return (1);
}
