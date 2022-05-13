/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** set_up_saves
*/

#include "main.h"

int good_entry(char *str)
{
    if (str[0] == '\0')
        return 1;
    return 0;
}

char *zonned(main_t *main)
{
    char *tmp = malloc(sizeof(char) * 2);

    if (main->player->zone < 15)
        tmp[0] = main->player->zone + 48;
    else
        tmp[0] = main->player->zone;
    tmp[1] = '\0';
    return tmp;
}

save_t *new_save(char *file_name)
{
    save_t *new = malloc(sizeof(save_t));
    char *file = my_strcat("saves/", file_name);
    FILE *fd = fopen(file, "r");
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, fd);
    if (line[0] == ' ')
        new->name = file_name;
    else if (line[0] != ' ')
        new->name = mystrdup(line);
    new->file_path = mystrdup(file);
    free(line);
    fclose(fd);
    free(file);
    return new;
}

static int fetch_in_order(char *name)
{
    char *nb = name;

    for (; (nb[0] < '0' || nb[0] > '9') && (nb[0] != '\0'); ++nb);
    if (nb[0] == '\0')
        return (0);
    return (my_atoi(nb) - 1);
}

save_t **create_saves(void)
{
    save_t **new = malloc(sizeof(save_t *) * 4);
    DIR *dir = opendir("saves/");
    struct dirent *file;
    int i = 0;

    file = readdir(dir);
    for (int j = 0; j < 4; ++j)
        new[j] = NULL;
    for (; file != NULL; file = readdir(dir)) {
        if (file->d_name[0] != '.') {
            i = fetch_in_order(file->d_name);
            new[i] = new_save(mystrdup(file->d_name));
        }
    }
    closedir(dir);
    return new;
}
