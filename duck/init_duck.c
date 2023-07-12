/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** to manadge duck
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#include "duck.h"
#include "error.h"
#include "src.h"

void load_textures(duck_list *l)
{
    l->textures_basic[0] = sfTexture_createFromImage(l->images_basic[0], NULL);
    l->textures_basic[1] = sfTexture_createFromImage(l->images_basic[1], NULL);
    l->textures_basic[2] = sfTexture_createFromImage(l->images_basic[2], NULL);

    l->textures_armor[0] = sfTexture_createFromImage(l->images_armor[0], NULL);
    l->textures_armor[1] = sfTexture_createFromImage(l->images_armor[1], NULL);
    l->textures_armor[2] = sfTexture_createFromImage(l->images_armor[2], NULL);

    l->texture_boss = sfTexture_createFromImage(l->image_boss, NULL);
}

void load_images(duck_list *list)
{
    list -> images_basic[0] = sfImage_createFromFile(DUCK_BASIC);
    list -> images_basic[1] = sfImage_createFromFile(DUCK_BASICG);
    list -> images_basic[2] = sfImage_createFromFile(DUCK_BASICP);

    list -> images_armor[0] = sfImage_createFromFile(DUCK_ARMOR);
    list -> images_armor[1] = sfImage_createFromFile(DUCK_ARMORG);
    list -> images_armor[2] = sfImage_createFromFile(DUCK_ARMORP);

    list -> image_boss = sfImage_createFromFile(DUCK_BASIC);
}

int init_duck(duck_list *list)
{
    int error;
    list -> image_basic = sfImage_createFromFile(DUCK_BASIC);
    list -> images_basic = malloc(sizeof(sfImage *) * 3);
    list -> textures_basic = malloc(sizeof(sfTexture *) * 3);
    list -> images_armor = malloc(sizeof(sfImage *) * 3);
    list -> textures_armor = malloc(sizeof(sfTexture *) * 3);
    load_images(list);
    error = check_nbr_error(list);
    if (error != 0)
        return error;
    list -> texture_basic = sfTexture_createFromImage(list->image_basic, NULL);
    list -> duck_list = NULL;
    load_textures(list);
    init_rect(list);
    return 0;
}

int check_nbr_error(duck_list *list)
{
    int nbr_error = 0;
    if (list -> image_basic == NULL) {
        missing_file(DUCK_BASIC);
        nbr_error++;
    }
    if (list -> images_basic[0] == NULL) {
        missing_file(DUCK_BASIC);
        nbr_error++;
    }
    if (list -> images_basic[1] == NULL) {
        missing_file(DUCK_BASICG);
        nbr_error++;
    }
    if (list -> images_basic[2] == NULL) {
        missing_file(DUCK_BASICP);
        nbr_error++;
    }
    return nbr_error;
}

void init_rect(duck_list *list)
{
    list -> rect_basic.top = 0;
    list -> rect_basic.left = 0;
    list -> rect_basic.width = 140;
    list -> rect_basic.height = 140;
}
