/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** free_params
*/

#include "main.h"

static void free_key_config_menu2(main_t *main)
{
    free_button(main->params->key_menu->config5);
    free_button(main->params->key_menu->config6);
    free_button(main->params->key_menu->config7);
    free_button(main->params->key_menu->config8);
    sfText_destroy(main->params->key_menu->preselect);
    sfText_destroy(main->params->key_menu->diy);
    sfText_destroy(main->params->key_menu->moove);
    sfText_destroy(main->params->key_menu->pause);
    sfText_destroy(main->params->key_menu->inventory);
    sfText_destroy(main->params->key_menu->tree);
    sfText_destroy(main->params->key_menu->quest);
    free(main->params->key_menu);
}

static void free_key_config_menu(main_t *main)
{
    sfSprite_destroy(main->params->key_menu->Sprit_back);
    sfTexture_destroy(main->params->key_menu->Texture_back);
    free_button(main->params->key_menu->back);
    free_button(main->params->key_menu->selection1);
    free_button(main->params->key_menu->selection2);
    free_button(main->params->key_menu->selection3);
    free_button(main->params->key_menu->config_up);
    free_button(main->params->key_menu->config_left);
    free_button(main->params->key_menu->config_right);
    free_button(main->params->key_menu->config_down);
    free_key_config_menu2(main);
}

static void free_resolution_menu(main_t *main)
{
    sfText_destroy(main->params->reso_menu->reso1);
    sfText_destroy(main->params->reso_menu->reso2);
    sfText_destroy(main->params->reso_menu->reso3);
    sfText_destroy(main->params->reso_menu->reso4);
    sfText_destroy(main->params->reso_menu->title);
    sfSprite_destroy(main->params->reso_menu->Sprit_back);
    sfTexture_destroy(main->params->reso_menu->Texture_back);
    free_button(main->params->reso_menu->back);
    free_button(main->params->reso_menu->reso1_1);
    free_button(main->params->reso_menu->reso1_2);
    free_button(main->params->reso_menu->reso1_3);
    free_button(main->params->reso_menu->reso2_1);
    free_button(main->params->reso_menu->reso2_2);
    free_button(main->params->reso_menu->reso2_3);
    free_button(main->params->reso_menu->reso3_1);
    free_button(main->params->reso_menu->reso3_2);
    free_button(main->params->reso_menu->reso3_3);
    free_button(main->params->reso_menu->reso4_1);
    free(main->params->reso_menu);
}

static void free_params_menu2(main_t *main)
{
    free_button(main->params->slid1);
    free_button(main->params->slid2);
    free_button(main->params->back);
    free_button(main->params->reso);
    free_resolution_menu(main);
    free_key_config_menu(main);
    free_button(main->params->set_btn);
    free_button(main->params->frame1);
    free_button(main->params->frame2);
    free_button(main->params->frame3);
    free_button(main->params->english);
    free_button(main->params->french);
    free(main->params);
}

void free_params_menu(main_t *main)
{
    sfText_destroy(main->params->language);
    sfText_destroy(main->params->framerate);
    sfText_destroy(main->params->sound);
    sfText_destroy(main->params->slider1);
    sfText_destroy(main->params->slider2);
    sfSprite_destroy(main->params->Sprit_back);
    sfTexture_destroy(main->params->Texture_back);
    sfSprite_destroy(main->params->Spri_sld1);
    sfTexture_destroy(main->params->Texture_slid1);
    sfSprite_destroy(main->params->Spri_sld2);
    sfTexture_destroy(main->params->Texture_slid2);
    free_params_menu2(main);
}
