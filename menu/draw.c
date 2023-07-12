/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** file to draw the menu
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>

#include "my.h"
#include "main.h"
#include "colision.h"
#include "menu.h"

void hover_play(menu *data);
void not_hover_play(menu *data);
int colision(cursor *curseur, menu *data);
int draw_menu(sfRenderWindow *fen, data *d, event_list *e)
{
    sfRenderWindow_clear(fen, sfBlack);
    sfRenderWindow_drawSprite(fen, d -> menu_data -> sprite_background, NULL);
    if (play_button(fen, d -> menu_data, d -> cursor_data, e)) {
        e -> right_click = 0;
        return 1;
    }
    if (credit_button(fen, d -> menu_data, d -> cursor_data, e))
        my_putstr("et la sur crédit :))))))))))))))");
    draw_cursor(fen, d->cursor_data, d->fen_datas);
    return 0;
}
