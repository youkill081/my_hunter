/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** evrything for the credit button
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "menu.h"
#include "cursor.h"
#include "colision.h"

int colision_credit(cursor *curseur, menu *data)
{
    sfVector2f cursor_pos = get_cursor_position(curseur);
    if (point_touch_sprite(cursor_pos, data->sprite_creditbutton,
        data->creditbutton_image))
        return 1;
    return 0;
}

void hover_credit(menu *data)
{
    float time;
    if (data->zoomstate_credit == 0)
        data->zoomstate_credit = 1;
    time = sfClock_getElapsedTime(data->clock_credit).microseconds / 1000000.0;
    if (time < 0.018) {
        return;
    }
    sfClock_restart(data->clock_credit);
    if (data->zoomstate_credit == 1) {
        sfSprite_scale(data->sprite_creditbutton, (sfVector2f) {1.01, 1.01});
        if (sfSprite_getScale(data->sprite_creditbutton).x >= 1.2)
            data->zoomstate_credit = 2;
    }
    if (data -> zoomstate_credit == 2) {
        sfSprite_scale(data->sprite_creditbutton, (sfVector2f) {0.99, 0.99});
        if (sfSprite_getScale(data->sprite_creditbutton).x <= 1)
            data->zoomstate_credit = 1;
    }
}

void not_hover_credit(menu *data)
{
    sfSprite_setScale(data->sprite_creditbutton, (sfVector2f) {1, 1});
    sfClock_restart(data->clock_credit);
    data -> zoomstate_credit = 0;
}

int place_credit_button(menu *data)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(data->sprite_creditbutton);
    sfVector2f vec = {512 - (rect.width / 2), 768 - (rect.height / 2)};
    sfSprite_setPosition(data->sprite_creditbutton, vec);
}

int credit_button(sfRenderWindow *fen, menu *data, cursor *curs, event_list *e)
{
    if (e -> right_click && colision_credit(curs, data)) {
        my_putstr("click credit\n");
        return 1;
    }

    if (colision_credit(curs, data))
        hover_credit(data);
    else
        not_hover_credit(data);

    place_credit_button(data);
    sfRenderWindow_drawSprite(fen, data -> sprite_creditbutton, NULL);
    return 0;
}
