/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** for the bullet list
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "bullet.h"

bullet *create_bullet(int x, int y);
bullet_list *init_bullet_list(void)
{
    bullet_list *bul_list = malloc(sizeof(bullet_list));
    int x = 150;
    int equart = 130;
    bul_list -> bul1 = create_bullet(equart * 0 + x, 790);
    bul_list -> bul2 = create_bullet(equart * 1 + x, 790);
    bul_list -> bul3 = create_bullet(equart * 2 + x, 790);
    return bul_list;
}

void show_bullet_list(bullet_list *list, sfRenderWindow *window)
{
    bullet_place(list -> bul1, window);
    bullet_place(list -> bul2, window);
    bullet_place(list -> bul3, window);
}

void remove_bullet(bullet_list *list)
{
    if (list->bul3->is_used) {
        list->bul3->is_used = 0;
        return;
    }
    if (list->bul2->is_used) {
        list -> bul2 -> is_used = 0;
        return;
    }
    list->bul1->is_used = 0;
}

int remain_bullet(bullet_list *list)
{
    int nbr_fin = 0;
    nbr_fin += list->bul3->is_used;
    nbr_fin += list->bul2->is_used;
    nbr_fin += list->bul1->is_used;
    return nbr_fin;
}
