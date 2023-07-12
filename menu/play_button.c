/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** evrything for the play button
*/


#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "colision.h"
#include "cursor.h"
#include "menu.h"

int colision_play(cursor *curseur, menu *data)
{
    sfVector2f cursor_pos = get_cursor_position(curseur);
    if (point_touch_sprite(cursor_pos, data->sprite_playbutton,
        data->playbutton_image))
        return 1;
    return 0;
}

void hover_play(menu *data)
{
    float time;
    if (data->zoomstate_play == 0)
        data->zoomstate_play = 1;
    time = sfClock_getElapsedTime(data->clock_play).microseconds / 1000000.0;
    if (time < 0.018) {
        return;
    }
    sfClock_restart(data->clock_play);
    if (data->zoomstate_play == 1) {
        sfSprite_scale(data->sprite_playbutton, (sfVector2f) {1.01, 1.01});
        if (sfSprite_getScale(data->sprite_playbutton).x >= 1.2)
            data->zoomstate_play = 2;
    }
    if (data -> zoomstate_play == 2) {
        sfSprite_scale(data->sprite_playbutton, (sfVector2f) {0.99, 0.99});
        if (sfSprite_getScale(data->sprite_playbutton).x <= 1)
            data->zoomstate_play = 1;
    }
}

void not_hover_play(menu *data)
{
    sfSprite_setScale(data->sprite_playbutton, (sfVector2f) {0.99, 0.99});
    sfClock_restart(data->clock_play);
    data -> zoomstate_play = 0;
}

int place_play_button(menu *data)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(data->sprite_playbutton);
    sfVector2f vec = {512 - (rect.width / 2), 384 - (rect.height / 2)};
    sfSprite_setPosition(data->sprite_playbutton, vec);
}

int play_button(sfRenderWindow *fen, menu *data, cursor *curseur, event_list *e)
{
    if (e -> right_click && colision_play(curseur, data)) {
        my_putstr("click play\n");
        return 1;
    }

    if (colision_play(curseur, data))
        hover_play(data);
    else
        not_hover_play(data);

    place_play_button(data);
    sfRenderWindow_drawSprite(fen, data -> sprite_playbutton, NULL);
    return 0;
}
