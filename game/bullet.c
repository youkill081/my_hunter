/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** for the bullet
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "src.h"
#include "error.h"
#include "bullet.h"

void init_sprite_bullet(bullet *bul, int x, int y);
void bullet_place(bullet *bul, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, bul -> sprite_imageback, NULL);
    if (bul -> is_used)
        sfRenderWindow_drawSprite(window, bul -> sprite_image, NULL);
}

bullet *create_bullet(int x, int y)
{
    bullet *bul = malloc(sizeof(bullet));
    sfImage *img1 = sfImage_createFromFile(BULLET_BACKGROUND);
    bul->bullet_image = sfImage_createFromFile(BULLET_TEXTURE);
    bul->bulletback_image = img1;
    if (check_image(bul) != 0)
        return NULL;
    bul->bullet_tex = sfTexture_createFromImage(bul->bullet_image, NULL);
    bul->bulletback_tex = sfTexture_createFromImage(img1, NULL);
    bul->pos = (sfVector2f) {x + 2, y + 2};
    bul->pos_back = (sfVector2f) {x, y};
    bul->is_used = 1;
    init_sprite_bullet(bul, x, y);
    return bul;
}

int check_image(bullet *bul)
{
    int nbr_error = 0;
    if (bul->bullet_image == NULL) {
        missing_file(BULLET_TEXTURE);
        nbr_error++;
    }
    if (bul->bulletback_image == NULL) {
        missing_file(BULLET_BACKGROUND);
        nbr_error++;
    }
    return nbr_error;
}

void init_sprite_bullet(bullet *bul, int x, int y)
{
    bul -> sprite_image = sfSprite_create();
    bul -> sprite_imageback = sfSprite_create();
    sfSprite_setTexture(bul -> sprite_image, bul -> bullet_tex, sfTrue);
    sfSprite_setTexture(bul->sprite_imageback, bul->bulletback_tex, sfTrue);
    sfSprite_setPosition(bul -> sprite_imageback, (sfVector2f) {x, y});
    sfSprite_setPosition(bul -> sprite_image, (sfVector2f) {x + 2, y + 2});
}
