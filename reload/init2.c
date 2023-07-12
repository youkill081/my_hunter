/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** other function for initialisation of reload
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "game.h"
#include "src.h"

void fill_text(game *game_data)
{
    sfFont *text_font = sfFont_createFromFile(FONT_RESTART);
    sfText_setFont(game_data->rel->type, text_font);
    sfText_setFont(game_data->rel->text_fin, text_font);
    sfText_setFont(game_data->rel->text_deb, text_font);
    sfText_setPosition(game_data->rel->type, (sfVector2f) {150, 250});
    sfText_setPosition(game_data->rel->text_fin, (sfVector2f) {150, 350});
    sfText_setPosition(game_data->rel->text_deb, (sfVector2f) {150, 350});
    sfText_setScale(game_data->rel->text_fin, (sfVector2f) {3, 3});
    sfText_setScale(game_data->rel->type, (sfVector2f) {3, 3});
    sfText_setScale(game_data->rel->text_deb, (sfVector2f) {3, 3});
    sfText_setColor(game_data -> rel -> text_deb, (sfColor) {0, 204, 0, 255});
    sfText_setColor(game_data -> rel -> text_fin, (sfColor) {255, 51, 0, 255});
    sfText_setColor(game_data -> rel -> type, (sfColor) {255, 51, 0, 255});
    sfText_setString(game_data -> rel -> type, "Type :");
}
