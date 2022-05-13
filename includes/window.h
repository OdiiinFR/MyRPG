/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include "csfml.h"

typedef struct window {
    int menu;
    int framerate;
    float nb_resolution;
    char *name;
    int is_in_htp;
    sfRenderWindow *window;
    sfVideoMode mode;
    sfVector2i position;
    sfVector2u resolution;
} window_t;

int set_window(void);

#endif /* !WINDOW_H_ */
