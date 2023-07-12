/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** for player shoot duck
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "duck.h"
#include "colision.h"
#include "game.h"

int reset_on_limit(duck_list *list)
{
    int nbr = 0;
    int i = 0;
    sfVector2f temp;
    if (list -> duck_list == NULL)
        return 0;
    while (list -> duck_list[i] != 0) {
        if (list -> duck_list[i] -> show &&
            sfSprite_getPosition(list -> duck_list[i] -> sprite).x > 874) {
            list -> duck_list[i] -> show = 0;
            nbr++;
        }
        i++;
    }
    return nbr;
}

int colision_duck(cursor *curseur, duck *duck, sfImage *image)
{
    sfVector2f cursor_pos = get_cursor_position(curseur);
    if (point_touch_sprite(cursor_pos, duck->sprite, image))
        return 1;
    return 0;
}

void shoot_action(duck_list *list, cursor *curseur, int i, game *game)
{
    sfImage *temp_image = NULL;
    duck *temp = list -> duck_list[i];
    sfTexture *temp_tex;
    if (list -> duck_list[i] -> type == 1 || list -> duck_list[i] -> type == 2)
        temp_image = list -> image_basic;
    if (temp_image == NULL)
        return;
    if (colision_duck(curseur, list -> duck_list[i], temp_image)) {
        if (list -> duck_list[i] -> type == 1) {
            list -> duck_list[i] -> show = 0;
            game -> score += 10;
            return;
        }
        game -> score += 20;
        temp_tex = list->textures_basic[temp->nbr_skin];
        sfSprite_setTexture(temp->sprite, temp_tex, 1);
        sfSprite_setTextureRect(temp->sprite, temp->rect);
        list -> duck_list[i] -> type = 1;
    }
}

void duck_shoot_handler(duck_list *list, cursor *curseur, game *game)
{
    sfImage *temp_image = NULL;
    if (list -> duck_list == NULL)
        return;
    for (int i = 0; list -> duck_list[i] != 0; i++) {
        if (list -> duck_list[i] -> show) {
            shoot_action(list, curseur, i, game);
        }
    }
}
