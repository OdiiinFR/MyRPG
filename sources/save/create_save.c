/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** create_save
*/

#include "main.h"

static void create_a_save5(main_t *main, char *line, int save)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(main->player->sp_player);

    for (int i = 0; i < 4; i += 1) {
        line = my_strcat(line, my_itoa(main->inv->equiped[0][i].reference));
        line = my_strcat(line, " ");
    }
    line = my_strcat(line, "\n");
    for (int i = 0; i < 3; i += 1) {
        line = my_strcat(line, my_itoa(main->inv->stats[i].stat));
        line = my_strcat(line, " ");
    }
    line = my_strcat(line, "\n");
    line = my_strcat(line, my_itoa(pos.top));
    line = my_strcat(line, " ");
    line = my_strcat(line, my_itoa(pos.left));
    line = my_strcat(line, " ");
    return create_a_save6(main, line, save);
}

static void create_a_save4(main_t *main, char *line, int save)
{
    line = my_strcat(line, my_itoa(main->skt->skt8->skt->in_fonction));
    line = my_strcat(line, " ");
    line = my_strcat(line, my_itoa(main->skt->skt9->skt->in_fonction));
    line = my_strcat(line, "\n");
    for (int i = 0; i < 5; i += 1) {
        line = my_strcat(line, my_itoa(main->inv->list[0][i].reference));
        line = my_strcat(line, " ");
        line = my_strcat(line, my_itoa(main->inv->list[0][i].nb));
        line = my_strcat(line, "  ");
    }
    line = my_strcat(line, "\n");
    for (int i = 0; i < 5; i += 1) {
        line = my_strcat(line, my_itoa(main->inv->list[1][i].reference));
        line = my_strcat(line, " ");
        line = my_strcat(line, my_itoa(main->inv->list[1][i].nb));
        line = my_strcat(line, "  ");
    }
    line = my_strcat(line, "\n");
    return create_a_save5(main, line, save);
}

static void create_a_save3(main_t *main, char *line, int save)
{
    int tmp = main->quests->qst5->position.x;

    line = my_strcat(line, my_itoa(tmp));
    line = my_strcat(line, "\n");
    line = my_strcat(line, my_itoa(main->skt->skt1->skt->in_fonction));
    line = my_strcat(line, " ");
    line = my_strcat(line, my_itoa(main->skt->skt2->skt->in_fonction));
    line = my_strcat(line, " ");
    line = my_strcat(line, my_itoa(main->skt->skt3->skt->in_fonction));
    line = my_strcat(line, " ");
    line = my_strcat(line, my_itoa(main->skt->skt4->skt->in_fonction));
    line = my_strcat(line, " ");
    line = my_strcat(line, my_itoa(main->skt->skt5->skt->in_fonction));
    line = my_strcat(line, " ");
    line = my_strcat(line, my_itoa(main->skt->skt6->skt->in_fonction));
    line = my_strcat(line, " ");
    line = my_strcat(line, my_itoa(main->skt->skt7->skt->in_fonction));
    line = my_strcat(line, " ");
    return create_a_save4(main, line, save);
}

static void create_a_save2(main_t *main, char *line, int save)
{
    int tmp1 = main->sounds->vol_music;
    int tmp2 = main->sounds->vol_sounds;
    int tmp3 = main->quests->qst1->position.x;
    int tmp4 = main->quests->qst2->position.x;
    int tmp5 = main->quests->qst3->position.x;
    int tmp6 = main->quests->qst4->position.x;

    line = my_strcat(line, my_itoa(tmp1));
    line = my_strcat(line, "\n");
    line = my_strcat(line, my_itoa(tmp2));
    line = my_strcat(line, "\n");
    line = my_strcat(line, my_itoa(tmp3));
    line = my_strcat(line, "\n");
    line = my_strcat(line, my_itoa(tmp4));
    line = my_strcat(line, "\n");
    line = my_strcat(line, my_itoa(tmp5));
    line = my_strcat(line, "\n");
    line = my_strcat(line, my_itoa(tmp6));
    line = my_strcat(line, "\n");
    return create_a_save3(main, line, save);
}

void create_a_save(main_t *main, int save)
{
    FILE *fd = fopen(main->saves[save]->file_path, "rw");
    char *line = NULL;
    size_t len = 0;
    char *tmp = zonned(main);

    getline(&line, &len, fd);
    line = my_strcat(line, my_itoa(main->money));
    line = my_strcat(line, "\n");
    for (int i = 0; i < 8; i += 1) {
        line = my_strcat(line, my_itoa(main->config->keys[i]->key));
        line = my_strcat(line, "\n");
    }
    line = my_strcat(line, my_itoa(main->lang));
    line = my_strcat(line, "\n");
    line = my_strcat(line, tmp);
    line = my_strcat(line, "\n");
    fclose(fd);
    return create_a_save2(main, line, save);
}
