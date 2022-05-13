/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** key_config_menu
*/

#include "main.h"

void do_config_key2(main_t *main)
{
    key_config_menu_t *tmp = main->params->key_menu;

    sfRenderWindow_drawText(main->wind.window, tmp->preselect, NULL);
    sfRenderWindow_drawText(main->wind.window, tmp->moove, NULL);
    sfRenderWindow_drawText(main->wind.window, tmp->diy, NULL);
    sfRenderWindow_drawText(main->wind.window, tmp->pause, NULL);
    sfRenderWindow_drawText(main->wind.window, tmp->inventory, NULL);
    sfRenderWindow_drawText(main->wind.window, tmp->tree, NULL);
    sfRenderWindow_drawText(main->wind.window, tmp->quest, NULL);
    return;
}

void do_config_key(main_t *main)
{
    sfSprite *new = main->params->key_menu->Sprit_back;
    my_key_t **tmp = main->config->keys;

    sfRenderWindow_drawSprite(main->wind.window, new, NULL);
    btn_action(main->params->key_menu->back, main);
    btn_action(main->params->key_menu->config_up, main);
    btn_action(main->params->key_menu->config_left, main);
    btn_action(main->params->key_menu->config_right, main);
    btn_action(main->params->key_menu->config_down, main);
    btn_action(main->params->key_menu->config5, main);
    btn_action(main->params->key_menu->config6, main);
    btn_action(main->params->key_menu->config7, main);
    btn_action(main->params->key_menu->config8, main);
    btn_action(main->params->key_menu->selection1, main);
    btn_action(main->params->key_menu->selection2, main);
    btn_action(main->params->key_menu->selection3, main);
    for (int i = 0; i < 8; i += 1)
        sfRenderWindow_drawText(main->wind.window, tmp[i]->text, NULL);
    do_config_key2(main);
}

void create_key_config2(key_config_menu_t *new)
{
    sfVector3f select = {850, 70, 0.8};
    sfVector3f select2 = {1200, 70, 0.8};
    sfVector3f select3 = {1550, 70, 0.8};

    new->selection1 = new_button("   KeyBoard\0", select, 0, 33);
    new->selection2 = new_button("Controller\0", select2, 0, 34);
    new->selection3 = new_button("  Dance pad\0", select3, 0, 35);
}

void create_key_config1(key_config_menu_t *new)
{
    sfVector3f config_up = {300, 450, 1};
    sfVector3f config_left = {100, 650, 1};
    sfVector3f config_right = {500, 650, 1};
    sfVector3f config_down = {300, 850, 1};
    sfVector3f config5 = {1100, 320, 1};
    sfVector3f config6 = {1100, 520, 1};
    sfVector3f config7 = {1100, 720, 1};
    sfVector3f config8 = {1100, 920, 1};

    new->config_up = new_button("\t   Up\0", config_up, 0, 25);
    new->config_left = new_button("\t Left\0", config_left, 0, 28);
    new->config_right = new_button("\tRight\0", config_right, 0, 26);
    new->config_down = new_button("\tDown\0", config_down, 0, 27);
    new->config5 = new_button("??????\0", config5, 0, 29);
    new->config6 = new_button("??????\0", config6, 0, 30);
    new->config7 = new_button("??????\0", config7, 0, 31);
    new->config8 = new_button("??????\0", config8, 0, 32);
    create_key_config2(new);
}

key_config_menu_t *create_key_config(void)
{
    key_config_menu_t *new = malloc(sizeof(*new));
    sfVector2f pos = {0, 0};
    sfVector2f scale = {0.8, 0.8};
    sfVector3f back = {50, 50, 1};

    new->back = new_button("\t Back\0", back, 3, 22);
    create_key_config1(new);
    new->Sprit_back = sfSprite_create();
    new->Texture_back = sfTexture_createFromFile(BCK_PARMAS, NULL);
    sfSprite_setTexture(new->Sprit_back, new->Texture_back, sfFalse);
    sfSprite_setPosition(new->Sprit_back, pos);
    new->preselect = btn_text("Choose a preset :\0", 400, 70, scale);
    new->moove = btn_text("Moovements :\0", 70, 350, scale);
    new->diy = btn_text("Or do your personal configuration:\0",
    70, 250, scale);
    new->pause = btn_text(": Pause key\0", 1450, 330, scale);
    new->inventory = btn_text(": Inventory key\0", 1450, 530, scale);
    new->tree = btn_text(": Skill tree key\0", 1450, 730, scale);
    new->quest = btn_text(": Quests key\0", 1450, 930, scale);
    return new;
}
