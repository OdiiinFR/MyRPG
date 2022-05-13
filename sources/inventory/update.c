/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** update
*/

#include "main.h"

void find_case(sfVector2f w, main_t *main)
{
    if (w.x > 868 && w.x < 1163 && w.y > 336 && w.y < 467 &&
        main->inv->list[0][0].name != NULL)
        main->drag = 0;
    if (w.x > 868 && w.x < 1163 && w.y > 486 && w.y < 603 &&
        main->inv->list[0][1].name != NULL)
        main->drag = 1;
    if (w.x > 868 && w.x < 1163 && w.y > 621 && w.y < 738 &&
        main->inv->list[0][2].name != NULL)
        main->drag = 2;
    if (w.x > 868 && w.x < 1163 && w.y > 755 && w.y < 873 &&
        main->inv->list[0][3].name != NULL)
        main->drag = 3;
    if (w.x > 868 && w.x < 1163 && w.y > 890 && w.y < 1007 &&
        main->inv->list[0][4].name != NULL)
        main->drag = 4;
    if (w.x > 1181 && w.x < 1509 && w.y > 336 && w.y < 467 &&
        main->inv->list[1][0].name != NULL)
        main->drag2 = 0;
    return find_case2(w, main);
}

void drag_drop(main_t *main, inventory_t *inv)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);

    if (main->drag2 == -1 && main->drag == -1 && main->drag3 == -1 &&
        main->event == 1) {
        find_case(w, main);
    } else {
        if (main->event == 1) {
            drop(main, inv, w);
            modifier(main, inv);
        } else {
            find_drop(main, inv, main->drop);
            main->drag2 = -1;
            main->drag = -1;
            main->drag3 = -1;
        }
    }
    find_status(main);
    sfRenderWindow_drawText(main->wind.window, inv->sort->status, NULL);
    sfRenderWindow_drawSprite(main->wind.window, inv->sort->spr, NULL);
}

void update_add(main_t *main, int ref, inventory_t *inv, int *new)
{
    object_t tmp;

    inv->list[new[0]][new[1]].mod = main->inv->all[ref]->mod;
    inv->list[new[0]][new[1]].equip = main->inv->all[ref]->equip;
    inv->list[new[0]][new[1]].name = main->inv->all[ref]->name;
    inv->list[new[0]][new[1]].nb = 1;
    inv->list[new[0]][new[1]].print_name = main->inv->all[ref]->print_name;
    inv->list[new[0]][new[1]].print_nb = main->inv->all[ref]->print_nb;
    inv->list[new[0]][new[1]].reference = main->inv->all[ref]->reference;
    inv->list[new[0]][new[1]].spr = main->inv->all[ref]->spr;
    inv->list[new[0]][new[1]].texture = main->inv->all[ref]->texture;
    inv->list[new[0]][new[1]].type = main->inv->all[ref]->type;
    tmp = inv->list[new[0]][new[1]];
    sfSprite_setPosition(inv->list[new[0]][new[1]].spr, tmp.pos_spr);
    sfText_setPosition(inv->list[new[0]][new[1]].print_name, tmp.pos_txt1);
    sfText_setPosition(inv->list[new[0]][new[1]].print_nb, tmp.pos_txt2);
    sfText_setString(inv->list[new[0]][new[1]].print_nb, my_itoa(tmp.nb));
}

int exist(int ref, inventory_t *inv, int *new, int j)
{
    object_t tmp;

    if (inv->list[new[0]][j].name != NULL) {
        if (inv->list[new[0]][j].name == inv->all[ref]->name) {
            inv->list[new[0]][j].nb += 1;
            tmp = inv->list[new[0]][j];
            sfText_setString(inv->list[new[0]][j].print_nb, my_itoa(tmp.nb));
            return -1;
        }
        new[1] = j + 1;
    }
    return 0;
}

void inv_add(main_t *main, int ref, inventory_t *inv)
{
    int new[2] = {0, 0};

    for (int j = 0; j < 5; j += 1)
        if (exist(ref, inv, new, j) == -1)
            return;
    if (new[1] >= 5) {
        new[0] = 1;
        new[1] = 0;
    }
    for (int j = 0; j < 5; j += 1)
        if (exist(ref, inv, new, j) == -1)
            return;
    if (new[1] >= 5)
        return;
    return update_add(main, ref, inv, new);
}
