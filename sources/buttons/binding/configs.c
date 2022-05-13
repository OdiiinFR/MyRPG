/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** configs
*/

#include "main.h"

void key_to_txt2(my_key_t *key, char *str)
{
    if (key->key > -1 && key->key < 26) {
        str = malloc(sizeof(char) * 10);
        for (int i = 0; i < 8; i += 1)
            str[i] = ' ';
        str[8] = (key->key + 65);
        str[9] = '\0';
    }
    sfText_setString(key->text, str);
    return;
}

void key_to_txt(my_key_t *key)
{
    char *str;

    if (key->key == sfKeySpace)
        str = mystrdup("Space\0");
    if (key->key == sfKeyEscape)
        str = mystrdup("   Escape\0");
    if (key->key == sfKeyUp)
        str = mystrdup("\t   Up\0");
    if (key->key == sfKeyRight)
        str = mystrdup("\tRight\0");
    if (key->key == sfKeyDown)
        str = mystrdup("\tDown\0");
    if (key->key == sfKeyLeft)
        str = mystrdup("\t Left\0");
    if (key->key == 81)
        str = mystrdup("Left (DP)");
    if (key->key == 82)
        str = mystrdup("Down (DP)");
    if (key->key == 83)
        str = mystrdup("Up (DP)");
    if (key->key == 84)
        str = mystrdup("Right (DP)");
    if (key->key == 85)
        str = mystrdup("Sqaure (DP)");
    if (key->key == 86)
        str = mystrdup("Triangle (DP)");
    if (key->key == 87)
        str = mystrdup("Cross (DP)");
    if (key->key == 88)
        str = mystrdup("Circle (DP)");
    if (key->key == 89)
        str = mystrdup("Select (DP)");
    if (key->key == 90)
        str = mystrdup("Start (DP)");
    if (key->key == 91)
        str = mystrdup("  A (JOY)");
    if (key->key == 92)
        str = mystrdup("  B (JOY)");
    if (key->key == 93)
        str = mystrdup("  X (JOY)");
    if (key->key == 94)
        str = mystrdup("  Y (JOY)");
    if (key->key == 95)
        str = mystrdup(" LB (JOY)");
    if (key->key == 96)
        str = mystrdup(" RB (JOY)");
    if (key->key == 97)
        str = mystrdup("Share (JOY)");
    if (key->key == 98)
        str = mystrdup("Menu (JOY)");
    if (key->key == 99)
        str = mystrdup("XBOX (JOY)");
    return key_to_txt2(key, str);
}

void set_keyboard2(main_t *main)
{
    main->config->keys[0]->key = sfKeyZ;
    key_to_txt(main->config->keys[0]);
    main->config->keys[1]->key = sfKeyD;
    key_to_txt(main->config->keys[1]);
    main->config->keys[2]->key = sfKeyS;
    key_to_txt(main->config->keys[2]);
    main->config->keys[3]->key = sfKeyQ;
    key_to_txt(main->config->keys[3]);
    main->config->keys[4]->key = sfKeyEscape;
    key_to_txt(main->config->keys[4]);
    main->config->keys[5]->key = sfKeyI;
    key_to_txt(main->config->keys[5]);
    main->config->keys[6]->key = sfKeyT;
    key_to_txt(main->config->keys[6]);
    main->config->keys[7]->key = sfKeyL;
    key_to_txt(main->config->keys[7]);
    return;
}

void set_keyboard(main_t *main, button_t *btn)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn &&
        w.y < ymx)
        set_keyboard2(main);
    return;
}
