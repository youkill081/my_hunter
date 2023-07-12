/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** to manadge the animated tree
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "game.h"

void next_step(game *data)
{
    float div = 1000000.0;
    float time = sfClock_getElapsedTime(data->clock_tree).microseconds / div;
    if (time < 0.5)
        return;
    sfClock_restart(data->clock_tree);
    data -> tree_rect.left += 394;
    if (data -> tree_rect.left > 1400)
        data -> tree_rect.left = 0;
    sfSprite_setTextureRect(data -> sprite_tree, data -> tree_rect);
}

void draw_tree(sfRenderWindow *window, game *game_data)
{
    next_step(game_data);
    sfRenderWindow_drawSprite(window, game_data -> sprite_tree, NULL);
}
