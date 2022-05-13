/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** reso_menu
*/

#include "main.h"

void create_frameplus(button_t *new, int type)
{
    if (type == 6) {
        new->Texture_idle = sfTexture_createFromFile(RND2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(RND2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(RND2_THR, NULL);
        new->function = 6;
        new->height = 130;
        new->lenght = 130;
    }
    return;
}

void do_resolution(main_t *m)
{
    sfRenderWindow_drawSprite(m->wind.window, m->params->Sprit_back, NULL);
    btn_action(m->params->reso_menu->back, m);
    btn_action(m->params->reso_menu->reso1_1, m);
    btn_action(m->params->reso_menu->reso1_2, m);
    btn_action(m->params->reso_menu->reso1_3, m);
    btn_action(m->params->reso_menu->reso2_1, m);
    btn_action(m->params->reso_menu->reso2_2, m);
    btn_action(m->params->reso_menu->reso2_3, m);
    btn_action(m->params->reso_menu->reso3_1, m);
    btn_action(m->params->reso_menu->reso3_2, m);
    btn_action(m->params->reso_menu->reso3_3, m);
    btn_action(m->params->reso_menu->reso4_1, m);
    sfRenderWindow_drawText(m->wind.window, m->params->reso_menu->reso1, NULL);
    sfRenderWindow_drawText(m->wind.window, m->params->reso_menu->reso2, NULL);
    sfRenderWindow_drawText(m->wind.window, m->params->reso_menu->reso3, NULL);
    sfRenderWindow_drawText(m->wind.window, m->params->reso_menu->reso4, NULL);
    sfRenderWindow_drawText(m->wind.window, m->params->reso_menu->title, NULL);
}

static void create_resolution1(resolution_menu_t *new)
{
    sfVector2f lang = {1, 1};

    new->title = btn_text("Choose your resolution :", 600, 50, lang);
}

static void create_resolution2(resolution_menu_t *new)
{
    sfVector3f reso2_1 = {500, 450, 1};
    sfVector3f reso2_2 = {500, 650, 1};
    sfVector3f reso2_3 = {500, 850, 1};
    sfVector3f reso3_1 = {1100, 450, 1};
    sfVector3f reso3_2 = {1100, 650, 1};
    sfVector3f reso3_3 = {1100, 850, 1};
    sfVector3f reso4_1 = {1500, 450, 1};
    sfVector2f lang = {1, 1};

    new->reso1 = btn_text("16/9", 200, 300, lang);
    new->reso2 = btn_text("16/10", 600, 300, lang);
    new->reso3 = btn_text("4/3", 1200, 300, lang);
    new->reso4 = btn_text("4K", 1600, 300, lang);
    new->reso2_1 = new_button(" 1280x800\0", reso2_1, 0, 10);
    new->reso2_2 = new_button("1920x1200\0", reso2_2, 0, 11);
    new->reso2_3 = new_button("2560x1600\0", reso2_3, 0, 12);
    new->reso3_1 = new_button(" 1024x768\0", reso3_1, 0, 13);
    new->reso3_2 = new_button("1400x1050\0", reso3_2, 0, 14);
    new->reso3_3 = new_button("2048x1536\0", reso3_3, 0, 15);
    new->reso4_1 = new_button("4096x2160\0", reso4_1, 0, 16);
}

resolution_menu_t *create_resolution(void)
{
    resolution_menu_t *new = malloc(sizeof(*new));
    sfVector2f pos = {0, 0};
    sfVector3f back = {50, 50, 1};
    sfVector3f reso1_1 = {100, 450, 1};
    sfVector3f reso1_2 = {100, 650, 1};
    sfVector3f reso1_3 = {100, 850, 1};

    new->back = new_button("\t Back\0", back, 3, 22);
    new->reso1_1 = new_button(" 1280x720\0", reso1_1, 0, 7);
    new->reso1_2 = new_button("1920x1080\0", reso1_2, 0, 8);
    new->reso1_3 = new_button("2560x1440\0", reso1_3, 0, 9);
    create_resolution1(new);
    create_resolution2(new);
    new->Sprit_back = sfSprite_create();
    new->Texture_back = sfTexture_createFromFile(BCK_PARMAS, NULL);
    sfSprite_setTexture(new->Sprit_back, new->Texture_back, sfFalse);
    sfSprite_setPosition(new->Sprit_back, pos);
    return new;
}
