/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** calcul for cursor
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "cursor.h"

sfVector2f get_cursor_position(cursor *cur)
{
    sfVector2f fin;
    fin.x = cur->position.x + (cur->width / 2);
    fin.y = cur->position.y + (cur->heigth / 2);
    return fin;
}
