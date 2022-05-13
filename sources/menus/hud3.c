/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** hud3
*/

#include "main.h"

static void apply_hud3(main_t *main)
{
    hud_menu_t *tmp = main->huds;

    if (main->skt->skt5->skt->in_fonction == 1)
        sfSprite_setTexture(tmp->hud_skt[4], tmp->txt_hud_skt[4], sfFalse);
    else
        sfSprite_setTexture(tmp->hud_skt[4], tmp->txt_hud_skt[9], sfFalse);
    if (main->skt->skt6->skt->in_fonction == 1)
        sfSprite_setTexture(tmp->hud_skt[5], tmp->txt_hud_skt[5], sfFalse);
    else
        sfSprite_setTexture(tmp->hud_skt[5], tmp->txt_hud_skt[9], sfFalse);
    if (main->skt->skt7->skt->in_fonction == 1)
        sfSprite_setTexture(tmp->hud_skt[6], tmp->txt_hud_skt[6], sfFalse);
    else
        sfSprite_setTexture(tmp->hud_skt[6], tmp->txt_hud_skt[9], sfFalse);
    if (main->skt->skt8->skt->in_fonction == 1)
        sfSprite_setTexture(tmp->hud_skt[7], tmp->txt_hud_skt[7], sfFalse);
    else
        sfSprite_setTexture(tmp->hud_skt[7], tmp->txt_hud_skt[9], sfFalse);
    return;
}

static void apply_hud2(main_t *main)
{
    hud_menu_t *tmp = main->huds;

    if (main->inv->status == 0)
        sfSprite_setTexture(tmp->hud_stat[3], tmp->txt_hud_stat[3], sfFalse);
    if (main->inv->status == 1)
        sfSprite_setTexture(tmp->hud_stat[3], tmp->txt_hud_stat[4], sfFalse);
    if (main->inv->status == 2)
        sfSprite_setTexture(tmp->hud_stat[3], tmp->txt_hud_stat[5], sfFalse);
    if (main->inv->status == 3)
        sfSprite_setTexture(tmp->hud_stat[3], tmp->txt_hud_stat[6], sfFalse);
    if (main->inv->status == 4)
        sfSprite_setTexture(tmp->hud_stat[3], tmp->txt_hud_stat[7], sfFalse);
    if (main->skt->skt9->skt->in_fonction == 1)
        sfSprite_setTexture(tmp->hud_skt[8], tmp->txt_hud_skt[8], sfFalse);
    else
        sfSprite_setTexture(tmp->hud_skt[8], tmp->txt_hud_skt[9], sfFalse);
    return apply_hud3(main);
}

void apply_hud(main_t *main)
{
    hud_menu_t *tmp = main->huds;

    if (main->skt->skt1->skt->in_fonction == 1)
        sfSprite_setTexture(tmp->hud_skt[0], tmp->txt_hud_skt[0], sfFalse);
    else
        sfSprite_setTexture(tmp->hud_skt[0], tmp->txt_hud_skt[9], sfFalse);
    if (main->skt->skt2->skt->in_fonction == 1)
        sfSprite_setTexture(tmp->hud_skt[1], tmp->txt_hud_skt[1], sfFalse);
    else
        sfSprite_setTexture(tmp->hud_skt[1], tmp->txt_hud_skt[9], sfFalse);
    if (main->skt->skt3->skt->in_fonction == 1)
        sfSprite_setTexture(tmp->hud_skt[2], tmp->txt_hud_skt[2], sfFalse);
    else
        sfSprite_setTexture(tmp->hud_skt[2], tmp->txt_hud_skt[9], sfFalse);
    if (main->skt->skt4->skt->in_fonction == 1)
        sfSprite_setTexture(tmp->hud_skt[3], tmp->txt_hud_skt[3], sfFalse);
    else
        sfSprite_setTexture(tmp->hud_skt[3], tmp->txt_hud_skt[9], sfFalse);
    return apply_hud2(main);
}
