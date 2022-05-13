/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Contains the sound structure.
*/

#ifndef SOUNDS_STRUCTS_H_
    #define SOUNDS_STRUCTS_H_

    #include <SFML/Audio.h>
    #define SOUND "res/sounds/success_failure_bitcrushed.ogg"

typedef struct sounds {
    sfMusic *menu;
    sfMusic *outside;
    sfMusic *tunnel;
    sfMusic *town;
    sfMusic *end;
    sfMusic *houses;
    sfMusic *sound;
    float vol_music;
    float vol_sounds;
    int run;
} sounds_t;

#endif /* !SOUNDS_STRUCTS_H_ */
