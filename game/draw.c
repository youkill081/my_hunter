/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** for the draw of the game
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "game.h"
#include "shoot.h"
#include "duck.h"
#include "reload.h"
#include "main.h"

char *my_int_to_str(int nbr);
int recalc_game(game *game_data, event_list *event, data *data);
void check_shoot(bullet_list *bul, event_list *ev, data *d, game *game);
void draw_score(game *game_d, sfRenderWindow *window)
{
    sfText_setString(game_d->text_score, my_int_to_str(game_d->score));
    sfRenderWindow_drawText(window, game_d->text_score, NULL);
}

void update_game(sfRenderWindow *w, game *game_d, event_list *e, data *d)
{
    if (e -> r_click)
        start_reload(game_d -> rel, e);
    if (!game_d -> rel -> is_reloading)
        check_shoot(game_d -> bul_list, e, d, game_d);
}

int draw_game(sfRenderWindow *window, game *game_d, event_list *e, data *d)
{
    if (pause_game(game_d, e, window))
        return 1;
    sfRenderWindow_clear(window, sfBlack);
    if (recalc_game(game_d, e, d))
        return 0;
    update_game(window, game_d, e, d);
    sfRenderWindow_drawSprite(window, game_d -> sprite_background, NULL);
    draw_tree(window, game_d);
    sfRenderWindow_drawSprite(window, game_d -> sprite_limit, NULL);
    sfRenderWindow_drawSprite(window, game_d -> sprite_square, NULL);
    show_bullet_list(game_d -> bul_list, window);
    draw_reload(game_d, window);
    make_reload(game_d, game_d-> rel, window, e);
    sfRenderWindow_drawRectangleShape(window, game_d -> back_life, NULL);
    sfRenderWindow_drawRectangleShape(window, game_d -> life, NULL);
    draw_duck(d->ducks, window);
    draw_score(game_d, window);
    draw_cursor(window, d->cursor_data, d->fen_datas);
    return 1;
}
