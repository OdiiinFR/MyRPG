/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** menus
*/

#ifndef MENUS_H_
    #define MENUS_H_

    #define BCK_MAIN "images/background.png"
    #define BCK_PARMAS "images/background_setting.png"

    #define HUD1 "images/hud1.png"
    #define HUD2 "images/hud2.png"
    #define HUD3 "images/hud3.png"
    #define CROIX "images/croix.png"

    #include "button.h"

typedef struct hud_menu {
    sfSprite **hud;
    sfVector2f *pos_hud;
    sfTexture **txt_hud;
    sfSprite **hud_skt;
    sfVector2f *pos_hud_skt;
    sfTexture **txt_hud_skt;
    sfSprite **hud_stat;
    sfVector2f *pos_hud_stat;
    sfTexture **txt_hud_stat;
    sfText *skill;
    sfText *stats;
    sfText *health;
    sfText *attack;
    sfText *defence;
} hud_menu_t;

typedef struct main_menu {
    sfSprite *Sprit_back;
    sfTexture *Texture_back;
    struct button *play;
    struct button *settings;
    struct button *htp;
    struct button *quit;
    struct button *score;
} main_menu_t;

typedef struct play_menu {
    sfSprite *Sprit_back;
    sfTexture *Texture_back;
    struct button *back;
    struct button *del;
    struct button *save1;
    struct button *save2;
    struct button *save3;
    struct button *validation;
    struct button *discard;
    sfText *create;
    sfText *entry_txt;
    sfText *destroy;
    char *txt;
    int ctr;
} play_menu_t;

typedef struct key_config_menu {
    sfSprite *Sprit_back;
    sfTexture *Texture_back;
    struct button *back;
    struct button *selection1;
    struct button *selection2;
    struct button *selection3;
    struct button *config_up;
    struct button *config_left;
    struct button *config_right;
    struct button *config_down;
    struct button *config5;
    struct button *config6;
    struct button *config7;
    struct button *config8;
    sfText *preselect;
    sfText *diy;
    sfText *moove;
    sfText *pause;
    sfText *inventory;
    sfText *tree;
    sfText *quest;
} key_config_menu_t;

typedef struct resolution_menu {
    sfText *reso1;
    sfText *reso2;
    sfText *reso3;
    sfText *reso4;
    sfText *title;
    sfSprite *Sprit_back;
    sfTexture *Texture_back;
    struct button *back;
    struct button *reso1_1;
    struct button *reso1_2;
    struct button *reso1_3;
    struct button *reso2_1;
    struct button *reso2_2;
    struct button *reso2_3;
    struct button *reso3_1;
    struct button *reso3_2;
    struct button *reso3_3;
    struct button *reso4_1;
} resolution_menu_t;

typedef struct params_menu {
    sfText *language;
    sfText *framerate;
    sfText *sound;
    sfText *slider1;
    sfText *slider2;
    sfSprite *Sprit_back;
    sfTexture *Texture_back;
    sfSprite *Spri_sld1;
    sfTexture *Texture_slid1;
    sfSprite *Spri_sld2;
    sfTexture *Texture_slid2;
    struct button *slid1;
    struct button *slid2;
    struct button *back;
    struct button *reso;
    struct resolution_menu *reso_menu;
    struct key_config_menu *key_menu;
    struct button *set_btn;
    struct button *frame1;
    struct button *frame2;
    struct button *frame3;
    struct button *english;
    struct button *french;
} params_menu_t;

typedef struct pause_menu {
    sfSprite *Sprit_back;
    sfTexture *Texture_back;
    struct button *back;
    struct button *params;
    struct button *quit;
    struct button *save;
    sfText *pause;
} pause_menu_t;

typedef struct htp_menu {
    sfSprite *Sprit_back;
    sfTexture *Texture_back;
    struct button *back;
} htp_menu_t;

main_menu_t *create_main(void);
htp_menu_t *create_htp(void);
params_menu_t *create_params(float music, float sound);
resolution_menu_t *create_resolution(void);
key_config_menu_t *create_key_config(void);
pause_menu_t *create_pause(void);
hud_menu_t *set_hud(void);

#endif /* !MENUS_H_ */
