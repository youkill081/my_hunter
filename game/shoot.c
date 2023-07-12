/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** for the shoot
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "game.h"
#include "main.h"
#include "bullet.h"
#include "event.h"
#include "duck.h"

void duck_shoot_handler(duck_list *list, cursor *curseur, game *game);
void check_shoot(bullet_list *bul, event_list *ev, data *d, game *game)
{
    duck_list *duck = d->ducks;
    cursor *c = d->cursor_data;
    if (ev->right_click) {
        if (remain_bullet(bul))
            duck_shoot_handler(duck, c, game);
        remove_bullet(bul);
    }
}
