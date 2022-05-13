/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Contains the battle engine header.
*/

#ifndef BATTLE_HEADER_H_
    #define BATTLE_HEADER_H_

    #include "battle_struct.h"
    #include "main.h"

battle_t *init_battle(main_t *main);
void do_battle_engine(battle_t *battle, main_t *main);

#endif /* !BATTLE_HEADER_H_ */
