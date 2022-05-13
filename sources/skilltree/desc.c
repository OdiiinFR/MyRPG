/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** desc
*/

#include "main.h"

static int check_buy3(button_t *btn, main_t *main)
{
    if (btn->function == 48 && main->money >= main->skt->skt8->bought &&
        main->skt->skt7->skt->in_fonction == 1 &&
        main->skt->skt5->skt->in_fonction == 1) {
        main->money -= main->skt->skt9->bought;
        return 0;
    }
    if (btn->function == 49 && main->money >= main->skt->skt9->bought &&
        main->skt->skt8->skt->in_fonction == 1) {
        main->money -= main->skt->skt9->bought;
        return 0;
    }
    if (btn->function == 41 && main->money >= main->skt->skt1->bought) {
        main->money -= main->skt->skt1->bought;
        return 0;
    }
    return 1;
}

static int check_buy2(button_t *btn, main_t *main)
{
    if (btn->function == 45 && main->money >= main->skt->skt5->bought &&
        main->skt->skt4->skt->in_fonction == 1 &&
        main->skt->skt2->skt->in_fonction == 1) {
        main->money -= main->skt->skt5->bought;
        return 0;
    }
    if (btn->function == 46 && main->money >= main->skt->skt6->bought &&
        main->skt->skt5->skt->in_fonction == 1) {
        main->money -= main->skt->skt6->bought;
        return 0;
    }
    if (btn->function == 47 && main->money >= main->skt->skt7->bought &&
        main->skt->skt4->skt->in_fonction == 1) {
        main->money -= main->skt->skt7->bought;
        return 0;
    }
    return check_buy3(btn, main);
}

int check_buy(button_t *btn, main_t *main)
{
    main->event = 0;
    if (btn->function == 42 && main->money >= main->skt->skt2->bought &&
        main->skt->skt1->skt->in_fonction == 1) {
        main->money -= main->skt->skt2->bought;
        return 0;
    }
    if (btn->function == 43 && main->money >= main->skt->skt3->bought &&
        main->skt->skt2->skt->in_fonction == 1) {
        main->money -= main->skt->skt3->bought;
        return 0;
    }
    if (btn->function == 44 && main->money >= main->skt->skt4->bought &&
        main->skt->skt1->skt->in_fonction == 1) {
        main->money -= main->skt->skt4->bought;
        return 0;
    }
    return check_buy2(btn, main);
}
