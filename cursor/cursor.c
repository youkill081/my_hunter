/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** for the custom cursor
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>

#include "cursor.h"
#include "src.h"
#include "error.h"
#include "my.h"

int init_cursor(cursor *data)
{
    sfVector2u texture_size;
    data -> texture = sfTexture_createFromFile(CURSOR, NULL);
    if (data -> texture == NULL) {
        missing_file(CURSOR);
        return 1;
    }
    data -> sprite = sfSprite_create();
    sfSprite_setTexture(data -> sprite, data -> texture, sfTrue);
    data -> position. x = 0;
    data -> position.y = 0;

    texture_size = sfTexture_getSize(data -> texture);
    data -> width = texture_size.x;
    data -> heigth = texture_size.y;
    return 0;
}

float ratio(sfRenderWindow  *window, cursor *data)
{
    return (float) sfRenderWindow_getSize(window).x / 1024;
}

void move_cursor(sfRenderWindow *window, cursor *data, struct fen_data *fend)
{
    int c1 = 0;
    int c2 = 0;
    sfVector2i mouse_pos = sfMouse_getPosition(window);
    c1 = mouse_pos.x / window_scale_ratio(window) - (data->width / 2);
    c2 = mouse_pos.y / window_scale_ratio(window) - (data->heigth / 2);
    data -> position.x = c1;
    data -> position.y = c2;
    sfSprite_setPosition(data -> sprite, data -> position);
}

void draw_cursor(sfRenderWindow *window, cursor *data, struct fen_data *fend)
{
    move_cursor(window, data, fend);
    sfRenderWindow_drawSprite(window, data -> sprite, NULL);
}
