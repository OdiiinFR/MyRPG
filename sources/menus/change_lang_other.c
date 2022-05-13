/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Changes the language.
*/

#include "main.h"

void change_french3(main_t *main)
{
    sfText_setString(main->params->key_menu->tree,
        ": arbre\nde competences\0");
    sfText_setString(main->params->key_menu->quest, ": menu de quetes\0");
    sfText_setString(main->pause->back->texte, "  retour\0");
    sfText_setString(main->pause->params->texte, " reglages\0");
    sfText_setScale(main->pause->quit->texte, (sfVector2f){1.2, 1.2});
    sfText_setString(main->pause->quit->texte,
        "  sauvegarder\n\tet quitter\0");
    sfText_setScale(main->pause->save->texte, (sfVector2f){1.4, 1.4});
    sfText_setString(main->pause->save->texte, " sauvegarder\0");
}

void change_english3(main_t *main)
{
    sfText_setString(main->params->key_menu->tree, ": skill tree key\0");
    sfText_setString(main->params->key_menu->quest, ": quests key\0");
    sfText_setString(main->pause->back->texte, "  resume\0");
    sfText_setString(main->pause->params->texte, " settings\0");
    sfText_setScale(main->pause->quit->texte, (sfVector2f){1.5, 1.5});
    sfText_setString(main->pause->quit->texte, " save & quit\0");
    sfText_setScale(main->pause->save->texte, (sfVector2f){1.5, 1.5});
    sfText_setString(main->pause->save->texte, "\t Save\0");
}
