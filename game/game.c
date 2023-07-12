/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** for the game manadgement
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "game.h"
#include "event.h"
#include "main.h"
#include "duck.h"

void redraw_life_bar(game *game_data)
{
    int size = game_data -> damage * 800 / 100;
    sfVector2f prev_v = sfRectangleShape_getSize(game_data -> life);
    prev_v.x = size;
    sfRectangleShape_setSize(game_data -> life, prev_v);
}

void reset_game(game *game_data, data *data)
{
    game_data -> score = 0;
    game_data -> damage = 100;
    reset_duck(data -> ducks);
    redraw_life_bar(game_data);
    game_data->bul_list->bul1->is_used = 1;
    game_data->bul_list->bul2->is_used = 1;
    game_data->bul_list->bul3->is_used = 1;

}

int can_spawn(game *g)
{
    float div = 1000000.0;
    float time = sfClock_getElapsedTime(g->clock_spawn).microseconds / div;
    if (time < 0.455)
        return 0;
    sfClock_restart(g->clock_spawn);
    return 1;
}

int recalc_game(game *game_data, event_list *event, data *data)
{
    int nbr_duck_dead = reset_on_limit(data -> ducks);
    if (can_spawn(game_data)) {
        if (rand() % 1000 < 250) {
            add_duck(data -> ducks, choose_duck());
        }
    }
    for (int i = 0; i < nbr_duck_dead; i++) {
        game_data -> damage -= 10;
        redraw_life_bar(game_data);
    }
    if (game_data -> damage <= 0) {
        reset_game(game_data, data);
        return 1;
    }
    return 0;
}
