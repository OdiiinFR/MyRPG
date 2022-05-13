/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** fonctions
*/

#include "main.h"

void change_pos(sfText *texte, int flag)
{
    sfVector2f pos = sfText_getPosition(texte);

    if (flag == 0) {
        pos.x -= 20;
        sfText_setPosition(texte, pos);
    }
    if (flag == 1) {
        pos.x += 20;
        sfText_setPosition(texte, pos);
    }
}

void check_entry(char *text, sfText *texte, main_t *main)
{
    if (main->last == 59 && main->event == 2) {
        if (main->play->ctr > -1 && main->play->ctr < 16) {
            text[main->play->ctr] = '\0';
            main->play->ctr -= 1;
            change_pos(texte, 1);
        }
        main->event = 0;
        sfText_setString(texte, text);
    }
    if (main->event == 2 && main->last > -1 && main->last < 26) {
        if (main->play->ctr < 15) {
            main->play->ctr += 1;
            text[main->play->ctr] = (main->last + 65);
            text[main->play->ctr + 1] = '\0';
            change_pos(texte, 0);
        }
        main->event = 0;
        sfText_setString(texte, text);
    }
}

void do_cancel(button_t *btn, main_t *main)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx) {
        main->event = 0;
        main->wind.menu = 1;
        reset_entry(main);
    }
}

void do_create2(main_t *main, int flag)
{
    int fd;
    char *tmp = my_strcat(main->play->txt, "\n");

    if (flag == 1) {
        fd = open("saves/Save1", O_RDWR);
        sfText_setString(main->play->save1->texte, main->play->txt);
        write(fd, tmp, my_strlen(tmp));
        main->play->save1->in_fonction = 1;
    } else if (flag == 2) {
        fd = open("saves/Save2", O_RDWR);
        sfText_setString(main->play->save2->texte, main->play->txt);
        write(fd, tmp, my_strlen(tmp));
        main->play->save2->in_fonction = 1;
    } else {
        fd = open("saves/Save3", O_RDWR);
        sfText_setString(main->play->save3->texte, main->play->txt);
        write(fd, tmp, my_strlen(tmp));
        main->play->save3->in_fonction = 1;
    }
    close(fd);
}

void do_create(button_t *btn, main_t *main)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx) {
        if (good_entry(main->play->txt) == 0) {
            save_save(main);
        }
    }
}
