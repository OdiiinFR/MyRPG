/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** free_button
*/

#include "main.h"

void free_button(button_t *button)
{
    sfText_destroy(button->texte);
    sfTexture_destroy(button->Texture_idle);
    sfTexture_destroy(button->Texture_on_mouse);
    sfTexture_destroy(button->Texture_clicked);
    sfSprite_destroy(button->Sprite);
    free(button);
}
