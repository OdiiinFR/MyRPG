/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Contains animation routines prototypes.
*/

#ifndef ANIMATION_H_
    #define ANIMATION_H_

    #define CURTAIN "res/spr/ui/MARI_Curtain.png"

    #include "csfml.h"
    #include "player_structs.h"

typedef struct transition {
    sfTexture *tx_curtain;
    sfSprite *sp_curtain;
    sfClock *clock;
    sfIntRect rect;
} transition_t;

transition_t *create_transition(void);

#endif /* !ANIMATION_H_ */
