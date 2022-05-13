/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int strcompare(char *str1, char *str2);
int strncompare(char *str1, char *str2, int n);
char *mystrdup(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char *src);
char *my_itoa(int nb);
char *my_strcat_path(char const *begin, char const *end);
int my_strcmp_header(char *s1, char const *s2);
int my_strcmp_bool(char const *s1, char const *s2);
int my_atoi(char *str);

#endif /* !MY_H_ */
