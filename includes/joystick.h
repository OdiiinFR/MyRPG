/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Contains the necessary utilities for the pad.
*/

#ifndef JOYSTICK_H_
    #define JOYSTICK_H_

typedef struct joys {
    int nb;
    int joy;
    int tapis;
    int key_tapis;
    int key_joy;
    int last;
    sfJoystickIdentification joy_id;
    sfJoystickIdentification tapis_id;
} joys_t;

void find_joys(joys_t *joy);
joys_t *set_joys(void);

#endif /* !JOYSTICK_H_ */
