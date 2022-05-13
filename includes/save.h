/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** save
*/

#ifndef SAVE_H_
    #define SAVE_H_

    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

typedef struct save {
    char *name;
    char *file_path;
} save_t;

save_t **create_saves(void);
void change_pos(sfText *texte, int flag);
int good_entry(char *str);

#endif /* !SAVE_H_ */
