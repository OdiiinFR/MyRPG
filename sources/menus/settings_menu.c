/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** settings_menu
*/

#include "main.h"

void do_settings(main_t *m)
{
    sfRenderWindow_drawSprite(m->wind.window, m->params->Sprit_back, NULL);
    sfRenderWindow_drawSprite(m->wind.window, m->params->Spri_sld1, NULL);
    sfRenderWindow_drawSprite(m->wind.window, m->params->Spri_sld2, NULL);
    btn_action(m->params->back, m);
    btn_action(m->params->reso, m);
    btn_action(m->params->set_btn, m);
    btn_action(m->params->frame1, m);
    btn_action(m->params->frame2, m);
    btn_action(m->params->frame3, m);
    btn_action(m->params->slid1, m);
    btn_action(m->params->slid2, m);
    btn_action(m->params->english, m);
    btn_action(m->params->french, m);
    sfRenderWindow_drawText(m->wind.window, m->params->language, NULL);
    sfRenderWindow_drawText(m->wind.window, m->params->framerate, NULL);
    sfRenderWindow_drawText(m->wind.window, m->params->sound, NULL);
    sfRenderWindow_drawText(m->wind.window, m->params->slider1, NULL);
    sfRenderWindow_drawText(m->wind.window, m->params->slider2, NULL);
}

params_menu_t *create_params3(params_menu_t *new)
{
    sfVector3f english = {1050, 150, 1};
    sfVector3f french = {1450, 150, 1};
    sfVector2f lang = {1, 1};
    sfVector2f slider = {0.8, 0.8};

    new->english = new_button("\t   EN\0", english, 0, 17);
    new->french = new_button("\t   FR\0", french, 0, 18);
    new->language = btn_text("Select your language", 1000, 50, lang);
    new->framerate = btn_text("Select your framerate", 1000, 300, lang);
    new->sound = btn_text("Set up your sound :", 50, 500, lang);
    new->slider1 = btn_text("Volume of musics :", 50, 600, slider);
    new->slider2 = btn_text("Volume of sound effects :", 50, 800, slider);
    return new;
}

params_menu_t *create_params2(params_menu_t *new)
{
    sfVector2f pos = {0, 0};
    sfVector2f pos_slid1 = {20, 600};
    sfVector2f pos_slid2 = {20, 800};

    new->reso_menu = create_resolution();
    new->key_menu = create_key_config();
    new->Sprit_back = sfSprite_create();
    new->Texture_back = sfTexture_createFromFile(BCK_PARMAS, NULL);
    sfSprite_setTexture(new->Sprit_back, new->Texture_back, sfFalse);
    sfSprite_setPosition(new->Sprit_back, pos);
    new->Spri_sld1 = sfSprite_create();
    new->Texture_slid1 = sfTexture_createFromFile("images/slider.png", NULL);
    sfSprite_setTexture(new->Spri_sld1, new->Texture_slid1, sfFalse);
    sfSprite_setPosition(new->Spri_sld1, pos_slid1);
    new->Spri_sld2 = sfSprite_create();
    new->Texture_slid2 = sfTexture_createFromFile("images/slider.png", NULL);
    sfSprite_setTexture(new->Spri_sld2, new->Texture_slid2, sfFalse);
    sfSprite_setPosition(new->Spri_sld2, pos_slid2);
    return create_params3(new);
}

params_menu_t *create_params(float music, float sound)
{
    params_menu_t *new = malloc(sizeof(*new));
    sfVector3f back = {50, 50, 1};
    sfVector3f res = {100, 350, 1};
    sfVector3f btn = {600, 350, 1};
    sfVector3f frame1 = {1100, 400, 1};
    sfVector3f frame2 = {1350, 400, 1};
    sfVector3f frame3 = {1600, 400, 1};
    sfVector3f slid1 = {((music * 1600) / 100), 690, 1};
    sfVector3f slid2 = {((sound * 1600) / 100), 890, 1};

    new->slid1 = new_button("\0", slid1, 0, 5);
    new->slid2 = new_button("\0", slid2, 0, 6);
    new->back = new_button("\t Back\0", back, 0, 22);
    new->reso = new_button("  Window\0", res, 6, 22);
    new->set_btn = new_button(" Buttons\0", btn, 7, 22);
    new->frame1 = new_button("144\0", frame1, 0, 2);
    new->frame2 = new_button(" 60\0", frame2, 0, 3);
    new->frame3 = new_button(" 30\0", frame3, 0, 4);
    return create_params2(new);
}
