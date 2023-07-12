/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** structure needed in the main
*/

#ifndef MAIN_H_
    #define MAIN_H_
    #include "menu.h"
    #include "game.h"
    #include "cursor.h"
    #include "window.h"
    #include "duck.h"
typedef struct all_data {
    menu *menu_data;
    game *game_data;
    cursor *cursor_data;
    duck_list *ducks;
    struct fen_data *fen_datas;
} data;
#endif
