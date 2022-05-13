/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Initializes the view.
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>

sfView *init_view(sfRenderWindow *window)
{
    sfView *view;
    sfVector2u size = sfRenderWindow_getSize(window);
    sfFloatRect rect = {0, 0, size.x, size.y};

    view = sfView_createFromRect(rect);
    return (view);
}
