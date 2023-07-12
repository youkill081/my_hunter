/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** contain evry cursor function and structure
*/

#ifndef CURSOR_H_
    #define CURSOR_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include "window.h"
typedef struct cursor {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    int width;
    int heigth;
} cursor;
void draw_cursor(sfRenderWindow *windows, cursor *data, struct fen_data *fend);
sfVector2f get_cursor_position(cursor *cur);
int init_cursor(cursor *data);
#endif
