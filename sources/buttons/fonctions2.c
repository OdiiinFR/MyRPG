/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** fonctions2
*/

#include "main.h"

void find_delete(button_t *new, int type)
{
    if (type == 23) {
        new->Texture_idle = sfTexture_createFromFile(BTN2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(BTN2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(BTN2_THR, NULL);
        new->function = type;
        new->height = 140;
        new->lenght = 310;
    }
    if (type == 24) {
        new->Texture_idle = sfTexture_createFromFile(BTN2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(BTN2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(BTN2_THR, NULL);
        new->function = type;
        new->height = 140;
        new->lenght = 310;
    }
}

void delation(main_t *main)
{
    int fd;
    char new[1] = " ";

    if (main->creating == 1) {
        fd = open("saves/Save1", O_RDWR);
        sfText_setString(main->play->save1->texte, "Save1\0");
        write(fd, new, 1);
    } else if (main->creating == 2) {
        fd = open("saves/Save2", O_RDWR);
        sfText_setString(main->play->save2->texte, "Save2\0");
        write(fd, new, 1);
    } else {
        fd = open("saves/Save3", O_RDWR);
        sfText_setString(main->play->save3->texte, "Save3\0");
        write(fd, new, 1);
    }
    main->play->save1->in_fonction = 0;
    main->play->save2->in_fonction = 0;
    main->play->save3->in_fonction = 0;
    close(fd);
}

void check_new(button_t *btn, main_t *main, int new)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1 && btn->in_fonction == 0) {
        if (w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx) {
            main->event = 0;
            main->wind.menu = new;
            (new == -2) ? main->play->save1->in_fonction = 2 : 0;
            (new == -2) ? main->play->save2->in_fonction = 2 : 0;
            (new == -2) ? main->play->save3->in_fonction = 2 : 0;
            find_btn(btn, main);
        }
    }
    return;
}

int find_save(char *text)
{
    if (strcompare(text, "Save1\0") == 0)
        return 0;
    if (strcompare(text, "Save2\0") == 0)
        return 0;
    if (strcompare(text, "Save3\0") == 0)
        return 0;
    return 1;
}

void check_saves(button_t *btn, main_t *main)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));
    int tmp[4] = {xmn, xmx, ymn, ymx};

    if (main->event == 1 && btn->in_fonction == 1) {
        if (w.x > xmn && w.x < xmx && w.y > ymn && w.y < ymx) {
            main->event = 0;
            main->wind.menu = btn->menu_dir;
            main->in_save = find_new(btn);
            open_and_apply(main);
        }
    } else if (main->event == 1 && btn->in_fonction == 2) {
        chek_a_save(main, btn, w, tmp);
    }
}
