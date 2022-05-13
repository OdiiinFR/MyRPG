/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** pause_menu
*/

#include "main.h"

void do_pause(main_t *main)
{
    main->params->back->menu_dir = 11;
    sfRenderWindow_drawSprite(main->wind.window,
    main->pause->Sprit_back, NULL);
    sfRenderWindow_drawText(main->wind.window, main->pause->pause, NULL);
    btn_action(main->pause->back, main);
    btn_action(main->pause->quit, main);
    btn_action(main->pause->save, main);
    btn_action(main->pause->params, main);
    return;
}

pause_menu_t *create_pause(void)
{
    pause_menu_t *new = malloc(sizeof(*new));
    sfVector3f back = {50, 50, 1};
    sfVector3f settings = {830, 250, 1};
    sfVector3f save = {830, 550, 1};
    sfVector3f quit = {830, 850, 0.8};
    sfVector2f scale = {1.5, 1.5};

    new->Sprit_back = sfSprite_create();
    new->pause = btn_text("PAUSE\0", 850, 50, scale);
    new->Texture_back = sfTexture_createFromFile(BCK_PARMAS, NULL);
    sfSprite_setTexture(new->Sprit_back, new->Texture_back, sfFalse);
    new->back = new_button("  Resume\0", back, 2, 22);
    new->params = new_button(" Settings\0", settings, 3, 22);
    new->save = new_button("\t Save\0", save, 0, 50);
    new->quit = new_button(" Save & Quit\0", quit, 0, 51);
    return new;
}
