/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** print_desc
*/

#include "main.h"
#include "sounds.h"

static void set_text(button_t *new, int type, char *path)
{
    new->Texture_idle = sfTexture_createFromFile(path, NULL);
    new->Texture_on_mouse = sfTexture_createFromFile(path, NULL);
    new->Texture_clicked = sfTexture_createFromFile(path, NULL);
    new->function = type;
    new->height = 50;
    new->lenght = 50;
    new->in_fonction = 0;
    return;
}

static void do_bind5(button_t *new, int type)
{
    if (type == 50 || type == 51) {
        new->Texture_idle = sfTexture_createFromFile(BTN2_ONE, NULL);
        new->Texture_on_mouse = sfTexture_createFromFile(BTN2_TWO, NULL);
        new->Texture_clicked = sfTexture_createFromFile(BTN2_THR, NULL);
        new->function = type;
        new->height = 140;
        new->lenght = 310;
    }
}

void do_bind4(button_t *new, int type)
{
    if (type == 41)
        set_text(new, type, SP1);
    if (type == 42)
        set_text(new, type, SP2);
    if (type == 43)
        set_text(new, type, SP3);
    if (type == 44)
        set_text(new, type, CR2);
    if (type == 45)
        set_text(new, type, TCK);
    if (type == 46)
        set_text(new, type, CBL);
    if (type == 47)
        set_text(new, type, ATK);
    if (type == 48)
        set_text(new, type, DEF);
    if (type == 49)
        set_text(new, type, ITER);
    return do_bind5(new, type);
}

void find_funct2(button_t *btn, main_t *main)
{
    if (btn->function > 35 && btn->function <= 40)
        check_desc(btn, main, 0);
    if (btn->function > 40 && btn->function < 50)
        skill_system(btn, main);
    if (btn->function == 50 && main->wind.is_in_htp == 0)
        print_save(btn, main);
    if (btn->function == 51) {
        if (main->wind.is_in_htp == 0)
            print_save(btn, main);
        menu_to_menu(btn->menu_dir, btn, main);
    }
    return;
}
