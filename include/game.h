/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** header for evry game function
*/

#ifndef GAME_H_
    #define GAME_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include "bullet.h"
    #include "event.h"
    #include "reload.h"
    #include "duck.h"
    #include "cursor.h"
typedef struct game {
    sfImage *background_image;
    sfImage *tree_image;
    sfImage *square_image;
    sfTexture *background_tex;
    sfTexture *tree_tex;
    sfTexture *square_tex;
    sfSprite *sprite_background;
    sfSprite *sprite_tree;
    sfSprite *sprite_square;
    sfSprite *sprite_limit;
    sfIntRect tree_rect;
    sfClock *clock_tree;
    bullet_list *bul_list;
    sfText *text_restart;
    int text_status;
    sfClock *clock_text_restart;
    reload *rel;
    int damage;
    sfRectangleShape *back_life;
    sfRectangleShape *life;
    sfClock *clock_spawn;
    int score;
    sfText *text_score;
    sfFont *font_score;
    sfSprite *pause_sprite;
    sfTexture *pause_tex;
    int in_pause;
    sfVector2i pos_before_pause;
} game;
typedef struct game_data_needed {
    sfRenderWindow *window;
    game *game_d;
    event_list *e;
    duck_list *d;
    cursor *c;
} gdn;
int init_game(game *game_data);
void draw_tree(sfRenderWindow *window, game *game_data);
void bullet_place(bullet *bul, sfRenderWindow *window);
void init_text_restart(game *game_data);
void draw_reload(game *game_data, sfRenderWindow *window);
void make_reload(game *g, reload *rel, sfRenderWindow *window, event_list *e);
int pause_game(game *game_data, event_list *e, sfRenderWindow *window);
#endif
