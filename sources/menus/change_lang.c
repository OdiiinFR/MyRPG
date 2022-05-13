/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** change_lang
*/

#include "main.h"

void change_french2(main_t *main)
{
    sfText_setString(main->play->discard->texte, " Annuler\0");
    sfText_setString(main->play->del->texte, " Detruire\0");
    sfText_setString(main->play->validation->texte, " Valider !\0");
    sfText_setString(main->params->key_menu->preselect, "Config auto :\0");
    sfText_setString(main->params->key_menu->selection1->texte,
        "   clavier\0");
    sfText_setString(main->params->key_menu->selection2->texte, "  manette\0");
    sfText_setString(main->params->key_menu->selection3->texte, "    tapis\0");
    sfText_setString(main->params->key_menu->diy,
        "creez une configuration perso :\0");
    sfText_setString(main->params->key_menu->moove, "Deplacements\0");
    sfText_setString(main->params->key_menu->pause, ": pause\0");
    sfText_setString(main->params->key_menu->inventory, ": inventaire\0");
    change_french3(main);
}

void change_french(main_t *main)
{
    sfText_setString(main->params->back->texte, "  retour\0");
    sfText_setString(main->params->reso->texte, "  fenetre\0");
    sfText_setString(main->params->set_btn->texte, " boutons\0");
    sfText_setString(main->params->reso_menu->back->texte, "  retour\0");
    sfText_setString(main->params->reso_menu->title,
        "Choisissez votre resolution :\0");
    sfText_setString(main->params->key_menu->back->texte, "  retour\0");
    sfText_setString(main->htp->back->texte, "  retour\0");
    sfText_setString(main->params->language, "Selectionnez votre langue\0");
    sfText_setString(main->params->framerate,
        "Selectionnez votre fps\0");
    sfText_setString(main->params->sound, "Parametres des sons :\0");
    sfText_setString(main->params->slider1, "Volume des musiques :\0");
    sfText_setString(main->params->slider2, "Volume des effets sonores :\0");
    sfText_setString(main->start->play->texte, "\t\t   Jouer\0");
    sfText_setString(main->start->settings->texte, "      Parametres\0");
    sfText_setString(main->start->score->texte, "\t\t   Scores\0");
    sfText_setString(main->start->quit->texte, "\t\t  Quitter\0");
    sfText_setString(main->play->back->texte, "  retour\0");
    return change_french2(main);
}

void change_english2(main_t *main)
{
    sfText_setString(main->play->discard->texte, "  Cancel\0");
    sfText_setString(main->play->del->texte, "   Delete\0");
    sfText_setString(main->play->validation->texte, " Create !\0");
    sfText_setString(main->params->key_menu->preselect, "Choose a preset :\0");
    sfText_setString(main->params->key_menu->selection1->texte, " Keyboard\0");
    sfText_setString(main->params->key_menu->selection2->texte,
        "Controller\0");
    sfText_setString(main->params->key_menu->selection3->texte,
        " Dance pad\0");
    sfText_setString(main->params->key_menu->diy,
        "or do your personal configuration:\0");
    sfText_setString(main->params->key_menu->moove, "Moovements\0");
    sfText_setString(main->params->key_menu->pause, ": Pause key\0");
    sfText_setString(main->params->key_menu->inventory, ": inventory key\0");
    change_english3(main);
}

void change_english(main_t *main)
{
    sfText_setString(main->params->back->texte, "\tback\0");
    sfText_setString(main->params->reso->texte, "  window\0");
    sfText_setString(main->params->set_btn->texte, " buttons\0");
    sfText_setString(main->params->reso_menu->back->texte, "\tback\0");
    sfText_setString(main->params->reso_menu->title,
        "Choose your resolution :\0");
    sfText_setString(main->params->key_menu->back->texte, "\tback\0");
    sfText_setString(main->htp->back->texte, "\tback\0");
    sfText_setString(main->params->language, "Select your language\0");
    sfText_setString(main->params->framerate,
        "Select your framerate\0");
    sfText_setString(main->params->sound, "Set up your sounds :\0");
    sfText_setString(main->params->slider1, "Volume of musics :\0");
    sfText_setString(main->params->slider2, "Volume of sound effects :\0");
    sfText_setString(main->start->play->texte, "\t\t\t Play\0");
    sfText_setString(main->start->settings->texte, "\t\t Settings\0");
    sfText_setString(main->start->score->texte, "\t\t   Scores\0");
    sfText_setString(main->start->quit->texte, "\t\t\t Quit\0");
    sfText_setString(main->play->back->texte, "\tback\0");
    return change_english2(main);
}
