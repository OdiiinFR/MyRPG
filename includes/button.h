/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** button
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #define FONT "images/BaksoSapi.otf"

    #define BTN_ONE "images/buttons2.png"
    #define BTN_TWO "images/buttons1.png"
    #define BTN_THR "images/buttons3.png"

    #define BTN2_ONE "images/pink1.png"
    #define BTN2_TWO "images/pink2.png"
    #define BTN2_THR "images/pink3.png"

    #define RND_ONE "images/litle1.png"
    #define RND_TWO "images/litle2.png"
    #define RND_THR "images/litle3.png"

    #define RND2_ONE "images/litle1_2.png"
    #define RND2_TWO "images/litle2_2.png"
    #define RND2_THR "images/litle3_2.png"

    #include "csfml.h"

typedef struct my_key {
    sfText *text;
    char *name;
    sfKeyCode key;
} my_key_t;

typedef struct keys {
    struct my_key **keys;
} keys_t;

typedef struct button {
    int function;
    int in_fonction;
    int menu_dir;
    int lenght;
    int height;
    sfText *texte;
    sfVector2f position;
    sfVector2f scale;
    sfTexture *Texture_idle;
    sfTexture *Texture_on_mouse;
    sfTexture *Texture_clicked;
    sfSprite *Sprite;
} button_t;

button_t *new_button(char *text, sfVector3f pos, int dir, int type);
void find_function(button_t *new, int type, char *text);
void create_frame(button_t *new, int type);
void create_reso(button_t *new, int type, char *name);
void text_up_pos(button_t *btn, int flag);
void create_reso2(button_t *new, int type, char *name);
void create_frameplus(button_t *new, int type);
void do_delete(button_t *btn, int type);
int find_save(char *text);
sfText *btn_text(char *str, float x, float y, sfVector2f mod);
char test_1(sfKeyCode key);
void set_scale(button_t *btn);
void find_delete(button_t *new, int type);
void apply_scale(button_t *btn, float y, sfVector2f pos, sfVector2f scale);
keys_t *set_up_keys(void);
void key_to_txt(my_key_t *key);
void do_bind4(button_t *new, int type);
int find_new(button_t *btn);

#endif /* !BUTTON_H_ */
