/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Handles text display.
*/

#ifndef HANDLE_TEXT_H_
    #define HANDLE_TEXT_H_

    #include "collisions_structs.h"
    #include "main.h"
    #include "player_structs.h"

tmp_t *add_cell(tmp_t *cell);
void do_text_loop(char **text, \
main_t *main, player_t *player, col_t *col);
int check_interactions(main_t *main, col_t *col);
void free_loop(tmp_t *cells);
int fetch_infos(void **parsed, interact_t **inter, int zone);

#endif /* !HANDLE_TEXT_H_ */
