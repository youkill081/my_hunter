/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** to draw ducks
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#include "my.h"
#include "duck.h"

void draw_duck(duck_list *list, sfRenderWindow *window)
{
    int i = 0;
    if (list -> duck_list == NULL) {
        return;
    }
    update_duck(list);
    while (list -> duck_list[i] != 0) {
        if (list -> duck_list[i] -> show) {
            sfRenderWindow_drawSprite(window, list->duck_list[i]->sprite, NULL);
        }
        i++;
    }
}

void move_up_rect(duck *d)
{
    if (d -> rect.top == 0)
        d -> rect.top = 140;
    else
        d -> rect.top = 0;
}

void anim_duck(duck *d)
{
    float div = 1000000.0;
    float time = sfClock_getElapsedTime(d->clock).microseconds / div;
    if (time < 0.09)
        return;
    sfClock_restart(d->clock);
    d -> rect.left += 140;
    if (d -> rect.left >= 840) {
        d -> rect.left = 0;
        move_up_rect(d);
    }
    sfSprite_setTextureRect(d -> sprite, d -> rect);
}

int can_move(duck *d)
{
    float div = 1000000.0;
    float time = sfClock_getElapsedTime(d->clock_move).microseconds / div;
    if (time < 0.019)
        return 0;
    sfClock_restart(d->clock_move);
    return 1;
}

void update_duck(duck_list *list)
{
    int i = 0;
    sfVector2f pos;
    while (list -> duck_list[i] != 0) {
        if (list -> duck_list[i] -> show && can_move(list -> duck_list[i])) {
            pos = sfSprite_getPosition(list -> duck_list[i] -> sprite);
            pos.x += list -> duck_list[i] -> speed;
            sfSprite_setPosition(list -> duck_list[i] -> sprite, pos);
            anim_duck(list -> duck_list[i]);
        }
        i++;
    }
}
