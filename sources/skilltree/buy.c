/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** buy
*/

#include "main.h"

static void set_in_funct(button_t *btn, main_t *main)
{
    if (btn->in_fonction == 0 && check_buy(btn, main) == 0)
        btn->in_fonction = 1;
    else if (btn->in_fonction == 1 && check_sell(btn, main) == 0)
        btn->in_fonction = 0;
}

static void skill_system2(button_t *btn, main_t *main)
{
    sfColor tmp = sfSprite_getColor(btn->Sprite);
    skilltree_t *tmp2 = main->skt;

    if (btn->in_fonction == 0) {
        tmp.a = 120;
        sfSprite_setColor(btn->Sprite, tmp);
    } else {
        tmp.a = 255;
        sfSprite_setColor(btn->Sprite, tmp);
    }
    sfText_setString(tmp2->money, my_strcat(my_itoa(main->money), " tickets"));
}

static int is_on_btn2(sfVector2f w, main_t *main)
{
    int *pos7 = find_pos(0, main, main->skt->skt7->skt->position);
    int *pos8 = find_pos(0, main, main->skt->skt8->skt->position);
    int *pos9 = find_pos(0, main, main->skt->skt9->skt->position);

    if (w.x >= pos7[0] && w.x <= pos7[1] && w.y >= pos7[2] && w.y <= pos7[3])
        return 1;
    if (w.x >= pos8[0] && w.x <= pos8[1] && w.y >= pos8[2] && w.y <= pos8[3])
        return 1;
    if (w.x >= pos9[0] && w.x <= pos9[1] && w.y >= pos9[2] && w.y <= pos9[3])
        return 1;
    return 0;
}

static int is_on_btn(sfVector2f w, main_t *main)
{
    int *pos1 = find_pos(0, main, main->skt->skt1->skt->position);
    int *pos2 = find_pos(0, main, main->skt->skt2->skt->position);
    int *pos3 = find_pos(0, main, main->skt->skt3->skt->position);
    int *pos4 = find_pos(0, main, main->skt->skt4->skt->position);
    int *pos5 = find_pos(0, main, main->skt->skt5->skt->position);
    int *pos6 = find_pos(0, main, main->skt->skt6->skt->position);

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
    if (w.x >= pos6[0] && w.x <= pos6[1] && w.y >= pos6[2] && w.y <= pos6[3])
        return 1;
    return is_on_btn2(w, main);
}

void skill_system(button_t *btn, main_t *main)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));
    const char *str = sfText_getString(btn->texte);

    if (main->event == 0 && w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx &&
        btn->in_fonction == 1)
        sfText_setString(main->skt->description, str);
    else if (main->event == 0 && is_on_btn(w, main) == 0)
        sfText_setString(main->skt->description, mystrdup(" \0"));
    if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx)
        set_in_funct(btn, main);
    return skill_system2(btn, main);
}
