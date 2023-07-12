/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** menu manager
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "error.h"
#include "menu.h"
#include "src.h"

int init_menu(menu *menu_fin)
{
    int error_nbr;
    sfImage *img1 = sfImage_createFromFile(MENU_BACK);
    sfImage *img2 = sfImage_createFromFile(MENU_PLAY);
    sfImage *img3 = sfImage_createFromFile(MENU_CREDIT);
    menu_fin -> background_image = img1;
    menu_fin -> playbutton_image = img2;
    menu_fin -> creditbutton_image = img3;
    error_nbr = is_all_image_find(menu_fin);
    if (error_nbr != 0)
        return error_nbr;
    menu_fin -> background_img = sfTexture_createFromImage(img1, NULL);
    menu_fin -> play_button_img = sfTexture_createFromImage(img2, NULL);
    menu_fin -> credit_button_img = sfTexture_createFromImage(img3, NULL);
    menu_fin -> zoomstate_play = 0;
    menu_fin -> zoomstate_credit = 0;
    menu_fin -> clock_play = sfClock_create();
    menu_fin -> clock_credit = sfClock_create();
    init_menu_sprite(menu_fin);
    return 0;
}

void init_menu_sprite(menu *m)
{
    sfVector2f pos1 = {337, 209};
    sfVector2f pos2 = {387, 643};
    m -> sprite_background = sfSprite_create();
    m -> sprite_playbutton = sfSprite_create();
    m -> sprite_creditbutton = sfSprite_create();
    sfSprite_setTexture(m->sprite_background, m->background_img, sfTrue);
    sfSprite_setTexture(m->sprite_playbutton, m->play_button_img, sfTrue);
    sfSprite_setTexture(m->sprite_creditbutton, m->credit_button_img, sfTrue);
    sfSprite_setPosition(m->sprite_playbutton, pos1);
    sfSprite_setPosition(m->sprite_creditbutton, pos2);
}

int is_all_image_find(menu *menu_fin)
{
    int nbr_missing = 0;
    if (menu_fin -> background_image == NULL) {
        missing_file(MENU_BACK);
        nbr_missing++;
    }
    if (menu_fin -> playbutton_image == NULL) {
        missing_file(MENU_PLAY);
        nbr_missing++;
    }
    if (menu_fin -> creditbutton_image == NULL) {
        missing_file(MENU_CREDIT);
        nbr_missing++;
    }
    return nbr_missing;
}
