/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Handles stepmania events.
*/

#include "main.h"

joys_t *set_joys(void)
{
    joys_t *new = malloc(sizeof(*new));

    new->nb = -1;
    new->joy = 2000;
    new->last = -1;
    new->tapis = 2000;
    new->key_joy = -1;
    new->key_tapis = -1;
    return new;
}

static void apply_id_joy(joys_t *joy, int nb, sfJoystickIdentification tmp)
{
    joy->joy_id = tmp;
    joy->joy = nb;
}

static void apply_id_tapis(joys_t *joy, int nb, sfJoystickIdentification tmp)
{
    joy->tapis_id = tmp;
    joy->tapis = nb;
}

void find_joys(joys_t *joy)
{
    int i = 0;
    sfJoystickIdentification tmp;
    sfJoystickIdentification tmp2;

    for (i = 0; sfJoystick_isConnected(i); i += 1);
    if (i == 1) {
        tmp = sfJoystick_getIdentification(0);
        if (tmp.productId == 17)
            apply_id_tapis(joy, 0, tmp);
        if (tmp.productId == 2834)
            apply_id_joy(joy, 0, tmp);
    }
    if (i == 2) {
        tmp = sfJoystick_getIdentification(0);
        tmp2 = sfJoystick_getIdentification(1);
        if (tmp.productId == 17)
            apply_id_tapis(joy, 0, tmp);
        if (tmp.productId == 2834)
            apply_id_joy(joy, 0, tmp);
        if (tmp2.productId == 17)
            apply_id_tapis(joy, 1, tmp2);
        if (tmp2.productId == 2834)
            apply_id_joy(joy, 1, tmp2);
    }
    joy->nb = i;
}

void update_joys(joys_t *joy)
{
    int i = 0;

    for (i = 0; sfJoystick_isConnected(i); i += 1);
    if (i != joy->nb)
        return;
    return;
}

void find_joy(joys_t *joy, main_t *main, sfEvent *event)
{
    if (joy->tapis != 2000) {
        joy->last = 0;
        if (sfJoystick_isButtonPressed(joy->tapis, 0)) {
            joy->key_tapis = 81;
            event->key.code = 81;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->tapis, 1)) {
            joy->key_tapis = 82;
            event->key.code = 82;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->tapis, 2)) {
            joy->key_tapis = 83;
            event->key.code = 83;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->tapis, 3)) {
            joy->key_tapis = 84;
            event->key.code = 84;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->tapis, 4)) {
            joy->key_tapis = 85;
            event->key.code = 85;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->tapis, 5)) {
            joy->key_tapis = 86;
            event->key.code = 86;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->tapis, 6)) {
            joy->key_tapis = 87;
            event->key.code = 87;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->tapis, 7)) {
            joy->key_tapis = 88;
            event->key.code = 88;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->tapis, 8)) {
            joy->key_tapis = 89;
            event->key.code = 89;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->tapis, 9)) {
            joy->key_tapis = 90;
            event->key.code = 90;
            main->last = event->key.code;
            return;
        }
    }
    if (joy->joy != 2000) {
        joy->last = 1;
        if (sfJoystick_isButtonPressed(joy->joy, 0)) {
            joy->key_joy = 91;
            event->key.code = 91;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->joy, 1)) {
            joy->key_joy = 92;
            event->key.code = 92;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->joy, 2)) {
            joy->key_joy = 93;
            event->key.code = 93;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->joy, 3)) {
            joy->key_joy = 94;
            event->key.code = 94;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->joy, 4)) {
            joy->key_joy = 95;
            event->key.code = 95;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->joy, 5)) {
            joy->key_joy = 96;
            event->key.code = 96;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->joy, 6)) {
            joy->key_joy = 97;
            event->key.code = 97;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->joy, 7)) {
            joy->key_joy = 98;
            event->key.code = 98;
            main->last = event->key.code;
            return;
        }
        if (sfJoystick_isButtonPressed(joy->joy, 8)) {
            joy->key_joy = 99;
            event->key.code = 99;
            main->last = event->key.code;
            return;
        }
        return;
    }
}

