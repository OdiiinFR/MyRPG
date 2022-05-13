/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** bounds
*/

#include "main.h"

void create_a_save6(main_t *main, char *line, int save)
{
    int fd = open(main->saves[save]->file_path, O_WRONLY);

    write(fd, line, my_strlen(line));
    close(fd);
}

static int fetch_position(char **line)
{
    int result = 0;

    for (; (*line)[0] != ' '; ++(*line)) {
        if ((*line)[0] > 47 && (*line)[0] < 58)
            result = result * 10 + ((*line)[0] - 48);
    }
    ++(*line);
    return (result);
}

void open_and_apply6(main_t *m, FILE *fd, char *line, size_t len)
{
    sfVector2f pos;
    char *tmp;

    getline(&line, &len, fd);
    tmp = line;
    pos.y = fetch_position(&tmp);
    pos.x = fetch_position(&tmp);
    sfSprite_setPosition(m->player->sp_player, pos);
}
