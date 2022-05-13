/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Handles interaction.
*/

#include "handle_text.h"
#include "main.h"
#include "player_structs.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <SFML/System/Clock.h>

static sfText *set_position(main_t *main)
{
    sfText *text = sfText_create();
    sfVector2f center = sfView_getCenter(main->view);
    sfVector2f size = sfView_getSize(main->view);
    sfVector2f vect = {center.x - (size.x / 2), center.y + (size.y / 2)};

    vect.y -= 100;
    vect.x += 100;
    sfText_setPosition(text, vect);
    sfText_setString(text, NULL);
    sfText_setFont(text, main->font);
    return (text);
}

static void draw_assets(main_t *main, \
col_t *col, player_t *player, tmp_t *inter)
{
    int zone = player->zone;

    sfRenderWindow_clear(main->wind.window, sfBlack);
    sfRenderWindow_drawSprite(main->wind.window, col->sp_col[zone], NULL);
    for (int i = 0; col->inter->sprites[player->zone][i] != NULL; ++i)
        sfRenderWindow_drawSprite(main->wind.window,
        col->inter->sprites[player->zone][i], NULL);
    sfRenderWindow_drawSprite(main->wind.window, player->sp_player, NULL);
    if (inter && inter->text)
        sfRenderWindow_drawText(main->wind.window, inter->text, NULL);
    if (inter && inter->bef && inter->bef->text)
        sfRenderWindow_drawText(main->wind.window, inter->bef->text, NULL);
    sfRenderWindow_display(main->wind.window);
}

static sfText *display_characters(char *text, \
main_t *main, col_t *col, tmp_t *inter)
{
    char *copy;
    char *ptr = text;
    int size = my_strlen(text) + 1;
    sfText *displayed = set_position(main);

    ++ptr;
    if (!(copy = malloc(sizeof(char) * (size + 1))))
        return (NULL);
    for (int i = 0; i < size + 1; ++i)
        copy[i] = '\0';
    for (int i = 0; ptr[0] != '\0'; ++ptr, ++i) {
        copy[i] = ptr[0];
        sfText_setString(displayed, copy);
        draw_assets(main, col, main->player, inter);
        sfRenderWindow_drawText(main->wind.window, displayed, NULL);
        sfRenderWindow_display(main->wind.window);
    }
    inter->copy = copy;
    return (displayed);
}

static void move_text(tmp_t *inter)
{
    if (!inter)
        return;
    if (inter->bef) {
        if (inter->bef->bef) {
            sfText_destroy(inter->bef->bef->text);
            free(inter->bef->bef->copy);
            free(inter->bef->bef);
            inter->bef->bef = NULL;
        }
    }
    sfText_move(inter->text, (sfVector2f){0, -50});
    inter = inter->next;
}

void do_text_loop(char **text, \
main_t *main, player_t *player, col_t *col)
{
    int i = 0;
    int end = 0;
    tmp_t *inter = NULL;

    while (end == 0 && sfRenderWindow_isOpen(main->wind.window)) {
        if (sfKeyboard_isKeyPressed(sfKeyEnter) && text[i] == NULL)
            break;
        if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            move_text(inter);
            inter = add_cell(inter);
            inter->text = display_characters(text[i], main, col, inter);
            ++i;
        }
        draw_assets(main, col, player, inter);
    }
    free_loop(inter);
}
