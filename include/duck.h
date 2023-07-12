/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** to manadge duck
*/

#ifndef DUCK_H_
    #define DUCK_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include "cursor.h"
typedef struct duck {
    int speed;
    int type;
    int show;
    int nbr_skin;
    int life;
    sfClock *clock;
    sfClock *clock_move;
    sfSprite *sprite;
    sfIntRect rect;
} duck;
typedef struct duck_list {
    duck **duck_list;
    sfImage *image_basic;
    sfTexture *texture_basic;
    sfTexture **textures_basic;
    sfImage **images_basic;
    sfTexture ** textures_armor;
    sfImage **images_armor;
    sfTexture *texture_boss;
    sfImage *image_boss;
    sfIntRect rect_basic;
} duck_list;
void draw_duck(duck_list *list, sfRenderWindow *window);
int generate_speed(int type, int difficult);
void add_duck(duck_list *list, int type);
int check_nbr_error(duck_list *list);
sfVector2f generate_co(int size_px);
int reset_on_limit(duck_list *list);
void update_duck(duck_list *list);
void init_sprite(duck_list *list);
void reset_duck(duck_list *list);
void init_rect(duck_list *list);
int init_duck(duck_list *list);
int choose_duck(void);
int gen_duck(void);
#endif
