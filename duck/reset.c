/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** to reset ducks
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "duck.h"

void reset_duck(duck_list *list)
{
    if (list == NULL)
        return;
    for (int i = 0; list->duck_list[i] != 0; i++) {
        free(list->duck_list[i]);
    }
    free(list->duck_list);
    list -> duck_list = NULL;
}
