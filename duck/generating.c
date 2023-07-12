/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** for direrent random number generation
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"

sfVector2f generate_co(int size_px)
{
    sfVector2f vec = {0, rand() % (634 - size_px)};
    return vec;
}

int generate_speed(int type, int difficult)
{
    if (type == 1) {
        return rand() % (difficult + 1) + 2;
    }
    if (type == 2) {
        return rand() % (difficult + 1) + 1;
    }
    return 5;
}

int gen_duck(void)
{
    return rand() % 3;
}

int choose_duck(void)
{
    int r = rand() % 100;
    if (r < 20)
        return 2;
    return 1;
}
