/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** apply
*/

#include "main.h"

static void reset_stats3(main_t *m)
{
    m->skt->skt7->skt->in_fonction = 0;
    m->skt->skt8->skt->in_fonction = 0;
    m->skt->skt9->skt->in_fonction = 0;
    return;
}

static void reset_stats2(main_t *m)
{
    sfSprite_setPosition(m->quests->qst1->Sprite, m->quests->qst1->position);
    sfSprite_setPosition(m->quests->qst1->Sprite, m->quests->qst2->position);
    sfSprite_setPosition(m->quests->qst1->Sprite, m->quests->qst3->position);
    sfSprite_setPosition(m->quests->qst1->Sprite, m->quests->qst4->position);
    sfSprite_setPosition(m->quests->qst1->Sprite, m->quests->qst5->position);
    m->skt->skt1->skt->in_fonction = 0;
    m->skt->skt2->skt->in_fonction = 0;
    m->skt->skt3->skt->in_fonction = 0;
    m->skt->skt4->skt->in_fonction = 0;
    m->skt->skt5->skt->in_fonction = 0;
    m->skt->skt6->skt->in_fonction = 0;
    m->quests->qst5->position.x = 720;
    for (int i = 0; i < 2; i += 1)
        for (int j = 0; j < 5; j += 1)
            m->inv->list[i][j].name = NULL;
    for (int i = 1; i < 3; i += 1)
        m->inv->stats[i].stat = 10;
    m->inv->stats[0].stat = 100;
    sfSprite_setPosition(m->player->sp_player, (sfVector2f){450, 20});
    return reset_stats3(m);
}

void reset_stats(main_t *main)
{
    main->money = 1000;
    main->lang = 0;
    main->player->zone = 1;
    main->sounds->vol_music = 50;
    main->sounds->vol_sounds = 50;
    main->config->keys[0]->key = 25;
    main->config->keys[1]->key = 3;
    main->config->keys[2]->key = 18;
    main->config->keys[3]->key = 16;
    main->config->keys[4]->key = 36;
    main->config->keys[5]->key = 8;
    main->config->keys[6]->key = 19;
    main->config->keys[7]->key = 11;
    main->quests->qst1->position.x = 430;
    main->quests->qst2->position.x = 650;
    main->quests->qst3->position.x = 570;
    main->quests->qst4->position.x = 440;
    for (int i = 0; i < 4; i += 1)
        main->inv->equiped[0][i].name = NULL;
    return reset_stats2(main);
}

static void equipped_add(main_t *main, int ref, inventory_t *inv, int i)
{
    inv->equiped[0][i].mod = main->inv->all[ref]->mod;
    inv->equiped[0][i].equip = main->inv->all[ref]->equip;
    inv->equiped[0][i].name = main->inv->all[ref]->name;
    inv->equiped[0][i].nb = 1;
    inv->equiped[0][i].print_name = main->inv->all[ref]->print_name;
    inv->equiped[0][i].print_nb = main->inv->all[ref]->print_nb;
    inv->equiped[0][i].reference = main->inv->all[ref]->reference;
    inv->equiped[0][i].spr = main->inv->all[ref]->spr;
    inv->equiped[0][i].texture = main->inv->all[ref]->texture;
    inv->equiped[0][i].type = main->inv->all[ref]->type;
    sfSprite_setPosition(inv->equiped[0][i].spr, inv->equiped[0][i].pos_spr);
}

void open_and_apply5(main_t *m, FILE *fd, char *line, size_t len)
{
    char str[3];
    getline(&line, &len, fd);
    for (int i = 0, nb = 0; i < 4; i += 1) {
        if (line[nb] == '1' && line[nb + 1] != '0') {
            equipped_add(m, (line[nb] - 48), m->inv, i);
            nb += 2;
        } else {
            nb += 4;
        }
    }
    getline(&line, &len, fd);
    for (int i = 0, a = 0, nb = 0; a < 3; a += 1) {
        for (nb = 0; line[i] != ' ' && line[i] != '\0'; nb += 1, i += 1)
            str[nb] = line[i];
        m->inv->stats[a].stat = my_atoi(str);
        for (nb -= 1; nb >= 0; nb -= 1)
            str[nb] = '\0';
        for (; line[i] == ' '; i += 1);
    }
    return open_and_apply6(m, fd, line, len);
}
