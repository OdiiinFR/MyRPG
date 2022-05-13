/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** sound
*/

#ifndef SOUNDS_H_
    #define SOUNDS_H_

    #include "main.h"
    #include "sounds_structs.h"

sounds_t *create_sounds(void);
void apply_volume(main_t *main);
void stop_music(main_t *main, int run);
void do_music(main_t *main, int former);

#endif /* !SOUNDS_H_ */
