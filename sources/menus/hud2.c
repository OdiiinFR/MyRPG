/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** hud2
*/

#include "main.h"

void new_pos2(sfText *txt, sfVector2f pos, sfVector2f hg)
{
    pos.x += hg.x;
    pos.y += hg.y;
    sfText_setPosition(txt, pos);
}

void new_pos(sfSprite *spr, sfVector2f pos, sfVector2f hg)
{
    pos.x += hg.x;
    pos.y += hg.y;
    sfSprite_setPosition(spr, pos);
}

void print_hud1(main_t *main, sfView *view)
{
    sfVector2f centr = sfView_getCenter(view);
    sfVector2f wind_size = sfView_getSize(view);
    sfVector2f hg = {centr.x - (wind_size.x / 2), centr.y - (wind_size.y / 2)};
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfFloatRect tmp = sfSprite_getLocalBounds(main->huds->hud[2]);

    if (sfFloatRect_contains(&tmp, a.x, a.y) == sfTrue && main->event == 1) {
        main->event = 0;
        main->hud = 1;
        return;
    }
    sfSprite_setPosition(main->huds->hud[1], hg);
    sfRenderWindow_drawSprite(main->wind.window, main->huds->hud[1], NULL);
    return;
}

static void print_hud2_2(main_t *main, sfVector2f hg)
{
    sfRenderWindow *tmp = main->wind.window;

    for (int i = 0; i < 9; i += 1) {
        new_pos(main->huds->hud_skt[i], main->huds->pos_hud_skt[i], hg);
        sfRenderWindow_drawSprite(tmp, main->huds->hud_skt[i], NULL);
    }
    for (int i = 0; i < 4; i += 1) {
        new_pos(main->huds->hud_stat[i], main->huds->pos_hud_stat[i], hg);
        sfRenderWindow_drawSprite(tmp, main->huds->hud_stat[i], NULL);
    }
    new_pos2(main->huds->attack, (sfVector2f){700, 50}, hg);
    new_pos2(main->huds->health, (sfVector2f){580, 50}, hg);
    new_pos2(main->huds->defence, (sfVector2f){580, 140}, hg);
    new_pos2(main->huds->skill, (sfVector2f){230, 230}, hg);
    new_pos2(main->huds->stats, (sfVector2f){550, 230}, hg);
    sfRenderWindow_drawText(main->wind.window, main->huds->skill, NULL);
    sfRenderWindow_drawText(main->wind.window, main->huds->stats, NULL);
    sfRenderWindow_drawText(main->wind.window, main->huds->attack, NULL);
    sfRenderWindow_drawText(main->wind.window, main->huds->defence, NULL);
    sfRenderWindow_drawText(main->wind.window, main->huds->health, NULL);
}

void print_hud2(main_t *main)
{
    sfVector2f centr = sfView_getCenter(main->view);
    sfVector2f wind_size = sfView_getSize(main->view);
    sfVector2f hg = {centr.x - (wind_size.x / 2), centr.y - (wind_size.y / 2)};
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfFloatRect tmp = sfSprite_getLocalBounds(main->huds->hud[1]);

    if (sfFloatRect_contains(&tmp, a.x, a.y) == sfTrue && main->event == 1) {
        main->event = 0;
        main->hud = 0;
        return;
    }
    apply_hud(main);
    new_pos(main->huds->hud[0], main->huds->pos_hud[0], hg);
    new_pos(main->huds->hud[2], main->huds->pos_hud[2], hg);
    sfRenderWindow_drawSprite(main->wind.window, main->huds->hud[0], NULL);
    sfRenderWindow_drawSprite(main->wind.window, main->huds->hud[2], NULL);
    return print_hud2_2(main, hg);
}
