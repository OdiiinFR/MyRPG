/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Contains the functions prototypes for the collisions.
*/

#ifndef COLLISIONS_HEADER_H_
    #define COLLISIONS_HEADER_H_

    #include "player_structs.h"
    #include "collisions_structs.h"
    #include "main.h"
    #include <SFML/Graphics/View.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Sprite.h>

//INITIALIZATION ROUTINES
sfView *init_view(sfRenderWindow *window);
player_t *init_player(col_t *col, main_t *main);
col_t *init_col(void);
void init_keys(player_t **player, main_t *main);
void move_vertices_corr(col_t *col, sfFloatRect rect, unsigned int nb);

//GAME
int do_game_loop(player_t *player, col_t *col, \
sfView *view, sfRenderWindow *window);
void view_follow(sfView *view, player_t *player, sfRenderWindow *window);

//COLLISIONS HANDLING
sfBool intersects_vertex(sfVertexArray **array, \
int **type, player_t *player, int *key);
int check_horizontal(sfVertex **vertex, int type, player_t *player, int *key);
int check_vertical(sfVertex **vertex, int type, player_t *player, int *key);
int check_diagonal(sfVertex **vertex, int type, player_t *player, int *key);
void move_back(player_t * player, int type, int *key);
void move_character(player_t *player, col_t *col, \
sfEvent *event, main_t *main);
void choose_xy(sfVertex **vertex, int type, void *x, void *y);
void recalculate_vectors(player_t *player);
sfVertexArray **init_vertex_array(void **parsed, col_t *col, int zone);
void change_center(sfView *view, main_t *main, player_t *player);
int init_positions(void **parsed, col_t *col, int zone);
int update_zone(col_t *col, player_t *player, main_t *main);
void init_interactions(col_t *col);
void init_transitions(col_t *col);
void init_zone(col_t *col);

#endif /* !COLLISIONS_HEADER_H_ */
