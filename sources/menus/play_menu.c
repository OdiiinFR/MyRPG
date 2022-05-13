/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** play_menu
*/

#include "main.h"

void set_scale(button_t *btn)
{
    sfVector2f pos = sfText_getPosition(btn->texte);
    sfVector2f scale = btn->scale;
    const char *text = sfText_getString(btn->texte);
    int nb = my_strlen(text);
    char too[15] = "too long name\0";

    if (nb <= 8)
        return;
    if (nb > 8 && nb <= 11) {
        pos.x += 10;
        apply_scale(btn, 1.5, pos, scale);
    } else if (nb > 11 && nb <= 14) {
        pos.x += 20;
        apply_scale(btn, 1.4, pos, scale);
    } else {
        pos.x += 20;
        apply_scale(btn, 1.1, pos, scale);
        sfText_setString(btn->texte, too);
    }
}

play_menu_t *create_play2(main_t *main, play_menu_t *new)
{
    sfVector3f save2 = {850, 200, 1};
    sfVector3f save3 = {1250, 200, 1};
    sfVector3f discard = {1000, 700, 1};
    sfVector3f create = {500, 700, 1};
    sfVector3f dell = {50, 350, 1};
    sfVector2f scale = {1, 1};

    new->save2 = new_button(main->saves[1]->name, save2, 2, 20);
    set_scale(new->save2);
    new->save3 = new_button(main->saves[2]->name, save3, 2, 20);
    set_scale(new->save3);
    new->del = new_button("   Delete\0", dell, 0, 21);
    new->discard = new_button("  Cancel\0", discard, 1, 23);
    new->validation = new_button(" Create !\0", create, 2, 24);
    new->create = btn_text("Please type the name of your save :\0",
        400, 200, scale);
    new->destroy = btn_text("Choose the save to destroy", 400, 100, scale);
    new->entry_txt = btn_text(NULL, 950, 500, scale);
    return new;
}

play_menu_t *create_play(main_t *main)
{
    play_menu_t *new = malloc(sizeof(play_menu_t));
    sfVector3f back = {50, 50, 1};
    sfVector3f save1 = {450, 200, 1};
    sfVector2f pos = {0, 0};

    new->Sprit_back = sfSprite_create();
    new->Texture_back = sfTexture_createFromFile(BCK_PARMAS, NULL);
    sfSprite_setTexture(new->Sprit_back, new->Texture_back, sfFalse);
    sfSprite_setPosition(new->Sprit_back, pos);
    new->back = new_button("\tBack\0", back, 0, 22);
    new->save1 = new_button(main->saves[0]->name, save1, 2, 20);
    set_scale(new->save1);
    new->txt = malloc(sizeof(char) * 16);
    for (int i = 0; i < 16; i += 1)
        new->txt[i] = '\0';
    new->ctr = -1;
    new->entry_txt = 0;
    return create_play2(main, new);
}

void do_save2(main_t *main)
{
    btn_action(main->play->back, main);
    btn_action(main->play->save1, main);
    btn_action(main->play->save2, main);
    btn_action(main->play->save3, main);
    btn_action(main->play->del, main);
}

void do_save(main_t *main)
{
    sfSprite *new = main->params->Sprit_back;

    sfRenderWindow_drawSprite(main->wind.window, new, NULL);
    if (main->wind.menu == 1) {
        do_save2(main);
    } else if (main->wind.menu == -1) {
        check_entry(main->play->txt, main->play->entry_txt, main);
        btn_action(main->play->discard, main);
        btn_action(main->play->validation, main);
        sfRenderWindow_drawText(main->wind.window, main->play->create, NULL);
        sfRenderWindow_drawText(main->wind.window,
        main->play->entry_txt, NULL);
    } else {
        btn_action(main->play->save1, main);
        btn_action(main->play->save2, main);
        btn_action(main->play->save3, main);
        btn_action(main->play->discard, main);
        sfRenderWindow_drawText(main->wind.window, main->play->destroy, NULL);
    }
    return;
}
