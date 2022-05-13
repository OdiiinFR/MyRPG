/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Contains attacks prototypes.
*/

#ifndef ATTACK_HEADER_H_
    #define ATTACK_HEADER_H_

    #include <SFML/System/Clock.h>
    #include "main.h"
    #include "attack_struct.h"

void chooses_arrows(attack_t *attack);
int do_attack(attack_t *attack, sfClock *clock, main_t *main);
attack_t *init_attack_struct(main_t *main);

#endif /* !ATTACK_HEADER_H_ */
