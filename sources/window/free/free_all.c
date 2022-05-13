/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** free_all
*/

#include "main.h"

static void free_skilltree_h(main_t *main)
{
    sfSprite_destroy(main->skt->spr);
    sfTexture_destroy(main->skt->texture);
    free_button(main->skt->skt1->skt);
    free_button(main->skt->skt2->skt);
    free_button(main->skt->skt3->skt);
    free_button(main->skt->skt4->skt);
    free_button(main->skt->skt5->skt);
    free_button(main->skt->skt6->skt);
    free_button(main->skt->skt7->skt);
    free_button(main->skt->skt8->skt);
    free_button(main->skt->skt9->skt);
    sfText_destroy(main->skt->skilltree);
    sfText_destroy(main->skt->desc);
    sfText_destroy(main->skt->description);
    sfText_destroy(main->skt->money);
}

static void free_keys(main_t *main)
{
    for (int i = 0; main->config->keys[i] != NULL; i++) {
        sfText_destroy(main->config->keys[i]->text);
        free(main->config->keys[i]);
    }
    free(main->config);
    sfMusic_destroy(main->sounds->end);
    sfMusic_destroy(main->sounds->houses);
    sfMusic_destroy(main->sounds->outside);
    sfMusic_destroy(main->sounds->menu);
    sfMusic_destroy(main->sounds->tunnel);
    sfMusic_destroy(main->sounds->town);
}

static void free_quests(main_t *main)
{
    sfSprite_destroy(main->quests->spr);
    sfTexture_destroy(main->quests->texture);
    sfText_destroy(main->quests->quest);
    sfText_destroy(main->quests->done);
    sfText_destroy(main->quests->second);
    sfText_destroy(main->quests->desc);
    sfText_destroy(main->quests->description);
    free_button(main->quests->qst1);
    free_button(main->quests->qst2);
    free_button(main->quests->qst3);
    free_button(main->quests->qst4);
    free_button(main->quests->qst5);
    free(main->quests);
}

void free_all(main_t *main)
{
    sfRenderWindow_destroy(main->wind.window);
    free_menus_h(main);
    free_skilltree_h(main);
    free_keys(main);
    free(main->sounds);
    free_quests(main);
    free_circles(main);
    free_rain(main);
}
