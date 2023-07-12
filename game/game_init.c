/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** contain the game engine
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "game.h"
#include "error.h"
#include "src.h"
#include "bullet.h"
#include "reload.h"

void init_game_sprite(game *g);
void init_reload(game *game_data);
int is_all_image_find_game(game *game_data);
void aloc(game *game_data)
{
    game_data -> clock_tree = sfClock_create();
    game_data -> tree_rect = (sfIntRect) {0, 0, 394, 770};
    game_data -> text_status = 0;
    game_data -> score = 0;
    game_data -> damage = 100;
    game_data -> in_pause = 0;
    game_data -> text_score = sfText_create();
    init_game_sprite(game_data);
    init_text_restart(game_data);
    init_reload(game_data);
}

void create_rectangle(game *game_data)
{
    sfColor color_back = {179, 179, 204, 150};
    sfColor color = {204, 51, 0, 255};
    game_data -> life = sfRectangleShape_create();
    game_data -> back_life = sfRectangleShape_create();
    sfRectangleShape_setFillColor(game_data -> life, color);
    sfRectangleShape_setFillColor(game_data -> back_life, color_back);
    sfRectangleShape_setPosition(game_data -> back_life, (sfVector2f) {40, 20});
    sfRectangleShape_setPosition(game_data -> life, (sfVector2f) {40, 20});
    sfRectangleShape_setSize(game_data -> life, (sfVector2f) {800, 20});
    sfRectangleShape_setSize(game_data -> back_life, (sfVector2f) {800, 20});
}

int init_game(game *game_data)
{
    int error_nbr;
    sfImage *img1 = sfImage_createFromFile(GAME_BACKGROUND);
    sfImage *img3 = sfImage_createFromFile(GAME_SQUARE);
    game_data -> background_image = img1;
    game_data -> tree_image = sfImage_createFromFile(GAME_TREE);
    game_data -> pause_tex = sfTexture_createFromFile(GAME_PAUSE, NULL);
    game_data -> square_image = img3;
    error_nbr = is_all_image_find_game(game_data);
    if (error_nbr != 0)
        return error_nbr;
    game_data -> background_tex = sfTexture_createFromImage(img1, NULL);
    game_data -> tree_tex = sfTexture_createFromImage(game_data->tree_image, 0);
    game_data -> square_tex = sfTexture_createFromImage(img3, NULL);
    game_data -> clock_spawn = sfClock_create();
    game_data -> bul_list = init_bullet_list();
    create_rectangle(game_data);
    aloc(game_data);
    return 0;
}

int is_all_image_find_game(game *game_data)
{
    int nbr_missing = 0;
    if (game_data -> background_image == NULL) {
        missing_file(GAME_BACKGROUND);
        nbr_missing++;
    }
    if (game_data -> tree_image == NULL) {
        missing_file(GAME_TREE);
        nbr_missing++;
    }
    if (game_data -> square_image == NULL) {
        missing_file(GAME_SQUARE);
        nbr_missing++;
    }
    if (game_data -> pause_tex == NULL) {
        missing_file(GAME_PAUSE);
        nbr_missing++;
    }
    return nbr_missing;
}

void init_game_sprite(game *g)
{
    int h = sfTexture_getSize(g -> square_tex).y;
    sfTexture *limit = sfTexture_createFromFile(GAME_LIMIT, NULL);
    g -> sprite_background = sfSprite_create();
    g -> sprite_tree = sfSprite_create();
    g -> sprite_square = sfSprite_create();
    g -> sprite_limit = sfSprite_create();
    g -> pause_sprite = sfSprite_create();
    sfSprite_setTexture(g -> sprite_background, g -> background_tex, sfTrue);
    sfSprite_setTexture(g -> sprite_tree, g -> tree_tex, sfTrue);
    sfSprite_setTexture(g -> sprite_square, g -> square_tex, sfTrue);
    sfSprite_setTexture(g -> sprite_limit, limit, sfTrue);
    sfSprite_setTexture(g -> pause_sprite, g -> pause_tex, sfTrue);
    sfSprite_setTextureRect(g -> sprite_tree, g -> tree_rect);
    sfSprite_setPosition(g -> sprite_square, (sfVector2f) {0, 1024 - h});
    sfSprite_setPosition(g -> sprite_tree, (sfVector2f) {415, 0});
    sfSprite_setPosition(g -> sprite_limit, (sfVector2f) {874, 0});
    sfSprite_setPosition(g -> pause_sprite, (sfVector2f) {293, 168});
}
