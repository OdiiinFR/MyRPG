/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** modifier
*/

#include "main.h"

void find_type2(main_t *main, char *mod, int x, int y)
{
    sfVector2f pos1 = {800, 255};
    sfVector2f pos2 = {1040, 255};
    sfVector2f pos3 = {1300, 255};
    char *str;

    if (strcompare(main->inv->equiped[x][y].type, "Attack\0") == 0)
        sfText_setPosition(main->modifier, pos2);
    if (strcompare(main->inv->equiped[x][y].type, "Defence\0") == 0)
        sfText_setPosition(main->modifier, pos3);
    if (strcompare(main->inv->equiped[x][y].type, "Healing\0") == 0)
        sfText_setPosition(main->modifier, pos1);
    str = my_strcat(mod, my_itoa(main->inv->equiped[x][y].mod));
    sfText_setString(main->modifier, str);
    sfRenderWindow_drawText(main->wind.window, main->modifier, NULL);
}

void find_type(main_t *main, char *mod, int x, int y)
{
    sfVector2f pos1 = {800, 255};
    sfVector2f pos2 = {1040, 255};
    sfVector2f pos3 = {1300, 255};
    char *str;

    str = my_strcat(mod, my_itoa(main->inv->list[x][y].mod));
    sfText_setString(main->modifier, str);
    if (strcompare(main->inv->list[x][y].type, "Attack\0") == 0) {
        sfText_setPosition(main->modifier, pos2);
        sfRenderWindow_drawText(main->wind.window, main->modifier, NULL);
    }
    if (strcompare(main->inv->list[x][y].type, "Defence\0") == 0) {
        sfText_setPosition(main->modifier, pos3);
        sfRenderWindow_drawText(main->wind.window, main->modifier, NULL);
    }
    if (strcompare(main->inv->list[x][y].type, "Healing\0") == 0) {
        sfText_setPosition(main->modifier, pos1);
        sfRenderWindow_drawText(main->wind.window, main->modifier, NULL);
    }
}

void modifier(main_t *main, inventory_t *inv)
{
    if (main->drag != -1 &&
        (strcompare(inv->list[0][main->drag].type, "type\0")) != 0)
        find_type(main, "+", 0, main->drag);
    if (main->drag2 != -1 &&
        (strcompare(inv->list[1][main->drag2].type, "type\0")) != 0)
        find_type(main, "+", 1, main->drag2);
    if (main->drag3 != -1 &&
        (strcompare(inv->equiped[0][main->drag3].type, "type\0")) != 0)
        find_type2(main, "-", 0, main->drag3);
    return;
}
