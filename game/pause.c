/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** to manadge pause menu
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "game.h"
#include "event.h"

void switch_pause(game *game_data, sfRenderWindow *window)
{
    if (game_data -> in_pause) {
        game_data -> in_pause = 0;
        sfMouse_setPosition(game_data -> pos_before_pause, window);
    } else {
        game_data -> in_pause = 1;
        game_data -> pos_before_pause = sfMouse_getPosition(window);
    }
}

int pause_game(game *game_data, event_list *ev, sfRenderWindow *window)
{
    if (ev -> key_click && ev -> key_clicked == 36) {
        switch_pause(game_data, window);
    }
    return game_data -> in_pause;
}
