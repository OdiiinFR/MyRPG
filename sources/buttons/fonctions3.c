/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** founctions3
*/

#include "main.h"

void find_btn(button_t *btn, main_t *main)
{
    (btn->position.x == 450) ? main->creating = 1 : 0;
    (btn->position.x == 850) ? main->creating = 2 : 0;
    (btn->position.x == 1250) ? main->creating = 3 : 0;
    return;
}

void reset_entry(main_t *main)
{
    for (int i = 0; i < 16; i += 1) {
        (main->play->txt[i] <= 'Z' && main->play->txt[i] >= 'A') ?
            change_pos(main->play->entry_txt, 1) : 0;
        main->play->txt[i] = '\0';
    }
    main->play->ctr = -1;
    sfText_setString(main->play->entry_txt, main->play->txt);
}

void apply_scale(button_t *btn, float y, sfVector2f pos, sfVector2f scale)
{
    scale.x = y;
    scale.y = y;
    sfText_setScale(btn->texte, scale);
    sfText_setPosition(btn->texte, pos);
}
