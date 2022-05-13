/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

    #define HEART "images/heart.png"
    #define SWORD "images/sword.png"
    #define SHIELD "images/shield.png"
    #define INV "images/inventory.png"

    #define PHONE "images/phone.png"
    #define CHOCO "images/chocolate_bar.png"
    #define BIBLE "images/bible.png"
    #define CLOVER "images/clover.png"
    #define FLOWER "images/flower.png"
    #define HAIR "images/hairpin.png"
    #define HAND "images/handkerchief.png"
    #define LUCK "images/lucky_coin.png"
    #define BIRD "images/plastic_bird.png"
    #define DUCK "images/platic_duck.png"
    #define POP "images/popcorn_bag.png"

    #define MAG "images/magic.png"
    #define BUR "images/burn.png"
    #define GEL "images/gel.png"
    #define POI "images/poison.png"
    #define NEU "images/rigodrole.png"

typedef struct status {
    sfSprite *spr;
    sfTexture *texture1;
    sfTexture *texture2;
    sfTexture *texture3;
    sfTexture *texture4;
    sfTexture *neutral;
    sfVector2f pos;
    sfText *status;
} status_t;

typedef struct my_stat {
    sfSprite *spr;
    sfTexture *texture;
    sfVector2f pos;
    char *name;
    int stat;
    sfText *print;
} my_stat_t;

typedef struct object {
    sfSprite *spr;
    sfTexture *texture;
    sfVector2f pos_spr;
    sfVector2f pos_txt1;
    sfVector2f pos_txt2;
    char *name;
    char *type;
    int nb;
    int mod;
    int reference;
    sfBool equip;
    sfText *print_name;
    sfText *print_nb;
} object_t;

typedef struct inventory {
    sfSprite *spr;
    sfTexture *texture;
    sfVector2f pos;
    int status;
    struct object **list;
    struct object **equiped;
    struct my_stat *stats;
    struct object **all;
    struct status *sort;
    sfText *perso;
    sfText *inv;
    sfText *preview;
    sfText *equip;
    sfText *statistics;
} inventory_t;

inventory_t *creation(void);
inventory_t *creation2(inventory_t *new);
my_stat_t *set_up_stat(void);
object_t **set_inv(void);
void set_pos(object_t **new, int i, int j);
status_t *set_status(void);

#endif /* !INVENTORY_H_ */
