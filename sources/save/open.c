/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** open
*/

#include "sounds.h"
#include "main.h"

static void apply(int i, main_t *m, char *line)
{
    int tmp = line[i + 2] - 48;
    if (tmp != 0)
        for (int tmp2 = 0; tmp2 != tmp; tmp2 += 1)
            inv_add(m, (line[i] - 48), m->inv);
}

static void open_and_apply4(main_t *m, FILE *fd, char *line, size_t len)
{
    for (int i = 0, a = 0; a < 5; i += 5, a += 1) {
        if ((line[i + 1] == ' '))
            apply(i, m, line);
        else
            i += 1;
    }
    getline(&line, &len, fd);
    for (int i = 0, a = 0; a < 5; i += 5, a += 1) {
        if ((line[i + 1] == ' '))
            apply(i, m, line);
        else
            i += 1;
    }
    return open_and_apply5(m, fd, line, len);
}

static void open_and_apply3(main_t *m, FILE *fd, char *line, size_t len)
{
    getline(&line, &len, fd);
    m->skt->skt1->skt->in_fonction = line[0] - 48;
    m->skt->skt2->skt->in_fonction = line[2] - 48;
    m->skt->skt3->skt->in_fonction = line[4] - 48;
    m->skt->skt4->skt->in_fonction = line[6] - 48;
    m->skt->skt5->skt->in_fonction = line[8] - 48;
    m->skt->skt6->skt->in_fonction = line[10] - 48;
    m->skt->skt7->skt->in_fonction = line[12] - 48;
    m->skt->skt8->skt->in_fonction = line[14] - 48;
    m->skt->skt9->skt->in_fonction = line[16] - 48;
    getline(&line, &len, fd);
    sfMusic_stop(m->sounds->menu);
    do_music(m, 0);
    return open_and_apply4(m, fd, line, len);
}

static void open_and_apply2(main_t *m, FILE *fd, char *line, size_t len)
{
    getline(&line, &len, fd);
    m->quests->qst1->position.x = my_atoi(line);
    sfSprite_setPosition(m->quests->qst1->Sprite, m->quests->qst1->position);
    getline(&line, &len, fd);
    m->quests->qst2->position.x = my_atoi(line);
    sfSprite_setPosition(m->quests->qst2->Sprite, m->quests->qst2->position);
    getline(&line, &len, fd);
    m->quests->qst3->position.x = my_atoi(line);
    sfSprite_setPosition(m->quests->qst3->Sprite, m->quests->qst3->position);
    getline(&line, &len, fd);
    m->quests->qst4->position.x = my_atoi(line);
    sfSprite_setPosition(m->quests->qst4->Sprite, m->quests->qst4->position);
    getline(&line, &len, fd);
    m->quests->qst5->position.x = my_atoi(line);
    sfSprite_setPosition(m->quests->qst5->Sprite, m->quests->qst5->position);
    return open_and_apply3(m, fd, line, len);
}

void open_and_apply(main_t *main)
{
    FILE *fd = fopen(main->saves[main->in_save]->file_path, "r");
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, fd);
    getline(&line, &len, fd);
    main->money = my_atoi(line);
    getline(&line, &len, fd);
    for (int i = 0; i < 8; i += 1) {
        main->config->keys[i]->key = my_atoi(line);
        key_to_txt(main->config->keys[i]);
        getline(&line, &len, fd);
    }
    main->lang = my_atoi(line);
    getline(&line, &len, fd);
    main->player->zone = my_atoi(line);
    getline(&line, &len, fd);
    main->sounds->vol_music = my_atoi(line);
    getline(&line, &len, fd);
    main->sounds->vol_sounds = my_atoi(line);
    return open_and_apply2(main, fd, line, len);
}
