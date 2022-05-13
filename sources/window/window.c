/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** window
*/

#include "main.h"
#include "sounds.h"

window_t fill_window(void)
{
    window_t new;
    sfVideoMode mode = {1920, 1080, 32};
    sfVector2i pos = {0, 0};
    char name[18] = "Kisaragi Station\0";

    new.mode = mode;
    new.menu = 0;
    new.position = pos;
    new.framerate = 60;
    new.nb_resolution = 169.1;
    new.name = name;
    new.is_in_htp = 0;
    new.window = sfRenderWindow_create(new.mode, name, sfClose, NULL);
    sfRenderWindow_setPosition(new.window, new.position);
    sfRenderWindow_setFramerateLimit(new.window, new.framerate);
    new.resolution = sfRenderWindow_getSize(new.window);
    return new;
}

static main_t fill_main2(main_t new)
{
    new.drag = -1;
    new.drag2 = -1;
    new.drag3 = -1;
    new.drag = -1;
    new.drag2 = -1;
    new.drag3 = -1;
    new.money = 1000;
    new.event = 0;
    new.in_save = 0;
    new.creating = 0;
    new.lang = 0;
    new.zone = 100;
    new.last = 0;
    new.circles = create_fog();
    new.rain = create_rain();
    new.hud = 0;
    new.huds = set_hud();
    new.font = sfFont_createFromFile(FONT);
    new.transition = create_transition();
    new.joy = set_joys();
    new.flag = 0;
    new.train = 0;
    new.spr_train = sfSprite_create();
    new.txt_train = sfTexture_createFromFile("res/spr/maps/train_ext.png", NULL);
    sfSprite_setPosition(new.spr_train, (sfVector2f){-2000, 510});
    sfSprite_setTexture(new.spr_train, new.txt_train, sfFalse);
    return new;
}

main_t fill_main(void)
{
    main_t new;
    sfVector2f pos = {0, 0};
    sfVector2f scale = {0.8, 0.8};

    new.wind = fill_window();
    new.start = create_main();
    new.pause = create_pause();
    new.htp = create_htp();
    new.saves = create_saves();
    new.play = create_play(&new);
    new.sounds = create_sounds();
    new.params = create_params(new.sounds->vol_music, new.sounds->vol_sounds);
    new.inv = creation();
    new.skt = create_skilltree();
    new.last_event = sfEvtClosed;
    new.drop = pos;
    new.modifier = btn_text("+10", 0, 0, scale);
    new.config = set_up_keys();
    new.quests = set_quests();
    return fill_main2(new);
}
