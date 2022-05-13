/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** delete
*/

#include "main.h"

void destroy(object_t *obj)
{
    obj->name = NULL;
    obj->type = NULL;
    obj->nb = 0;
    obj->reference = 100;
    return;
}

void check_stats(object_t *obj, inventory_t *inv, int flag)
{
    int add = 10;

    if (flag == 1)
        add = -10;
    if (strcompare(obj->type, "Healing\0") == 0) {
        inv->stats[0].stat += add;
        sfText_setString(inv->stats[0].print, my_itoa(inv->stats[0].stat));
    }
    if (strcompare(obj->type, "Attack\0") == 0) {
        inv->stats[1].stat += add;
        sfText_setString(inv->stats[1].print, my_itoa(inv->stats[1].stat));
    }
    if (strcompare(obj->type, "Defence\0") == 0) {
        inv->stats[2].stat += add;
        sfText_setString(inv->stats[2].print, my_itoa(inv->stats[2].stat));
    }
}

void apply_changev2(main_t *main, inventory_t *inv, sfVector2f pos, int y)
{
    if (main->drag != -1 && inv->list[0][main->drag].equip == sfTrue) {
        if (strcompare("Healing", inv->list[0][main->drag].type) == 0) {
            if (inv->list[0][main->drag].nb > 1) {
                inv->list[0][main->drag].nb -= 1;
                sfText_setString(inv->list[0][main->drag].print_nb, my_itoa(inv->list[0][main->drag].nb));
                check_stats(&inv->list[0][main->drag], inv, 0);
            } else {
                check_stats(&inv->list[0][main->drag], inv, 0);
                destroy(&inv->list[0][main->drag]);
            }
            return;
        }
        inv->equiped[0][y] = inv->list[0][main->drag];
        if (inv->list[0][main->drag].nb > 1) {
            inv->list[0][main->drag].nb -= 1;
            sfText_setString(inv->list[0][main->drag].print_nb, my_itoa(inv->list[0][main->drag].nb));
            check_stats(&inv->equiped[0][y], inv, 0);
        } else {
            destroy(&inv->list[0][main->drag]);
            sfSprite_setPosition(inv->equiped[0][y].spr, pos);
            check_stats(&inv->equiped[0][y], inv, 0);
        }
    }
    if (main->drag2 != -1 && inv->list[1][main->drag2].equip == sfTrue) {
        if (strcompare("Healing", inv->list[1][main->drag2].type) == 0) {
            if (inv->list[1][main->drag2].nb > 1) {
                inv->list[0][main->drag].nb -= 1;
                sfText_setString(inv->list[1][main->drag2].print_nb, my_itoa(inv->list[1][main->drag2].nb));
                check_stats(&inv->list[1][main->drag2], inv, 0);
            } else {
                destroy(&inv->list[1][main->drag2]);
                sfSprite_setPosition(inv->equiped[0][y].spr, pos);
                check_stats(&inv->list[1][main->drag2], inv, 0);
            }
            return;
        }
        inv->equiped[0][y] = inv->list[1][main->drag2];
        if (inv->list[1][main->drag2].nb > 1) {
            inv->list[0][main->drag].nb -= 1;
            sfText_setString(inv->list[1][main->drag2].print_nb, my_itoa(inv->list[1][main->drag2].nb));
            check_stats(&inv->equiped[0][y], inv, 0);
        } else {
            check_stats(&inv->equiped[0][y], inv, 0);
            destroy(&inv->list[1][main->drag2]);
        }
    }
}

void apply_change(main_t *main, inventory_t *inv, int x, int y)
{
    sfVector2f tmp = inv->list[x][y].pos_txt1;
    if (main->drag3 != -1) {
        inv->list[x][y] = inv->equiped[0][main->drag3];
        destroy(&inv->equiped[0][main->drag3]);
        check_stats(&inv->list[x][y], inv, 1);
    }
    if (main->drag != -1) {
        inv->list[x][y] = inv->list[0][main->drag];
        destroy(&inv->list[0][main->drag]);
    }
    if (main->drag2 != -1) {
        inv->list[x][y] = inv->list[1][main->drag2];
        destroy(&inv->list[1][main->drag2]);
    }
    if (main->drag3 != -1 || main->drag != -1 || main->drag2 != -1) {
        set_pos(inv->list, x, y);
        sfSprite_setPosition(inv->list[x][y].spr, inv->list[x][y].pos_spr);
        sfText_setPosition(inv->list[x][y].print_name, tmp);
        sfText_setPosition(inv->list[x][y].print_nb, inv->list[x][y].pos_txt2);
    }
}

void find_drop3(main_t *main, inventory_t *inv, sfVector2f w)
{
    if (w.x > 1181 && w.x < 1509 && w.y > 486 && w.y < 603 &&
        inv->list[1][1].name == NULL)
        apply_change(main, inv, 1, 1);
    if (w.x > 1181 && w.x < 1509 && w.y > 621 && w.y < 738 &&
        inv->list[1][2].name == NULL)
        apply_change(main, inv, 1, 2);
    if (w.x > 1181 && w.x < 1509 && w.y > 755 && w.y < 873 &&
        inv->list[1][3].name == NULL)
        apply_change(main, inv, 1, 3);
    if (w.x > 1181 && w.x < 1509 && w.y > 890 && w.y < 1007 &&
        inv->list[1][4].name == NULL)
        apply_change(main, inv, 1, 4);
    if (w.x < 330 || w.x > 1550 || w.y < 100 || w.y > 1020) {
        if (main->drag != -1)
            destroy(&inv->list[0][main->drag]);
        if (main->drag2 != -1)
            destroy(&inv->list[1][main->drag2]);
        if (main->drag3 != -1)
            destroy(&inv->equiped[0][main->drag3]);
    }
}
