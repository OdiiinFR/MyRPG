/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** mooving
*/

#include "main.h"

void find_drop2(main_t *main, inventory_t *inv, sfVector2f w)
{
    if (w.x > 868 && w.x < 1163 && w.y > 336 && w.y < 467 &&
        inv->list[0][0].name == NULL)
        apply_change(main, inv, 0, 0);
    if (w.x > 868 && w.x < 1163 && w.y > 486 && w.y < 603 &&
        inv->list[0][1].name == NULL)
        apply_change(main, inv, 0, 1);
    if (w.x > 868 && w.x < 1163 && w.y > 621 && w.y < 738 &&
        inv->list[0][2].name == NULL)
        apply_change(main, inv, 0, 2);
    if (w.x > 868 && w.x < 1163 && w.y > 755 && w.y < 873 &&
        inv->list[0][3].name == NULL)
        apply_change(main, inv, 0, 3);
    if (w.x > 868 && w.x < 1163 && w.y > 890 && w.y < 1007 &&
        inv->list[0][4].name == NULL)
        apply_change(main, inv, 0, 4);
    if (w.x > 1181 && w.x < 1509 && w.y > 336 && w.y < 467 &&
        inv->list[1][0].name == NULL)
        apply_change(main, inv, 1, 0);
    return find_drop3(main, inv, w);
}

void find_drop(main_t *main, inventory_t *inv, sfVector2f w)
{
    sfVector2f pos1 = {390, 915};
    sfVector2f pos2 = {520, 915};
    sfVector2f pos3 = {635, 915};
    sfVector2f pos4 = {775, 915};

    if (w.x > 356 && w.x < 472 && w.y > 890 && w.y < 1007 &&
        inv->equiped[0][0].name == NULL)
        apply_changev2(main, inv, pos1, 0);
    if (w.x > 490 && w.x < 593 && w.y > 890 && w.y < 1007 &&
        inv->equiped[0][1].name == NULL)
        apply_changev2(main, inv, pos2, 1);
    if (w.x > 611 && w.x < 714 && w.y > 890 && w.y < 1007 &&
        inv->equiped[0][2].name == NULL)
        apply_changev2(main, inv, pos3, 2);
    if (w.x > 732 && w.x < 848 && w.y > 890 && w.y < 1007 &&
        inv->equiped[0][3].name == NULL) {
        apply_changev2(main, inv, pos4, 3);
    }
    return find_drop2(main, inv, w);
}

void drop(main_t *main, inventory_t *inv, sfVector2f w)
{
    if (main->drag != -1) {
        main->moove = sfSprite_copy(main->inv->list[0][main->drag].spr);
        sfSprite_setPosition(main->moove, w);
        sfRenderWindow_drawSprite(main->wind.window, main->moove, NULL);
        main->drop = w;
    }
    if (main->drag2 != -1) {
        main->moove = sfSprite_copy(main->inv->list[1][main->drag2].spr);
        sfSprite_setPosition(main->moove, w);
        sfRenderWindow_drawSprite(main->wind.window, main->moove, NULL);
        main->drop = w;
    }
    if (main->drag3 != -1 && inv->equiped[0][main->drag3].name != NULL) {
        main->moove = sfSprite_copy(main->inv->equiped[0][main->drag3].spr);
        sfSprite_setPosition(main->moove, w);
        sfRenderWindow_drawSprite(main->wind.window, main->moove, NULL);
        main->drop = w;
    }
    return;
}

void find_case3(sfVector2f w, main_t *main)
{
    if (w.x > 1181 && w.x < 1509 && w.y > 486 && w.y < 603 &&
        main->inv->list[1][1].name != NULL)
        main->drag2 = 1;
    if (w.x > 1181 && w.x < 1509 && w.y > 621 && w.y < 738 &&
        main->inv->list[1][2].name != NULL)
        main->drag2 = 2;
    return;
}

void find_case2(sfVector2f w, main_t *main)
{
    if (w.x > 1181 && w.x < 1509 && w.y > 755 && w.y < 873 &&
        main->inv->list[1][3].name != NULL)
        main->drag2 = 3;
    if (w.x > 1181 && w.x < 1509 && w.y > 890 && w.y < 1007 &&
        main->inv->list[1][4].name != NULL)
        main->drag2 = 4;
    if (w.x > 356 && w.x < 472 && w.y > 890 && w.y < 1007 &&
        main->drag2 == -1 && main->drag == -1)
        main->drag3 = 0;
    if (w.x > 490 && w.x < 593 && w.y > 890 && w.y < 1007 &&
        main->drag2 == -1 && main->drag == -1)
        main->drag3 = 1;
    if (w.x > 611 && w.x < 714 && w.y > 890 && w.y < 1007 &&
        main->drag2 == -1 && main->drag == -1)
        main->drag3 = 2;
    if (w.x > 732 && w.x < 848 && w.y > 890 && w.y < 1007 &&
        main->drag2 == -1 && main->drag == -1)
        main->drag3 = 3;
    return find_case3(w, main);
}
