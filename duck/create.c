/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** to create ducks
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "duck.h"

void create_duck_3(duck_list *list);
int number_duck(duck_list *list)
{
    int i = 0;
    if (list -> duck_list == NULL)
        return 0;
    while (list-> duck_list[i] != 0) {
        i++;
    }
    return i;
}

duck **create_copyp(duck_list *list, int nbr_duck)
{
    duck **lfin;
    int i = 0;
    if (nbr_duck == 0) {
        lfin = malloc(sizeof(duck) * 2);
        lfin[1] = 0;
        return lfin;
    }
    lfin = malloc(sizeof(duck) * (nbr_duck + 1));
    while (list -> duck_list[i] != 0) {
        lfin[i] = list -> duck_list[i];
        i++;
    }
    lfin[i + 1] = 0;
    return lfin;
}

void create_duck_2(duck_list *list)
{
    int nbr_duck = number_duck(list);
    int nbr = gen_duck();
    duck **list_fin = create_copyp(list, nbr_duck);
    duck *to_add = malloc(sizeof(duck));
    to_add -> nbr_skin = nbr;
    to_add -> speed = generate_speed(2, 1);
    to_add -> type = 2;
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

void create_duck_1(duck_list *list)
{
    int nbr_duck = number_duck(list);
    int nbr = gen_duck();
    duck **list_fin = create_copyp(list, nbr_duck);
    duck *to_add = malloc(sizeof(duck));
    to_add -> nbr_skin = nbr;
    to_add -> speed = generate_speed(1, 1);
    to_add -> type = 1;
    to_add -> show = 1;
    to_add -> clock = sfClock_create();
    to_add -> clock_move = sfClock_create();
    to_add -> sprite = sfSprite_create();
    to_add -> life = 0;
    sfSprite_setTexture(to_add->sprite, list->textures_basic[nbr], sfTrue);
    sfSprite_setTextureRect(to_add->sprite, list->rect_basic);
    sfSprite_setPosition(to_add->sprite, generate_co(75));
    to_add -> rect = list->rect_basic;
    list_fin[nbr_duck] = to_add;
    free(list -> duck_list);
    list -> duck_list = list_fin;
}

void add_duck(duck_list *list, int type)
{
    if (type == 1) {
        create_duck_1(list);
    }
    if (type == 2) {
        create_duck_2(list);
    }
    if (type == 3) {
        create_duck_3(list);
    }
}
