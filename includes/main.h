/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-anthony.faure
** File description:
** main
*/

#ifndef MAIN_H_
    #define MAIN_H_

    #include "my.h"
    #include "window.h"
    #include "menus.h"
    #include "save.h"
    #include "inventory.h"
    #include "skilltree.h"
    #include "quests.h"
    #include "player_structs.h"
    #include "collisions_structs.h"
    #include "particles.h"
    #include "sounds_structs.h"
    #include "animations.h"
    #include "joystick.h"

typedef struct main {
    int lang;
    int event;
    int creating;
    int money;
    int drag;
    int drag2;
    int drag3;
    int in_save;
    int zone;
    int hud;
    int train;
    sfSprite *spr_train;
    sfTexture *txt_train;
    sfFont *font;
    int flag;
    sfVector2f drop;
    sfSprite *moove;
    sfText *modifier;
    struct window wind;
    struct main_menu *start;
    struct play_menu *play;
    struct params_menu *params;
    struct pause_menu *pause;
    struct htp_menu *htp;
    struct hud_menu *huds;
    struct sounds *sounds;
    struct save **saves;
    sfKeyCode last;
    struct language *language;
    struct inventory *inv;
    struct skilltree *skt;
    sfEventType last_event;
    struct keys *config;
    struct quests *quests;
    struct circles *circles;
    struct rain *rain;
    sfView *view;
    struct player *player;
    struct transition *transition;
    struct battle *battle;
    struct joys *joy;
} main_t;

void do_main(main_t *main);
void do_htp(main_t *main, col_t *col);
void do_save(main_t *main);
void do_settings(main_t *main);
void do_resolution(main_t *main);
void do_config_key(main_t *main);
void do_game(main_t *main, col_t *col, player_t *player);
void do_reso(button_t *btn, main_t *main);
void do_cancel(button_t *btn, main_t *main);
void do_skilltree(main_t *m);
void do_inv(main_t *main, inventory_t *inv);
void do_quests(main_t *main);
void do_pause(main_t *main);
void btn_action(button_t *btn, main_t *main);
int btn_quit(button_t *btn, main_t *main);
void btn_update(button_t *btn, main_t *main);
void menu_to_menu(int new, button_t *btn, main_t *main);
void check_frame(button_t *btn, button_t *btn2, button_t *btn3, main_t *main);
void check_frame2(button_t *btn, button_t *btn2, button_t *btn3, main_t *main);
void check_frame3(button_t *btn, button_t *btn2, button_t *btn3, main_t *main);
void find_reso(button_t *btn, main_t *main);
void do_slider(button_t *btn, main_t *main);
void find_funct(button_t *btn, main_t *main);
void find_funct2(button_t *btn, main_t *main);
void do_lang(button_t *btn, main_t *main);
void update_frame(button_t *btn, button_t *btn2, main_t *main);
play_menu_t *create_play(main_t *main);
void check_saves(button_t *btn, main_t *main);
void check_new(button_t *btn, main_t *main, int new);
void check_entry(char *text, sfText *texte, main_t *main);
void reset_entry(main_t *main);
void do_create(button_t *btn, main_t *main);
void find_btn(button_t *btn, main_t *main);
void applay_delete(main_t *main);
void change_french(main_t *main);
void change_english(main_t *main);
void update_inv(main_t *main, inventory_t *inv, sfRenderWindow *wind);
void drag_drop(main_t *main, inventory_t *inv);
void apply_change(main_t *main, inventory_t *inv, int x, int y);
void apply_changev2(main_t *main, inventory_t *inv, sfVector2f pos, int y);
void find_drop3(main_t *main, inventory_t *inv, sfVector2f w);
void find_case2(sfVector2f w, main_t *main);
void drop(main_t *main, inventory_t *inv, sfVector2f w);
void find_drop(main_t *main, inventory_t *inv, sfVector2f w);
void update_skt(main_t *main, skilltree_t *skt);
void modifier(main_t *main, inventory_t *inv);
void do_binding(button_t *btn, main_t *main, my_key_t *key);
void inv_add(main_t *main, int ref, inventory_t *inv);
void set_keyboard(main_t *main, button_t *btn);
void check_desc(button_t *btn, main_t *main, int flag);
main_t fill_main(void);
void skill_system(button_t *btn, main_t *main);
int *find_pos(int flag, main_t *main, sfVector2f pos);
int check_sell(button_t *btn, main_t *main);
int check_buy(button_t *btn, main_t *main);
void update_view(sfView *view, sfRenderWindow *window);
void print_save(button_t *btn, main_t *main);
void create_a_save(main_t *main, int save);
void open_and_apply(main_t *main);
void open_and_apply5(main_t *m, FILE *fd, char *line, size_t len);
void open_and_apply6(main_t *m, FILE *fd, char *line, size_t len);
void reset_stats(main_t *main);
void do_create2(main_t *main, int flag);
void do_do(main_t *main, int fd);
void draw_big_circle(main_t *main);
void do_fog(main_t *main);
void do_rain(main_t *main);
void free_all(main_t *main);
void free_button(button_t *button);
void free_params_menu(main_t *main);
void free_menus_h(main_t *main);
void free_circles(main_t *main);
void free_rain(main_t *main);
char *zonned(main_t *main);
void find_status(main_t *main);
void print_hud1(main_t *main, sfView *view);
void print_hud2(main_t *main);
void save_save(main_t *main);
void chek_a_save(main_t *main, button_t *btn, sfVector2f w, int *tmp);
void delation(main_t *main);
void apply_hud(main_t *main);
void create_a_save6(main_t *main, char *line, int save);
void change_french3(main_t *main);
void change_english3(main_t *main);
void do_close_curtain(main_t *main);
void do_open_curtain(main_t *main);

//
sfJoystickIdentification get_joy(void);
void find_joy(joys_t *joy, main_t *main, sfEvent *event);
void set_controller(main_t *main, button_t *btn);
void set_dancepad(main_t *main, button_t *btn);
void do_animation(player_t *player, sfEvent *event, main_t *main);
sfBool button_mvt_is_pressed(main_t *main);
sfBool button_mvt_is_rea(main_t *main);
sfBool key_is_pressed(player_t *player);
void do_train(main_t *main, col_t *col);

#endif /* !MAIN_H_ */
