/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** quests
*/

#include "main.h"

int *find_pos(int flag, main_t *main, sfVector2f pos)
{
    int *new = malloc(sizeof(int) * 4);
    sfVector2f scale = {2, 2};
    sfVector2f spr = {50, 50};

    if (flag == 1) {
        scale.x = 3;
        spr.y = 21;
        pos = main->quests->qst2->position;
    }
    if (flag == 4) {
        pos = main->quests->qst5->position;
        spr.y = 65;
    }
    new[0] = (pos.x - 1);
    new[1] = (pos.x + ((spr.x + 1) * scale.x));
    new[2] = (pos.y - 1);
    new[3] = (pos.y + ((spr.y + 1) * scale.x));
    return new;
}

static int is_on_btn(sfVector2f w, main_t *main)
{
    int *pos1 = find_pos(0, main, main->quests->qst1->position);
    int *pos2 = find_pos(1, main, main->quests->qst2->position);
    int *pos3 = find_pos(2, main, main->quests->qst3->position);
    int *pos4 = find_pos(3, main, main->quests->qst4->position);
    int *pos5 = find_pos(4, main, main->quests->qst5->position);

    if (w.x >= pos1[0] && w.x <= pos1[1] && w.y >= pos1[2] && w.y <= pos1[3])
        return 1;
    if (w.x >= pos2[0] && w.x <= pos2[1] && w.y >= pos2[2] && w.y <= pos2[3])
        return 1;
    if (w.x >= pos3[0] && w.x <= pos3[1] && w.y >= pos3[2] && w.y <= pos3[3])
        return 1;
    if (w.x >= pos4[0] && w.x <= pos4[1] && w.y >= pos4[2] && w.y <= pos4[3])
        return 1;
    if (w.x >= pos5[0] && w.x <= pos5[1] && w.y >= pos5[2] && w.y <= pos5[3])
        return 1;
    return 0;
}

void check_desc(button_t *btn, main_t *main, int flag)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));
    const char *str;

    if (flag == 0 && w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx) {
        str = sfText_getString(btn->texte);
        sfText_setString(main->quests->description, str);
    } else if (flag == 0 && is_on_btn(w, main) == 0) {
        sfText_setString(main->quests->description, " \0");
    }
}

quests_t *set_quests2(quests_t *new)
{
    sfVector2f scale = {0.7, 0.7};
    sfVector2f scale2 = {0.5, 0.5};

    new->desc = btn_text("Description :\0", 365, 855, scale);
    new->quest = btn_text("Primary quests\0", 440, 40, scale);
    new->done = btn_text("completed quests\0", 1000, 40, scale);
    new->second = btn_text("Side quests\0", 500, 600, scale);
    new->description = btn_text(" \0", 360, 910, scale2);
    return new;
}

quests_t *set_quests(void)
{
    quests_t *new = malloc(sizeof(*new));
    sfVector2f pos = {190, -205};
    sfVector3f qst1 = {430, 250, 2};
    sfVector3f qst2 = {650, 280, 3};
    sfVector3f qst3 = {570, 400, 2};
    sfVector3f qst4 = {440, 730, 2};
    sfVector3f qst5 = {720, 720, 2};

    new->spr = sfSprite_create();
    new->pos = pos;
    new->texture = sfTexture_createFromFile(QST, NULL);
    sfSprite_setTexture(new->spr, new->texture, sfFalse);
    sfSprite_setPosition(new->spr, new->pos);
    new->qst1 = new_button(QST1, qst1, 0, 36);
    new->qst2 = new_button(QST2, qst2, 0, 37);
    new->qst3 = new_button(QST3, qst3, 0, 38);
    new->qst4 = new_button(QST4, qst4, 0, 39);
    new->qst5 = new_button(QST5, qst5, 0, 40);
    return set_quests2(new);
}
