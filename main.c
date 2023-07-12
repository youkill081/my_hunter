/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** main of my_hunter
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "menu.h"
#include "window.h"
#include "event.h"
#include "cursor.h"
#include "game.h"
#include "main.h"
#include "duck.h"

int draw_game(sfRenderWindow *window, game *game_d, event_list *e, data *d);
int draw_menu(sfRenderWindow *fen, data *d, event_list *e);
void reset(struct fen_data *data_fen);
int make_h(int ac, char **av);
int init_all(data *d);
int main(int ac, char **av)
{
    sfRenderWindow *window;
    data *d = malloc(sizeof(data));
    event_list *eventlist = malloc(sizeof(event_list));
    int state = 0;
    if (make_h(ac, av))
        return 0;
    window = create_window();
    if (window == NULL || init_all(d))
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        manadge_event(window, eventlist);
        cacul_fen_size(window, d->fen_datas);
        if (state == 0)
            state = draw_menu(window, d, eventlist);
        if (state == 1)
            state = draw_game(window, d->game_data, eventlist, d);
        sfRenderWindow_display(window);
        reset(d->fen_datas);
    }
    return 0;
}

int init_all(data *d)
{
    int nbr_error = 0;
    d -> menu_data = malloc(sizeof(menu));
    d -> game_data = malloc(sizeof(game));
    d -> cursor_data = malloc(sizeof(cursor));
    d -> ducks = malloc(sizeof(duck_list));
    my_putstr("init menu\n");
    nbr_error += init_menu(d->menu_data);
    my_putstr("init cursor\n");
    nbr_error += init_cursor(d->cursor_data);
    my_putstr("init game\n");
    nbr_error += init_game(d->game_data);
    my_putstr("init duck_list\n");
    nbr_error += init_duck(d->ducks);
    d -> fen_datas = init_fen();
    return nbr_error;
}

void reset(struct fen_data *data_fen)
{
    data_fen -> was_resize = 0;
}

int make_h(int ac, char **av)
{
    if (ac > 1 && my_strcmp(av[1], "-h") == 0) {
        my_putstr("USAGE\n");
        my_putstr("    ./my_hunter\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("    The my_hunter game, the goal is to kill as many ducks \
as possible\n");
        my_putstr("KEYS\n");
        my_putstr("    Escape : pause game\n");
        my_putstr("    Right click : shoot\n");
        my_putstr("    R : reload\n");
        my_putstr("    All letter key : to write the word\n");
        return 1;
    }
    return 0;
}
