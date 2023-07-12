/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** for the text gestion
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "game.h"
#include "src.h"

void update_color(game *game_data)
{
    sfColor color = sfText_getColor(game_data->text_restart);
    if (game_data -> text_status) {
        color.a += 5;
    } else {
        color.a -= 5;
    }
    if (color.a < 0) {
        game_data -> text_status = 1;
        color.a = 1;
    }
    if (color.a > 255) {
        game_data -> text_status = 0;
        color.a = 255;
    }
    sfText_setColor(game_data -> text_restart, color);
}

void draw_reload(game *game_data, sfRenderWindow *window)
{
    update_color(game_data);
    if (!remain_bullet(game_data->bul_list))
        sfRenderWindow_drawText(window, game_data->text_restart, NULL);
}

void init_text_restart(game *game_data)
{
    sfColor text_color = {255, 0, 0, 255};
    sfFont *text_font = sfFont_createFromFile(FONT_RESTART);
    game_data -> font_score = sfFont_createFromFile(FONT_SCORE);
    game_data -> text_restart = sfText_create();
    game_data -> text_score = sfText_create();
    sfText_setString(game_data->text_restart, "Press 'R' to reload");
    sfText_setString(game_data->text_score, "78456");
    sfText_setColor(game_data->text_restart, text_color);
    sfText_setColor(game_data->text_score, text_color);
    sfText_setFont(game_data->text_restart, text_font);
    sfText_setFont(game_data->text_score, game_data->font_score);
    sfText_setPosition(game_data->text_restart, (sfVector2f) {42, 40});
    sfText_setPosition(game_data->text_score, (sfVector2f) {750, 825});
    sfText_setScale(game_data->text_restart, (sfVector2f) {2, 2});
    sfText_setScale(game_data->text_score, (sfVector2f) {4, 4});
    game_data -> clock_text_restart = sfClock_create();
}
