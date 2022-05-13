/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** quests
*/

#ifndef QUESTS_H_
    #define QUESTS_H_

    #define QST "images/quests.png"
    #define HOUSE "images/house.png"
    #define KEY "images/key.png"
    #define ZARB "images/zarb.png"
    #define NUAGE "images/nuage.jpg"
    #define FANTOM "images/Noppegh.jpg"

    #define QST1 "Don't be afraid to enter all of the homes, someone or \n"\
        "something may be waiting for you\0"
    #define QST2 "Whenever you turned back when you were lost,\
        it always got\n"\
        " you back home. It should be the same as always, shouldn't it ?\0"
    #define QST3 "Although you will get help, stay on guard !\0"
    #define QST4 "So alone, so alone I am; my children, find them, I beg of "\
        "you...\0"
    #define QST5 "The procession always begins where the sacred place is\0"

typedef struct quests {
    sfSprite *spr;
    sfTexture *texture;
    sfVector2f pos;
    sfText *quest;
    sfText *done;
    sfText *second;
    sfText *desc;
    sfText *description;
    struct button *qst1;
    struct button *qst2;
    struct button *qst3;
    struct button *qst4;
    struct button *qst5;
} quests_t;

quests_t *set_quests(void);

#endif /* !QUESTS_H_ */
