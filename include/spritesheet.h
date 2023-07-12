/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** header for spritesheet
*/

#ifndef SPRITESHEET_H_
    #define SPRITESHEET_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
typedef struct spritesheet {
    sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    int max_x;
    int min_time;
    int first_width;
    sfClock *clock;
} spritesheet;
#endif
