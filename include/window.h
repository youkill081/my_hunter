/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** header for the window manadgement
*/

#ifndef WINDOW_H_
    #define WINDOW_H_
struct fen_data {
    int last_width;
    int last_heigth;
    int was_resize;
};
sfRenderWindow *create_window(void);
void close_window(sfRenderWindow *window);
struct fen_data *init_fen(void);
void cacul_fen_size(sfRenderWindow *window, struct fen_data *data);
float window_scale_ratio(sfRenderWindow *window);
#endif
