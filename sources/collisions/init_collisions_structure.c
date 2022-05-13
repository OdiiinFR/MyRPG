/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Initialises the col_t structure.
*/

#include "collisions_structs.h"
#include "collisions_header.h"
#include "json_parser.h"
#include "json_structs.h"

static int malloc_transitions(col_t *col)
{
    if (!(col->transitions = malloc(sizeof(sfFloatRect **) * (12 + 1))))
        return (84);
    if (!(col->positions = malloc(sizeof(int **) * (12 + 1))))
        return (84);
    for (int i = 0; i < 12 + 1; ++i) {
        col->transitions[i] = NULL;
        col->positions[i] = NULL;
    }
    return (0);
}

static void init_other_transitions(col_t *col)
{
    json_t *parsed;

    parsed = return_parsed_json("./res/col/transitions_tunnel.json");
    init_positions(parsed->value, col, 6);
    parsed = return_parsed_json("./res/col/transitions_house1.json");
    init_positions(parsed->value, col, 7);
    parsed = return_parsed_json("./res/col/transitions_house2.json");
    init_positions(parsed->value, col, 8);
    parsed = return_parsed_json("./res/col/transitions_gate.json");
    init_positions(parsed->value, col, 9);
    parsed = return_parsed_json("./res/col/transitions_crematorium.json");
    init_positions(parsed->value, col, 10);
    parsed = return_parsed_json("./res/col/transitions_ash.json");
    init_positions(parsed->value, col, 11);
}

void init_transitions(col_t *col)
{
    json_t *parsed;

    malloc_transitions(col);
    parsed = return_parsed_json("./res/col/transitions_debug.json");
    init_positions(parsed->value, col, 0);
    parsed = return_parsed_json("./res/col/transitions_begin.json");
    init_positions(parsed->value, col, 1);
    parsed = return_parsed_json("./res/col/transitions_train_int.json");
    init_positions(parsed->value, col, 2);
    parsed = return_parsed_json("./res/col/transitions_outside.json");
    init_positions(parsed->value, col, 3);
    parsed = return_parsed_json("./res/col/transitions_town.json");
    init_positions(parsed->value, col, 4);
    parsed = return_parsed_json("./res/col/transitions_mountain.json");
    init_positions(parsed->value, col, 5);
    init_other_transitions(col);
}

static void init_other_zones(col_t *col)
{
    json_t *parsed;

    parsed = return_parsed_json("./res/col/collisions_tunnel.json");
    col->array[6] = init_vertex_array(parsed->value, col, 6);
    parsed = return_parsed_json("./res/col/collisions_house1.json");
    col->array[7] = init_vertex_array(parsed->value, col, 7);
    parsed = return_parsed_json("./res/col/collisions_house2.json");
    col->array[8] = init_vertex_array(parsed->value, col, 8);
    parsed = return_parsed_json("./res/col/collisions_gate.json");
    col->array[9] = init_vertex_array(parsed->value, col, 9);
    parsed = return_parsed_json("./res/col/collisions_crematorium.json");
    col->array[10] = init_vertex_array(parsed->value, col, 10);
    parsed = return_parsed_json("./res/col/collisions_ash.json");
    col->array[11] = init_vertex_array(parsed->value, col, 11);
}

void init_zone(col_t *col)
{
    json_t *parsed;

    parsed = return_parsed_json("./res/col/collisions_debug.json");
    col->array[0] = init_vertex_array(parsed->value, col, 0);
    parsed = return_parsed_json("./res/col/collisions_begin.json");
    col->array[1] = init_vertex_array(parsed->value, col, 1);
    parsed = return_parsed_json("./res/col/collisions_train_int.json");
    col->array[2] = init_vertex_array(parsed->value, col, 2);
    parsed = return_parsed_json("./res/col/collisions_outside.json");
    col->array[3] = init_vertex_array(parsed->value, col, 3);
    parsed = return_parsed_json("./res/col/collisions_town.json");
    col->array[4] = init_vertex_array(parsed->value, col, 4);
    parsed = return_parsed_json("./res/col/collisions_mountain.json");
    col->array[5] = init_vertex_array(parsed->value, col, 5);
    init_other_zones(col);
}
