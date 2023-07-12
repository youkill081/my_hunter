/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** to create spritesheet simply
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "spritesheet.h"

/*
 * text = texture
 * sfVector2i square: x -> width
 *                    y -> height
 * sfVecor2i data1: x -> max padding for square
 *                  y -> min time for animation
 * sfVector2f pos -> position x - y
 */

spritesheet *create_spritesheet(char *text, sfVector2i square, sfVector2i data1,
    sfVector2f pos)
{
    spritesheet *sprite = malloc(sizeof(spritesheet));
    sfIntRect rect = {0, 0, square.x, square.y};
    sprite -> image = sfImage_createFromFile(text);
    if (sprite -> image == NULL)
        return NULL;
    sprite -> texture = sfTexture_createFromImage(sprite -> image, NULL);
    sprite -> sprite = sfSprite_create();
    sfSprite_setTexture(sprite -> sprite, sprite -> texture, sfTrue);
    sfSprite_setTextureRect(sprite -> sprite, rect);
    sfSprite_setPosition(sprite -> sprite, pos);
    sprite -> pos = pos;
    sprite -> rect = rect;
    sprite -> max_x = data1.x;
    sprite -> min_time = data1. y;
    sprite -> first_width = square. x;
    sprite -> clock = sfClock_create();
}

void update_spritesheet(spritesheet *sprite)
{
    float div = 1000000.0;
    float time = sfClock_getElapsedTime(sprite->clock).microseconds / div;
    if (time < sprite -> min_time)
        return;
    sfClock_restart(sprite->clock);
    sprite -> rect.left += sprite -> first_width;
    if (sprite -> rect.left > sprite -> max_x)
        sprite -> rect.left = 0;
    sfSprite_setTextureRect(sprite -> sprite, sprite -> rect);
}

void show_spritesheet(sfRenderWindow *window, spritesheet *sprite)
{
    update_spritesheet(sprite);
    sfRenderWindow_drawSprite(window, sprite -> sprite, NULL);
}
