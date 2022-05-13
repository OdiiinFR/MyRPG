/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** main
*/

#include "main.h"

int usage(void)
{
    my_putstr("USAGE:\n  ./my_rpg:\nRPG create with CSFML library\n");
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 1) {
        if (strcompare("-h", argv[1]) == 0)
            return usage();
    }
    return set_window();
}
