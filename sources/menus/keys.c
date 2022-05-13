/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** keys
*/

#include "main.h"

void update_frame(button_t *btn, button_t *btn2, main_t *main)
{
    sfVector2f new1 = btn->position;
    sfVector2f new2 = btn2->position;

    new1.x += 5;
    new2.x += 5;
    new1.y += 20;
    new2.y += 20;
    sfText_setPosition(btn->texte, new1);
    sfText_setPosition(btn2->texte, new2);
    btn2->in_fonction = 0;
    btn->in_fonction = 0;
    main->event = 0;
    return;
}
