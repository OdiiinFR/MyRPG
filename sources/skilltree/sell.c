/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** sell
*/

#include "main.h"

void do_skilltree(main_t *m)
{
    sfRenderWindow_drawSprite(m->wind.window, m->play->Sprit_back, NULL);
    sfRenderWindow_drawSprite(m->wind.window, m->skt->spr, NULL);
    sfRenderWindow_drawText(m->wind.window, m->skt->skilltree, NULL);
    sfRenderWindow_drawText(m->wind.window, m->skt->description, NULL);
    sfRenderWindow_drawText(m->wind.window, m->skt->desc, NULL);
    sfRenderWindow_drawText(m->wind.window, m->skt->money, NULL);
    btn_action(m->skt->skt1->skt, m);
    btn_action(m->skt->skt2->skt, m);
    btn_action(m->skt->skt3->skt, m);
    btn_action(m->skt->skt4->skt, m);
    btn_action(m->skt->skt5->skt, m);
    btn_action(m->skt->skt6->skt, m);
    btn_action(m->skt->skt7->skt, m);
    btn_action(m->skt->skt8->skt, m);
    btn_action(m->skt->skt9->skt, m);
}

static int check_sell3(button_t *btn, main_t *main)
{
    if (btn->function == 41 && main->skt->skt2->skt->in_fonction == 0 &&
        main->skt->skt4->skt->in_fonction == 0) {
        main->money += main->skt->skt1->bought;
        return 0;
    }
    return 1;
}

static int check_sell2(button_t *btn, main_t *main)
{
    if (btn->function == 47 && main->skt->skt8->skt->in_fonction == 0) {
        main->money += main->skt->skt7->bought;
        return 0;
    }
    if (btn->function == 45 && main->skt->skt6->skt->in_fonction == 0 &&
        main->skt->skt8->skt->in_fonction == 0) {
        main->money += main->skt->skt5->bought;
        return 0;
    }
    if (btn->function == 44 && main->skt->skt7->skt->in_fonction == 0 &&
        main->skt->skt5->skt->in_fonction == 0) {
        main->money += main->skt->skt4->bought;
        return 0;
    }
    if (btn->function == 42 && main->skt->skt3->skt->in_fonction == 0 &&
        main->skt->skt5->skt->in_fonction == 0) {
        main->money += main->skt->skt2->bought;
        return 0;
    }
    return check_sell3(btn, main);
}

int check_sell(button_t *btn, main_t *main)
{
    main->event = 0;
    if (btn->function == 49) {
        main->money += main->skt->skt9->bought;
        return 0;
    }
    if (btn->function == 46) {
        main->money += main->skt->skt6->bought;
        return 0;
    }
    if (btn->function == 43) {
        main->money += main->skt->skt3->bought;
        return 0;
    }
    if (btn->function == 48 && main->skt->skt9->skt->in_fonction == 0) {
        main->money += main->skt->skt9->bought;
        return 0;
    }
    return check_sell2(btn, main);
}
