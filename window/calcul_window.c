/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** contain calcul for window
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "window.h"
#include "my.h"

void cacul_fen_size(sfRenderWindow *window, struct fen_data *data)
{
    sfVector2u vec = sfRenderWindow_getSize(window);
    if (vec.x != data -> last_width) {
        data -> last_width = vec.x;
        vec.y = vec.x;
        data -> was_resize = 1;
    }
    if (vec.y != data -> last_heigth) {
        data -> last_heigth = vec.y;
        vec.x = vec.y;
        data-> was_resize = 1;
    }
    sfRenderWindow_setSize(window, vec);
}

float window_scale_ratio(sfRenderWindow *window)
{
    return (float) sfRenderWindow_getSize(window).x / 1024;
}
