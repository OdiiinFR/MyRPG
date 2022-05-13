/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** free_menus
*/

#include "main.h"

static void free_main_menu(main_t *main)
{
    sfSprite_destroy(main->start->Sprit_back);
    sfTexture_destroy(main->start->Texture_back);
    free_button(main->start->play);
    free_button(main->start->settings);
    free_button(main->start->htp);
    free_button(main->start->quit);
    free_button(main->start->score);
    free(main->start);
}

static void free_play_menu(main_t *main)
{
    sfSprite_destroy(main->play->Sprit_back);
    sfTexture_destroy(main->play->Texture_back);
    free_button(main->play->back);
    free_button(main->play->del);
    free_button(main->play->save1);
    free_button(main->play->save2);
    free_button(main->play->save3);
    free_button(main->play->validation);
    free_button(main->play->discard);
    sfText_destroy(main->play->create);
    sfText_destroy(main->play->entry_txt);
    sfText_destroy(main->play->destroy);
    free(main->play->txt);
    free(main->play);
}

static void free_pause_menu(main_t *main)
{
    sfSprite_destroy(main->pause->Sprit_back);
    sfTexture_destroy(main->pause->Texture_back);
    free_button(main->pause->back);
    free_button(main->pause->params);
    free_button(main->pause->quit);
    free_button(main->pause->save);
    sfText_destroy(main->pause->pause);
    free(main->pause);
}

static void free_htp_menu(main_t *main)
{
    sfSprite_destroy(main->htp->Sprit_back);
    sfTexture_destroy(main->htp->Texture_back);
    free_button(main->htp->back);
    free(main->htp);
}

void free_menus_h(main_t *main)
{
    free_main_menu(main);
    free_play_menu(main);
    free_params_menu(main);
    free_pause_menu(main);
    free_htp_menu(main);
}
