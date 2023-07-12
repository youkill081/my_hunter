/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** to create duck
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "duck.h"

int number_duck(duck_list *list);
duck **create_copyp(duck_list *list, int nbr_duck);
void create_duck_3(duck_list *list)
{
    int nbr_duck = number_duck(list);
    int nbr = gen_duck();
    duck **list_fin = create_copyp(list, nbr_duck);
    duck *to_add = malloc(sizeof(duck));
    to_add -> nbr_skin = nbr;
    to_add -> speed = generate_speed(2, 1);
    to_add -> type = 3;
    to_add -> show = 1;
    to_add -> clock = sfClock_create();
    to_add -> clock_move = sfClock_create();
    to_add -> sprite = sfSprite_create();
    to_add -> life = 0;
    sfSprite_setTexture(to_add->sprite, list->textures_armor[nbr], sfTrue);
    sfSprite_setTextureRect(to_add->sprite, list->rect_basic);
    sfSprite_setPosition(to_add->sprite, generate_co(75));
    to_add -> rect = list->rect_basic;
    list_fin[nbr_duck] = to_add;
    free(list -> duck_list);
    list -> duck_list = list_fin;
}
