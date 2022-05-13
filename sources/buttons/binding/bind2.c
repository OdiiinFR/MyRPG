/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** bind2
*/

#include "main.h"

my_key_t *new_key(char *name, sfKeyCode key, float x, float y)
{
    my_key_t *new = malloc(sizeof(my_key_t));
    sfVector2f scale = {1, 1};
    char str[2] = "A\0";
    char escape[8] = "Escape\0";

    new->key = key;
    new->name = name;
    str[0] = (key + 65);
    new->text = btn_text(str, x, y, scale);
    if (key == sfKeyEscape)
        sfText_setString(new->text, escape);
    key_to_txt(new);
    return new;
}

my_key_t **set_keys(void)
{
    my_key_t **new = malloc(sizeof(my_key_t *) * 9);

    new[0] = new_key("Up\0", sfKeyZ, 300, 450);
    new[1] = new_key("Right\0", sfKeyD, 500, 650);
    new[2] = new_key("Down\0", sfKeyS, 300, 850);
    new[3] = new_key("Left\0", sfKeyQ, 100, 650);
    new[4] = new_key("Pause\0", sfKeyEscape, 1100, 320);
    new[5] = new_key("Inventory\0", sfKeyI, 1100, 520);
    new[6] = new_key("Skill tree\0", sfKeyT, 1100, 720);
    new[7] = new_key("Quests\0", sfKeyL, 1100, 920);
    new[8] = NULL;
    return new;
}

keys_t *set_up_keys(void)
{
    keys_t *new = malloc(sizeof(keys_t));

    new->keys = set_keys();
    return new;
}
