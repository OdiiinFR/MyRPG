/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** sounds
*/

#include "main.h"

void apply_volume(main_t *main)
{
    sfMusic_setVolume(main->sounds->menu, main->sounds->vol_music);
    sfMusic_setVolume(main->sounds->town, main->sounds->vol_music);
    sfMusic_setVolume(main->sounds->tunnel, main->sounds->vol_music);
    sfMusic_setVolume(main->sounds->outside, main->sounds->vol_music);
    sfMusic_setVolume(main->sounds->end, main->sounds->vol_music);
    sfMusic_setVolume(main->sounds->houses, main->sounds->vol_music);
    return;
}

sounds_t *create_sounds(void)
{
    sounds_t *new = malloc(sizeof(*new));

    new->vol_music = 50;
    new->vol_sounds = 50;
    new->menu = sfMusic_createFromFile("res/sounds/new_menuloopv2.ogg");
    sfMusic_setLoop(new->menu, sfTrue);
    new->outside = sfMusic_createFromFile("res/sounds/new_old_puppet.ogg");
    sfMusic_setLoop(new->outside, sfTrue);
    new->town = sfMusic_createFromFile("res/sounds/new_strange_town_opus.ogg");
    sfMusic_setLoop(new->town, sfTrue);
    new->end = sfMusic_createFromFile(SOUND);
    sfMusic_setLoop(new->end, sfTrue);
    new->houses = sfMusic_createFromFile("res/sounds/bathroom-tomb.ogg");
    sfMusic_setLoop(new->houses, sfTrue);
    new->tunnel = sfMusic_createFromFile("res/sounds/ambience.ogg");
    sfMusic_setLoop(new->tunnel, sfTrue);
    return new;
}

void stop_music(main_t *main, int run)
{
    if (run == 1)
        sfMusic_stop(main->sounds->menu);
    if (run == 2)
        sfMusic_stop(main->sounds->menu);
    if (run == 3)
        sfMusic_stop(main->sounds->outside);
    if (run == 4)
        sfMusic_stop(main->sounds->town);
    if (run == 5)
        sfMusic_stop(main->sounds->outside);
    if (run == 6)
        sfMusic_stop(main->sounds->tunnel);
    if (run == 7 || run == 8)
        sfMusic_stop(main->sounds->houses);
    if (run == 9)
        sfMusic_stop(main->sounds->end);
}

static void play_music(main_t *main, int run)
{
    if (run == 1)
        sfMusic_play(main->sounds->menu);
    if (run == 2)
        sfMusic_play(main->sounds->menu);
    if (run == 3)
        sfMusic_play(main->sounds->outside);
    if (run == 4)
        sfMusic_play(main->sounds->town);
    if (run == 5)
        sfMusic_play(main->sounds->outside);
    if (run == 6)
        sfMusic_play(main->sounds->tunnel);
    if (run == 7 || run == 8)
        sfMusic_play(main->sounds->houses);
    if (run == 9)
        sfMusic_play(main->sounds->end);
}

void do_music(main_t *main, int former)
{
    stop_music(main, former);
    play_music(main, main->player->zone);
    return;
}
