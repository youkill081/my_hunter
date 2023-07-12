/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** all compenant of the menu
*/

#ifndef MENU_H_
    #define MENU_H_
    #include "cursor.h"
    #include "event.h"
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>

typedef struct menu {
    sfImage *background_image;
    sfImage *playbutton_image;
    sfImage *creditbutton_image;
    sfTexture *background_img;
    sfTexture *play_button_img;
    sfTexture *credit_button_img;
    sfTexture *logo_img;
    sfSprite *sprite_background;
    sfSprite *sprite_playbutton;
    sfSprite *sprite_creditbutton;
    sfClock *clock_play;
    sfClock *clock_credit;

    int zoomstate_play;
    int zoomstate_credit;
} menu;

int is_all_image_find(menu *menu_init);
int init_menu(menu *menu_fin);
void init_menu_sprite(menu *menu_fin);
int play_button(sfRenderWindow *fen, menu *data, cursor *curs, event_list *ev);
int credit_button(sfRenderWindow *fen, menu *data, cursor *cur, event_list *e);
#endif