static void set_joysss2(main_t *main)
{
    main->config->keys[0]->key = 94;
    key_to_txt(main->config->keys[0]);
    main->config->keys[1]->key = 92;
    key_to_txt(main->config->keys[1]);
    main->config->keys[2]->key = 91;
    key_to_txt(main->config->keys[2]);
    main->config->keys[3]->key = 93;
    key_to_txt(main->config->keys[3]);
    main->config->keys[4]->key = 98;
    key_to_txt(main->config->keys[4]);
    main->config->keys[5]->key = 96;
    key_to_txt(main->config->keys[5]);
    main->config->keys[6]->key = 95;
    key_to_txt(main->config->keys[6]);
    main->config->keys[7]->key = 97;
    key_to_txt(main->config->keys[7]);
    return;
}

void set_controller(main_t *main, button_t *btn)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn &&
        w.y < ymx && main->joy->joy != 2000)
        set_joysss2(main);
    return;
}

static void set_dance2(main_t *main)
{
    main->config->keys[0]->key = 83;
    key_to_txt(main->config->keys[0]);
    main->config->keys[1]->key = 84;
    key_to_txt(main->config->keys[1]);
    main->config->keys[2]->key = 82;
    key_to_txt(main->config->keys[2]);
    main->config->keys[3]->key = 81;
    key_to_txt(main->config->keys[3]);
    main->config->keys[4]->key = 87;
    key_to_txt(main->config->keys[4]);
    main->config->keys[5]->key = 88;
    key_to_txt(main->config->keys[5]);
    main->config->keys[6]->key = 86;
    key_to_txt(main->config->keys[6]);
    main->config->keys[7]->key = 85;
    key_to_txt(main->config->keys[7]);
    return;
}

void set_dancepad(main_t *main, button_t *btn)
{
    sfVector2i a = sfMouse_getPositionRenderWindow(main->wind.window);
    sfVector2f w = sfRenderWindow_mapPixelToCoords(main->wind.window, a, NULL);
    int xmn = (btn->position.x - 1);
    int xmx = (btn->position.x + ((btn->lenght + 1) * btn->scale.x));
    int ymn = (btn->position.y - 1);
    int ymx = (btn->position.y + ((btn->height + 1) * btn->scale.x));

    if (main->event == 1 && w.x > xmn && w.x < xmx && w.y > ymn &&
        w.y < ymx && main->joy->tapis != 2000)
        set_dance2(main);
    return;
}

sfBool button_mvt_is_pressed(main_t *main)
{
    for (int i = 0; i < 10; i += 1) {
        if (sfJoystick_isButtonPressed(main->joy->tapis, i))
            return sfTrue;
    }
    for (int i = 0; i < 9; i += 1) {
        if (sfJoystick_isButtonPressed(main->joy->joy, i))
            return sfTrue;
    }
    return sfFalse;
}

sfBool button_mvt_is_rea(main_t *main)
{
    for (int i = 0; i < 10; i += 1) {
        if (!sfJoystick_isButtonPressed(main->joy->tapis, i))
            return sfTrue;
    }
    for (int i = 0; i < 9; i += 1) {
        if (!sfJoystick_isButtonPressed(main->joy->joy, i))
            return sfTrue;
    }
    return sfFalse;
}

sfBool key_is_pressed(player_t *player)
{
    if (sfKeyboard_isKeyPressed(player->down))
        return sfTrue;
    if (sfKeyboard_isKeyPressed(player->left))
        return sfTrue;
    if (sfKeyboard_isKeyPressed(player->right))
        return sfTrue;
    if (sfKeyboard_isKeyPressed(player->up))
        return sfTrue;
    return sfFalse;
}