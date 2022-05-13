/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** skilltree
*/

#ifndef SKILLTREE_H_
    #define SKILLTREE_H_

    #define SKT "images/tree.png"

    #define SP1 "images/raw1.png"
    #define DESC1 "decreases the speed during a fight (X1)"
    #define SP2 "images/raw2.png"
    #define DESC2 "decreases the speed during a fight (X2)"
    #define SP3 "images/raw3.png"
    #define DESC3 "decreases the speed during a fight (X3)"

    #define DEF "images/shield_modified.png"
    #define DESC8 "Increases your defense points"
    #define CR2 "images/heart_blue.png"
    #define DESC5 "Increases your winnings in a fight"
    #define ATK "images/sword-modified.png"
    #define DESC7 "Increases your attack points"

    #define ITER "images/inter.png"
    #define DESC9 "SURPRISE!!!"
    #define TCK "images/ticket.png"
    #define DESC4 "Increases your life points"
    #define CBL "images/cible.png"
    #define DESC6 "Increases the probability of your critical hits in a fight"

typedef struct skills {
    struct button *skt;
    int bought;
} skills_t;

typedef struct skilltree {
    sfSprite *spr;
    sfTexture *texture;
    sfVector2f pos;
    struct skills *skt1;
    struct skills *skt2;
    struct skills *skt3;
    struct skills *skt4;
    struct skills *skt5;
    struct skills *skt6;
    struct skills *skt7;
    struct skills *skt8;
    struct skills *skt9;
    sfText *skilltree;
    sfText *desc;
    sfText *description;
    sfText *money;
} skilltree_t;

skilltree_t *create_skilltree(void);

#endif /* !SKILLTREE_H_ */
