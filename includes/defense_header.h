/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Contains the prototypes of the defense functions.
*/

#ifndef DEFENSE_HEADER_H_
    #define DEFENSE_HEADER_H_

    #include "defense_struct.h"
    #include "main.h"
    #include "enemy_struct.h"

defense_t *init_defense(main_t *main);
void generate_pattern(pattern_t *pattern, defense_t *defense, \
enemy_t *enemy, int zone);
int do_defense_loop(sfRenderWindow *window, defense_t *defense, main_t *main);

void do_straight_line(pattern_t *pattern);
float do_pendulum(float time, pattern_t *pattern, sfVector2f center);
float do_concentric_spiral(float time, pattern_t *pattern, sfVector2f center);

void choose_pos(int move, pattern_t *pattern, defense_t *defense);
void check_collisions_defense(defense_t *defense, int key_code, main_t *main);
float fetch_vector_norm(sfVector2f pos);

int check_events(sfRenderWindow *window, defense_t *defense);

#endif /* !DEFENSE_HEADER_H_ */
