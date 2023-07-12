/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** to check manage colision
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "cursor.h"

int check_alpha(unsigned int x, unsigned y, sfImage *image)
{
    if (sfImage_getPixel(image, x, y).a == 0)
        return 0;
    return 1;
}

int point_touch_sprite(sfVector2f point, sfSprite *sprite, sfImage *image)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
    sfVector2f scale = sfSprite_getScale(sprite);
    unsigned int x = 0;
    unsigned int y = 0;
    if (point.x >= rect.left && point.x <= rect.left + rect.width) {
        if (point.y >= rect.top && point.y <= rect.top + rect.height) {
            x = (rect.left - point.x) * -1 / scale.x;
            y = (rect.top - point.y) * -1 / scale.y;
            return check_alpha(x, y, image);
        }
    }
    return 0;
}
