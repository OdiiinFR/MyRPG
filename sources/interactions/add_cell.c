/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Adds a cell to the tmp list.
*/

#include "collisions_structs.h"
#include "collisions_header.h"

static tmp_t *init_cell(void)
{
    tmp_t *cell;

    if (!(cell = malloc(sizeof(tmp_t))))
        return (NULL);
    cell->next = NULL;
    cell->bef = NULL;
    cell->text = NULL;
    return (cell);
}

tmp_t *add_cell(tmp_t *cell)
{
    if (cell == NULL)
        return (init_cell());
    if (cell->next == NULL)
        cell->next = init_cell();
    cell->next->bef = cell;
    return (cell->next);
}
