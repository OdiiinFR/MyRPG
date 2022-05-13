/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** inventory
*/

#include "main.h"

static skills_t *create_skill(char *name, sfVector3f pos, int type)
{
    skills_t *new = malloc(sizeof(*new));
    sfVector3f sk = {pos.x, pos.y, 2};
    int buy = pos.z;

    new->skt = new_button(name, sk, 0, type);
    new->bought = buy;
    return new;
}

static skilltree_t *create_skilltree2(skilltree_t *new)
{
    sfVector3f skt6 = {838, 700, 10};
    sfVector3f skt7 = {1250, 160, 10};
    sfVector3f skt8 = {1250, 435, 10};
    sfVector3f skt9 = {1250, 700, 10};
    sfVector2f scale = {0.7, 0.7};
    sfVector2f scale2 = {0.5, 0.5};

    new->skt6 = create_skill(DESC6, skt6, 46);
    new->skt7 = create_skill(DESC7, skt7, 47);
    new->skt8 = create_skill(DESC8, skt8, 48);
    new->skt9 = create_skill(DESC9, skt9, 49);
    new->desc = btn_text("Description :\0", 365, 855, scale);
    new->description = btn_text(" \0", 360, 910, scale2);
    new->money = btn_text(my_strcat(my_itoa(0), " tickets"), 1150, 40, scale);
    return new;
}

skilltree_t *create_skilltree(void)
{
    skilltree_t *new = malloc(sizeof(*new));
    sfVector2f title = {1, 1};
    sfVector2f pos = {190, -205};
    sfVector3f skt1 = {435, 160, 10};
    sfVector3f skt2 = {435, 435, 10};
    sfVector3f skt3 = {435, 700, 10};
    sfVector3f skt4 = {838, 160, 10};
    sfVector3f skt5 = {838, 435, 10};

    new->skilltree = btn_text("Skilltree", 780, 35, title);
    new->spr = sfSprite_create();
    new->texture = sfTexture_createFromFile(SKT, NULL);
    sfSprite_setTexture(new->spr, new->texture, sfFalse);
    sfSprite_setPosition(new->spr, pos);
    new->skt1 = create_skill(DESC1, skt1, 41);
    new->skt2 = create_skill(DESC2, skt2, 42);
    new->skt3 = create_skill(DESC3, skt3, 43);
    new->skt4 = create_skill(DESC4, skt4, 44);
    new->skt5 = create_skill(DESC5, skt5, 45);
    return create_skilltree2(new);
}
